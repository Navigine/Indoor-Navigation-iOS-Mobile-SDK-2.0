import UIKit

class LocationSearchController : UISearchController {
  // MARK: - Properties
  weak var dataSource: LocationListDataSource?
  var filteredLocations: [NCLocationInfo] = []
  var isSearchBarEmpty: Bool {
    return self.searchBar.text?.isEmpty ?? true
  }
  var isFiltering: Bool {
    return self.isActive && !isSearchBarEmpty
  }
  
  // MARK: Initializers
  override init(searchResultsController: UIViewController?) {
    super.init(searchResultsController: nil)
    setup()
  }

  required init?(coder: NSCoder) {
    super.init(coder: coder)
  }
  
  override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
    super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
  }
  
  private func setup() {
    searchResultsUpdater = self
    dimsBackgroundDuringPresentation = true
    obscuresBackgroundDuringPresentation = false
    hidesNavigationBarDuringPresentation = false

    searchBar.placeholder = "Search"
    searchBar.searchBarStyle = .minimal
    searchBar.sizeToFit()
  }
  
  private func filterContentForSearchText() {
    guard let dataSource = self.dataSource else {
      return
    }
    
    filteredLocations =
      dataSource.mLocationsList.filter { (location: NCLocationInfo) -> Bool in
        let searchText = searchBar.text!
        return location.name.lowercased().contains(searchText.lowercased())
    }
    
    dataSource.didUpdateSearchResults()
  }
  
}

// MARK: - UISearchResultsUpdating methods
extension LocationSearchController: UISearchResultsUpdating {
  func updateSearchResults(for searchController: UISearchController) {
    filterContentForSearchText()
  }
}

