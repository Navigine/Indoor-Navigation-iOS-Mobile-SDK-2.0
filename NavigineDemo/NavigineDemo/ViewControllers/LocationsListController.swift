import Foundation

protocol LocationListDataSource : class {
    var mLocationsList: [NCLocationInfo] { get }
    func didUpdateSearchResults()
}

struct LoadProgress {
    var currentLocationId: Int32 = -1
    var progress: CGFloat = 0.0
}

class LocationsListController: UIViewController, LocationListManagerDelegate {

    @IBOutlet weak var mTableView: UITableView!

    var mLocationsList: [NCLocationInfo] = []

    let mSearchController = LocationSearchController(searchResultsController: nil)

    var currentProgress: LoadProgress!

    var locationDataFetcher = LocationDataManager()
    var selectedItem: LocationInfoItem?
    var downloadingItem: LocationInfoItem?
    var locations = [LocationInfoItem]()
    private var completionHandler: (() -> Void)?
    var isDownloading: Bool = false

    override func viewDidLoad() {
        super.viewDidLoad()

        NavigineApp.mLocationListManager?.add(self)
        NavigineApp.mLocationManager?.add(self)

        NavigineApp.mLocationListManager?.add(locationDataFetcher)
        locationDataFetcher.delegate = self

        mSearchController.dataSource = self
        mSearchController.searchBar.placeholder = "Search"
        if #available(iOS 11.0, *) {
            navigationItem.searchController = mSearchController
            navigationItem.hidesSearchBarWhenScrolling = false
        } else { }

        self.fetchData {[weak self] in
            self?.mTableView.reloadData()
        }
        currentProgress = LoadProgress(currentLocationId: -1, progress: 0.0)
    }

    override func viewWillAppear(_ animated: Bool) {
      super.viewWillAppear(animated)

      if !self.isDownloading {
          self.fetchLocationList {
          self.mTableView.reloadData()
          if self.locations.count == 1 {
            self.mTableView.selectRow(at: IndexPath.init(row: 0, section: 0), animated: false, scrollPosition: .none)
          }
        }
      }

    }
    
    deinit {
      NavigineApp.mLocationListManager?.remove(locationDataFetcher)
    }

    func fetchData(completion: () -> Void) {
      // Get locations from storage
      locationDataFetcher.fetchLocations { (items, error) in
        self.locations = items
//        self.error = error
        // Try to get selected item from storage
        selectedItem = locations.first { item -> Bool in
          guard let status = item.status else { return false }
          switch(status) {
          case .selected:
            NavigineApp.mLocationManager?.setLocationId(item.info.id)
            postSetLocation()
            return true
          default:
            return false
          }
        }
        downloadingItem = locations.first { item -> Bool in
          guard let status = item.status else { return false }
          switch(status) {
          case .downloading:
            NavigineApp.mLocationManager?.setLocationId(item.info.id)
            postSetLocation()
            return true
          default:
            return false
          }
        }

        completion()
      }
    }

    func fetchLocationList(completion: @escaping () -> Void) {
      completionHandler = completion
      NavigineApp.mLocationListManager?.updateLocationList()
    }

    // NOTE: This important because MapViewController
    // responds to this notification and updates map
    // TODO: Remove this after refacroring MapViewController,
    private func postSetLocation() {
      let userInfo = ["locationName" : self.selectedItem?.info.name ?? ""]
      let notifcation =
        Notification(name: Notification.Name(rawValue: "setLocation"),
                     object: nil,
                     userInfo: userInfo)
      NotificationCenter.default.post(notifcation)
    }

    //MARK: LocationListManagerDelegate methods

    func locationListDidSaved(manager: LocationDataManager, locations: [LocationInfoItem]) {
      return
    }

    func locationDidRemoved(manager: LocationDataManager, removedLocation: LocationInfoItem) {
      // Update status for removed location
      removedLocation.status = .initial
      locationDataFetcher.saveLocationList()
      if removedLocation == selectedItem {
        selectedItem = nil
      }
    }

    func locationListDidLoaded(manager: LocationDataManager, locations: [LocationInfoItem], _ error: Error?) {
      self.locations = locations
      completionHandler?()
    }
}

