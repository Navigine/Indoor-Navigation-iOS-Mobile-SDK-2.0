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
    private let userHash = "0000-0000-0000-0000"
    private let locationId: Int32 = 0
    
    private var floor: Int = 0
    
    private var mNavigineSdk: NCNavigineSdk?
    private var mLocationManager: NCLocationManager?
    
    private var mLocation: NCLocation?
    private var mSublocation: NCSublocation?
    
    @IBOutlet weak var mLocationView: NCLocationView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
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
        
        //resize map by screen size
        setupZoomFactor()
        view.layoutIfNeeded()
    }
    
    func setupZoomFactor() {
        mLocationView.locationWindow.maxZoomFactor = Float(mLocationView.frame.width * 20 / CGFloat(mSublocation!.width))
        mLocationView.locationWindow.minZoomFactor = Float(mLocationView.frame.width / 20 / CGFloat(mSublocation!.width))
        mLocationView.locationWindow.zoomFactor = Float(mLocationView.frame.width / CGFloat(mSublocation!.width))
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

