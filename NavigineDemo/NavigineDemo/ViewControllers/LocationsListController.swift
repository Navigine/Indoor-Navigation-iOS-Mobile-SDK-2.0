import Foundation

protocol LocationListDataSource : class {
    var mLocationsList: [NCLocationInfo] { get }
    func didUpdateSearchResults()
}

struct LoadProgress {
    var currentLocationId: Int32 = -1
    var progress: CGFloat = 0.0
}

class LocationsListController: UIViewController {
    
    @IBOutlet weak var mTableView: UITableView!
    
    var mLocationsList: [NCLocationInfo] = []
        
    let mSearchController = LocationSearchController(searchResultsController: nil)
    
    var currentProgress: LoadProgress!
    
    override func viewDidLoad() {
        super.viewDidLoad()
                
        NavigineApp.mLocationListManager?.add(self)
        NavigineApp.mLocationManager?.add(self)

        mSearchController.dataSource = self
        mSearchController.searchBar.placeholder = "Search"
        if #available(iOS 11.0, *) {
            navigationItem.searchController = mSearchController
            navigationItem.hidesSearchBarWhenScrolling = false
        } else { }
        
        currentProgress = LoadProgress(currentLocationId: -1, progress: 0.0)
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
            cell.versionView.text = String(item.version)
            
            if item.id == currentProgress.currentLocationId {
                cell.progressBar.progress = currentProgress.progress
            }
            
            cell.progressBar.isHidden = item.id == currentProgress.currentLocationId ? false : true
            
            return cell
        }
        return UITableViewCell()
    }
    
    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        return UIView()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if currentProgress.currentLocationId == mLocationsList[indexPath.row].id {
            return
        }
        NavigineApp.mLocationManager?.setLocationId(mLocationsList[indexPath.row].id)
        currentProgress.currentLocationId = mLocationsList[indexPath.row].id
        currentProgress.progress = 0.0
        self.mTableView.reloadData()
        
        NavigineApp.mLocationListManager?.updateLocationList()
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
    func onLocationLoaded(_ location: NCLocation?) {
        currentProgress.progress = 1.0
        self.mTableView.reloadData()
    }
    
    func onDownloadProgress(_ received: Int32, total: Int32) {
        let p = CGFloat(received) / CGFloat(total)
        if (abs(p - currentProgress.progress) * 100 > 1) {
            currentProgress.progress = p
            self.mTableView.reloadData()
        }
    }
    
    func onLocationFailed(_ error: Error?) { }
}
