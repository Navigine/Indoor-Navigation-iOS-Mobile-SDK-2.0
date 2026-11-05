//
//  ViewController.swift
//  Navigine-LocationManager
//
//  Created by Elvira Khabibullina on 04.07.2024.
//

import UIKit
import Navigine

class ViewController: UIViewController {

    // insert your user hash & location id from https://locations.navigine.com/
    private let serverUrl = "https://ips.navigine.com"
    private let userHash = "1DE0-C579-7274-35E8"
    private let locationId: Int32 = 112
    
    private var floor: Int = 0
    
    private var mNavigineSdk: NCNavigineSdk?
    private var mLocationManager: NCLocationManager?
    
    private var mLocation: NCLocation?
    private var mSublocation: NCSublocation?
    
    @IBOutlet weak var mLocationView: NCDefaultNavigationView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let viewConfig = NCDefaultNavigationViewConfig.default()
        viewConfig.visibleWidgets = [.followMeButton, .floorSelector]
        mLocationView.viewConfig = viewConfig
        initSDK()
        setLocation()
    }
    
    deinit {
        mLocationManager?.remove(self)
    }
    
    func initSDK() {
        //the main funcions to init Navigine SDK
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)
        //get location manager and add your class to listen updates of location manager
        mLocationManager = mNavigineSdk?.getLocationManager()
        mLocationManager?.add(self)
    }
    
    func setLocation() {
        //set necessary lovation id to work with it
        mLocationManager?.setLocationId(locationId)
    }
    
    func setupFloor(_ floor: Int) {
        //search for sublocation id ib your location by floor index
        let sublocation = mLocation?.sublocations[floor]
        if sublocation == mSublocation {
            return
        }
        mSublocation = sublocation
        
        // set sublocation id to load the map to location view on your screen
        mLocationView.locationWindow.setSublocationId(mSublocation!.id)
        
        view.layoutIfNeeded()
    }
}

extension ViewController: NCLocationListener {
    
    //this func called when new location loaded or updated from server, don't forget to set floor to update map on the screen
    func onLocationLoaded(_ location: NCLocation?) {
        //check if location is changed or loaded new location
        let isLocationNew = (mLocation == nil || mLocation?.id != location?.id)
        if isLocationNew {
            mLocation = location
            setupFloor(floor)
            mLocation?.sublocations.map({ subLocation in
                print("Sublocation: \(subLocation.id)")
            })
        }
        
        
    }
    
    //when location loading failed you can check why
    func onLocationFailed(_ locationId: Int32, error: Error?) {
        print("location loading failed with error: \(String(describing: error))")
    }
    
    //when you change location and update it on the server called this func
    func onLocationUploaded(_ locationId: Int32) {
        
    }
    
    
}
