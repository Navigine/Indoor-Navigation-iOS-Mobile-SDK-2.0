//
//  ViewController.swift
//  NavigineDemo
//
//  Created by mrcrambo on 02/10/2020.
//  Copyright © 2020 navigine. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var mNavigineSdk: NCNavigineSdk?
    var mLocationManager: NCLocationManager?
    
    @IBOutlet weak var mLocationView: NCLocationView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mNavigineSdk = NCNavigineSdk.getInstance()!
        
        mLocationManager = mNavigineSdk?.getLocationManager()!
        mLocationManager?.add(self)
        mLocationManager?.setLocation(Int32(Constants.LOCATION_ID))
    }

}

extension ViewController: NCLocationListener {
    func onDownloadProgress(_ received: Int32, total: Int32) { }
    
    func onLocationLoaded(_ location: NCLocation?) {
        mLocationView.setSublocation(Int32(Constants.SUBLOCATION_ID))
    }
        
    func onLocationFailed(_ error: Error?) { }
}
