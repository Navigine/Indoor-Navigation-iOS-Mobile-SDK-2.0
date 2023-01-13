//
//  LocationListManager.swift
//  Navigine
//
//  Created by Dmitry Stavitsky on 28/11/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

import UIKit

protocol LocationListManagerDelegate : class {
    func locationListDidSaved(manager: LocationDataManager, locations: [LocationInfoItem])
    func locationDidRemoved(manager: LocationDataManager, removedLocation: LocationInfoItem)
    func locationListDidLoaded(manager: LocationDataManager, locations: [LocationInfoItem], _ error: Error?)
}

class LocationDataManager: NSObject {
    //MARK: - Properties
    
    static let locationList = "com.navigine.app.location_list"
    
    var locations = [LocationInfoItem]()
    weak var delegate: LocationListManagerDelegate?
    class var userDefaults: UserDefaults {
        get {
            return UserDefaults.standard
        }
    }
    
    class var workingDirPath: String {
        get {
            return NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
        }
    }
    
    class var workingDirURL: URL {
        get {
            return URL(string: self.workingDirPath)!
        }
    }
    
    let transformLocation: ((_ item: NCLocationInfo) -> LocationInfoItem) = { item in
        let detailedItem = LocationInfoItem()
        detailedItem.info = item
        detailedItem.status = .initial
        detailedItem.isSelected = false
        return detailedItem
    }
    
    func fetchLocations(completion: ( [LocationInfoItem], _ error: NCError.LocationDataManagerFailure?) -> Void ) {
        // Try to get locations from storage
        if let locations = LocationDataManager.loadLocationListFromLocalStorage() {
            self.locations = locations
        } else if let locations = NavigineApp.mLocationListManager?.getLocationList() {
            self.locations = locations.map { self.transformLocation($1) }
        } else {
            completion(locations, .invalidData)
            return
        }
        completion(locations, nil)
    }
    
}

extension LocationDataManager: NCLocationListListener {
    func onLocationListLoaded(_ locationInfos: [NSNumber : NCLocationInfo]) {
        
        // Get new locations from server
        let serverList = locationInfos.values
        
        let newLocations = serverList.filter { serverLocation -> Bool in
            return !self.locations.contains { serverLocation == $0 }
        }
        
        // Add new locations to list
        
        self.locations += newLocations.map{self.transformLocation($0)}
        
        // Get locations that exists on disk but not exists on server
        let obsoleteLocations = self.locations.filter { localLocation -> Bool in
            return !serverList.contains{localLocation.info.id == $0.id}
        }
        
        // Remove obsolete locations from disk
        obsoleteLocations.forEach {
            self.removeLocation(identifier: Int($0.info.id))
        }
        
        // Remove obsolete locations from list
        self.locations.removeAll{obsoleteLocations.contains($0)}
        
        // Update location info
        // TODO: Need to refactoring!
        for serverLocation in serverList {
            for localLocation in self.locations {
                if localLocation.info.id == serverLocation.id {
                    if localLocation.info.version < serverLocation.version {
                        localLocation.info = serverLocation
                        if !localLocation.isSelected {
                            localLocation.status = .initial
                        }
                    }
                }
            }
        }
        self.saveLocationList()
        
        
        guard let locationListDidLoaded = delegate?.locationListDidLoaded else {
            return
        }
        locationListDidLoaded(self, self.locations, nil)
    }
    
    func onLocationListFailed(_ error: Error?) {
        print(error)
    }
    
}

//MARK: - Location archive manipulating methods
extension LocationDataManager {
    func removeLocation(identifier: Int) {
        
    }
    
    // TODO: Consider throw exception
    static func removeAllLocations() {
        let fileManager = FileManager.default
        let documentsPath = self.workingDirPath
        let documentsURL = self.workingDirURL
        let directoryList = try? fileManager.contentsOfDirectory(atPath: documentsPath)
        if let directoryList = directoryList {
            directoryList.forEach({ dir in
                let path = documentsURL.appendingPathComponent(dir)
                try? fileManager.removeItem(at: path)
            })
        }
    }
    
}

//MARK: - Location list manipulating methods
extension LocationDataManager {
    
    static private var plistURL: URL {
        let documents = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
        return documents.appendingPathComponent("\(LocationDataManager.locationList).plist")
    }
    
    func saveLocationList() {
        let encoder = PropertyListEncoder()
        encoder.outputFormat = .xml
        
        let path = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0].appendingPathComponent("\(LocationDataManager.locationList).plist")
        
        do {
            let data = try encoder.encode(locations)
            try data.write(to: path)
        } catch {
            print(error)
        }
        
        guard let locationListDidSaved = delegate?.locationListDidSaved else {
            return
        }
        locationListDidSaved(self, locations)
    }
    
    static func removeLocationList() {
        do {
            if FileManager.default.fileExists(atPath: plistURL.path) {
                try FileManager.default.removeItem(atPath: plistURL.path)
            }
        } catch {
            print(error)
        }
    }
    
    static func loadLocationListFromLocalStorage() -> Array<LocationInfoItem>? {
        if let loc = loadLocations() {
            return loc
        }
        return nil
    }
    
    func loadFileFromLocalPath(_ localFilePath: String) ->Data? {
        return try? Data(contentsOf: URL(fileURLWithPath: localFilePath))
    }
    
    func getDocumentsDirectory() -> URL {
        let paths = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        return paths[0]
    }
    
    
    static func write(locations: [LocationInfoItem]) {
        let encoder = PropertyListEncoder()
        
        if let data = try? encoder.encode(locations) {
            if FileManager.default.fileExists(atPath: plistURL.path) {
                // Update an existing plist
                try? data.write(to: plistURL)
            } else {
                // Create a new plist
                FileManager.default.createFile(atPath: plistURL.path, contents: data, attributes: nil)
            }
        }
    }
    
    static func loadLocations() ->  [LocationInfoItem]? {
        let decoder = PropertyListDecoder()
        
        guard let data = try? Data.init(contentsOf: plistURL),
              let locations = try? decoder.decode( [LocationInfoItem].self, from: data)
        else {
            return nil
            
        }
        return locations
    }
    
}
