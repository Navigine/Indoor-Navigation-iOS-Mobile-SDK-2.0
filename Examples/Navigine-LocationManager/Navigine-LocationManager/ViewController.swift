//
//  ViewController.swift
//  Navigine-LocationManager
//
//  Created by Elvira Khabibullina on 04.07.2024.
//

import UIKit
import Navigine

class ViewController: UIViewController {

    private let serverUrl = "https://ips.navigine.com"
    private let userHash = "1DE0-C579-7274-35E8"
    
    private let locationId: Int32 = 112
    
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
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)
        mLocationManager = mNavigineSdk?.getLocationManager()
        mLocationManager?.add(self)
    }
    
    func setLocation() {
        mLocationManager?.setLocationId(locationId)
    }
    
    func setupFloor(_ floor: Int) {
        let sublocation = mLocation?.sublocations[floor]
        if sublocation == mSublocation {
            return
        }
        mSublocation = sublocation
        mLocationView.locationWindow.setSublocationId(mSublocation!.id)
        
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
    func onLocationLoaded(_ location: NCLocation?) {
        mLocation = location
        setupFloor(floor)
        print("Location \(mLocation?.id))")
        mLocation?.sublocations.map({ subLocation in
            print("Sublocation: \(subLocation.id)")
        })
        
        
    }
    
    func onLocationFailed(_ locationId: Int32, error: Error?) {
        print("location loading failed with error: \(String(describing: error))")
    }
    
    func onLocationUploaded(_ locationId: Int32) {
        
    }
    
    
}