extension LocationsListController: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if mSearchController.isFiltering {
            return mSearchController.filteredLocations.count
        }

        return self.mLocationsList.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let item: NCLocationInfo
        if mSearchController.isFiltering {
            item = mSearchController.filteredLocations[indexPath.row]
        } else {
            item = mLocationsList[indexPath.row]
        }

        if let cell = tableView.dequeueReusableCell(withIdentifier:"cell", for: indexPath) as? LocationItemCell {
            cell.nameView.text = item.name
            cell.versionView.text = "Version #\(item.version)"

            if item.id == currentProgress.currentLocationId {
                cell.progressBar.progress = currentProgress.progress
            }

            let infoItem: LocationInfoItem = locations[indexPath.row]
            cell.item = infoItem
            
            cell.progressBar.isHidden = item.id == currentProgress.currentLocationId ? false : true

            return cell
        }
        return UITableViewCell()
    }

    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        return UIView()
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        mTableView.deselectRow(at: indexPath, animated: true)
        if currentProgress.currentLocationId == mLocationsList[indexPath.row].id {
            return
        }
        NavigineApp.mLocationManager?.setLocationId(mLocationsList[indexPath.row].id)
        currentProgress.currentLocationId = mLocationsList[indexPath.row].id
        currentProgress.progress = 0.0
//        self.mTableView.reloadData()

        // Get current cell in table
        guard let currentCell =
          tableView.cellForRow(at: indexPath) as? LocationItemCell,
          let currentItem = currentCell.item else {
            return
        }

        if let selectedItem = self.selectedItem, let selectedIndex =
          locations.firstIndex(where: {$0 === selectedItem}) {
          // Cell already selected
          if selectedIndex == indexPath.row && downloadingItem == nil {
            return
          }

          //unselect selected item
          if selectedItem.status == .selected {
            selectedItem.status = .unselected
          }
        }

        if let downloadingItem = self.downloadingItem, let downloadingIndex =
          locations.firstIndex(where: {$0 === downloadingItem}) {
          if downloadingIndex == indexPath.row {
            return
          }

          downloadingItem.status = .initial
          self.downloadingItem = nil
        }

        switch(currentItem.status) {
        case .initial:
          do {
            NavigineApp.locationState = .downloading
            print("DID PRESS LOCATION: \(currentItem.info.name) ")
            isDownloading = true
            currentItem.status = .downloading
            downloadingItem = currentItem
    //        self.selectedItem = currentItem
            DispatchQueue.global().async {

              self.locationDataFetcher.saveLocationList()
            }
            NavigineApp.mLocationManager?.setLocationId(currentItem.info.id)
    //        self.postSetLocation()
          } catch let error as NSError {
            print(error.code)
          }
          break
        case .unselected:
          do {
            // Update status for new selected location
            NavigineApp.locationState = .downloading
            currentItem.status = .selected
            self.selectedItem = currentItem
            //stop downloading
            if downloadingItem != nil {
              downloadingItem = nil
              isDownloading = false
            }
            DispatchQueue.global().async {
              self.locationDataFetcher.saveLocationList()
            }
            NavigineApp.mLocationManager?.setLocationId(currentItem.info.id)
    //        self.postSetLocation()
          } catch let error as NSError {
            print(error.code)
            // TODO: Add new state for invalid location
            // currentItem.status = .failure(error.code)
          }
        default:
          return
        }
    }
}

extension LocationsListController: NCLocationListListener {
    func onLocationListLoaded(_ locationInfos: [NSNumber : NCLocationInfo]) {
        self.mLocationsList.removeAll()
        for el in locationInfos {
            self.mLocationsList.append(el.value)
        }
        self.mTableView.reloadData()
    }

    func onLocationListFailed(_ error: Error?) {

    }
}

extension LocationsListController: LocationListDataSource {
    func didUpdateSearchResults() {
        self.mTableView.reloadData()
    }
}

extension LocationsListController: NCLocationListener {

    func onLocationUploaded(_ locationId: Int32) { }

    func onLocationFailed(_ locationId: Int32, error: Error?) { }

    func onLocationLoaded(_ location: NCLocation?) {
        currentProgress.progress = 1.0
        self.mTableView.reloadData()
        
        if (downloadingItem != nil) {
          downloadingItem!.status = .selected
          selectedItem = downloadingItem
          downloadingItem = nil
          isDownloading = false
        }

        self.locationDataFetcher.saveLocationList()
    }


}
