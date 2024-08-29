//
//  ViewController.swift
//  Navigine-LocationListManager
//
//  Created by Elvira Khabibullina on 01.07.2024.
//

import UIKit
import Navigine

class ViewController: UIViewController {

    private let serverUrl = "https://ips.navigine.com"
    private let userHash = "1DE0-C579-7274-35E8"
    
    private var mNavigineSdk: NCNavigineSdk?
    private var mLocationListManager: NCLocationListManager?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        initSDK()
        getLocationList()
    }
    
    deinit {
        //removing listener when it is not needed
        mLocationListManager?.remove(self)
    }

    func initSDK() {
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)
        mLocationListManager = mNavigineSdk?.getLocationListManager()
        mLocationListManager?.add(self)
    }
    
    func getLocationList() {
        mLocationListManager?.getLocationList()
    }
    
    @IBAction func forceUpdateLocations(_ sender: Any) {
        mLocationListManager?.updateLocationList()
    }
}

extension ViewController : NCLocationListListener {
    func onLocationListLoaded(_ locationInfos: [NSNumber : NCLocationInfo]) {
        print(locationInfos.debugDescription)
    }
    
    func onLocationListFailed(_ error: Error?) {
        print("location list loading failed with error: \(error)")
    }
    
    
}
