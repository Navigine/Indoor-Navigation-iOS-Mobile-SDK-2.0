//
//  ViewController.swift
//  Navigine-NavigationManager
//
//  Created by Elvira Khabibullina on 30.08.2024.
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
    private var mNavigationManager: NCNavigationManager?
    private var mAsyncRouteManager: NCAsyncRouteManager?
    private var mAsyncRouteSession: NCRouteSession?
    
    private var mLocation: NCLocation?
    private var mSublocation: NCSublocation?
    
    private var mUserPositionIcon: NCFlatIconMapObject!
    private var mUserPoint : NCLocationPoint?
    
    private var mFinishPoint: NCLocationPoint!
    private var mRoutePath: NCRoutePath?
    private var mPolylines: [NCPolylineMapObject] = []
    private var mRoutingIcon: NCIconMapObject!
    
    private var mRoutingAvailable = false
    private var mUserPositionKnown = false
    
    @IBOutlet weak var mLocationView: NCLocationView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        initSDK()
        setLocation()
        setupUserPosition()
        setupRoutePin()
    }
    
    func initSDK() {
        //the main funcions to init Navigine SDK
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)
        
        //get Location manager and add your class to listen updates of location manager
        mLocationManager = mNavigineSdk?.getLocationManager()
        mLocationManager?.add(self)
        
        //get Navigation manager and add listener to update user position
        mNavigationManager = mNavigineSdk?.getNavigationManager(mLocationManager)
        mNavigationManager?.add(self)
        
        mAsyncRouteManager = mNavigineSdk?.getAsyncRouteManager(mLocationManager, navigationManager: mNavigationManager)
        
        //call func of  touches on map (NCPickListener)
        mLocationView.locationWindow.add(self as NCPickListener)
        mLocationView.locationWindow.add(self as NCInputListener)
        mLocationView.locationWindow.stickToBorder = true
        
    }
    
    func setLocation() {
        //set necessary loсation id to work with it
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
    
    //setup user position icon style
    func setupUserPosition() {
        mUserPositionIcon = mLocationView.locationWindow.addFlatIconMapObject()
        mUserPositionIcon.setBitmap(UIImage(named: "curLocation"))
        mUserPositionIcon.setSize(22.0, height: 22.0)
        mUserPositionIcon.setVisible(true)
        mUserPositionIcon.setStyle("{ order: 1, collide: false}")
    }
    
    func setupRoutePin() {
      mRoutingIcon = mLocationView.locationWindow.addIconMapObject()
      mRoutingIcon.setBitmap(UIImage(named: "pin"))
      mRoutingIcon.setSize(36.0, height: 108.0)
      mRoutingIcon.setStyle("{ order: 1, collide: false}")
    }
    
    func updateUserPosition(locationPoint: NCLocationPoint) {
        if let iconObj = mUserPositionIcon {
            iconObj.setPosition(locationPoint)
            iconObj.setVisible(true)
            mUserPoint = locationPoint
        }
        mUserPositionKnown = true
    }
    
    func stopRoute() {
      mFinishPoint = nil
      mRoutingIcon.setVisible(false)
      mRoutePath = nil
      
      mAsyncRouteSession?.remove(self)
      mAsyncRouteManager?.cancel(mAsyncRouteSession)
      for polilyne in mPolylines {
        polilyne.setVisible(false)
        mLocationView.locationWindow.remove(polilyne)
      }
      mPolylines.removeAll()
      
    }
}

//MARK: NCLocationListener
extension ViewController: NCLocationListener {
    
    //this func called when new location loaded or updated from server, don't forget to set floor to update map on the screen
    func onLocationLoaded(_ location: NCLocation?) {
        //check if location is changed or loaded new location
        let isLocationNew = (mLocation == nil || mLocation?.id != location?.id)
        if isLocationNew {
            mLocation = location
            setupFloor(floor)
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

//MARK: NCPositionListener
extension ViewController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
        mRoutingAvailable = true
        if position.locationPoint != nil {
            updateUserPosition(locationPoint: position.locationPoint!)
        }
    }
    
    
    func onPositionError(_ error: Error?) {
        mRoutingAvailable = false
        mUserPositionKnown = false
        if let iconObj = mUserPositionIcon {
            iconObj.setVisible(false)
        }
    }
}

//MARK: NCPickListener
extension ViewController: NCPickListener {
    func onMapObjectPickComplete(_ mapObjectPickResult: NCMapObjectPickResult?, screenPosition: CGPoint) {
        
    }
    
    func onMapFeaturePickComplete(_ mapFeaturePickResult: [String : String], screenPosition: CGPoint) {
        //get all info from mapFeaturePickResult and create struct for further use
        guard let name = mapFeaturePickResult["name"],
              let description = mapFeaturePickResult["description"],
              let image = mapFeaturePickResult["image"],
              let phone = mapFeaturePickResult["phone"],
              let kind = mapFeaturePickResult["kind"],
              let alias = mapFeaturePickResult["alias"] else {
            return
        }
        let venue = VenueObject.init(name: name,
                                     description: description,
                                     imageUrl: image,
                                     phone: phone,
                                     kind: kind,
                                     alias: alias)
        
        print("Did press to venue: \(venue)")
    }
}

//MARK: NCInputListener
extension ViewController : NCInputListener {
    func onViewTap(_ screenPoint: CGPoint) {
        //here I stop route as an example, you can stot routing by other actions
        stopRoute()
        mLocationView.locationWindow.pickMapFeature(at: screenPoint)
    }
    
    func onViewDoubleTap(_ screenPoint: CGPoint) {
        
    }
    
    func onViewLongTap(_ screenPoint: CGPoint) {
        if !mRoutingAvailable {
            return
        }
        //func to convert screen point to location point on the map
        let point = mLocationView.locationWindow.screenPosition(toMeters: screenPoint)
        let locPoint = NCLocationPoint(point: point, locationId: mLocation!.id , sublocationId: mLocation!.sublocations[floor].id)
        
        //here is an example how to start routing by long tap
        mFinishPoint = locPoint
        startRouting()
    }
    
    func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeLongPressGesture location: CGPoint) {
        //func to convert screen point to location point on the map
        let point = mLocationView.locationWindow.screenPosition(toMeters: location)
        let locPoint = NCLocationPoint(point: point, locationId: mLocation!.id , sublocationId: mLocation!.sublocations[floor].id)
        
    }
}

//MARK: NCAsyncRouteListener
extension ViewController: NCAsyncRouteListener {
    func onRouteChanged(_ currentPath: NCRoutePath?) {
        if !mRoutingAvailable {
            return
        }
        for polyline in mPolylines {
            mLocationView.locationWindow.remove(polyline)
        }
        mRoutePath = currentPath
    }
    
    func onRouteAdvanced(_ distance: Float, point: NCLocationPoint) {
        if !mRoutingAvailable {
            return
        }
        //user point drawing
        let locationPoint = NCLocationPoint.init(point: point.point, locationId: point.locationId, sublocationId: point.sublocationId)
        updateUserPosition(locationPoint: locationPoint)
        
        for polyline in mPolylines {
            mLocationView.locationWindow.remove(polyline)
        }
        //route path drawing
        let paths = mRoutePath?.split(distance)
        if let drawingPath = paths?[1] {
            drawNewPath(path: drawingPath)
        }
    }
    
    func startRouting() {
        if let asyncRouteSession = mAsyncRouteSession {
            mAsyncRouteManager?.cancel(asyncRouteSession)
        }
        let options =  NCRouteOptions(smoothRadius: 0, maxProjectionDistance: 3, maxAdvance: 2)
        mAsyncRouteSession = mAsyncRouteManager?.createRouteSession(mFinishPoint, routeOptions: options)
        mAsyncRouteSession?.add(self)
    }
    
    func setRoutePin(point: NCPoint) {
        mRoutingIcon.setPosition(NCLocationPoint.init(point: point, locationId:mLocation?.id ?? 0, sublocationId: mSublocation?.id ?? 0))
        mRoutingIcon.setVisible(true)
    }
    
    func drawNewPath(path: NCRoutePath) {
        var curSublocID:Int32 = 0
        
        var curPoints: [NCPoint] = []
        var curPolyline = createNewPolyline()
        
        for point in path.points.reversed() {
            if point.sublocationId != curSublocID {
                if !curPoints.isEmpty {
                    let locationPolyline = NCLocationPolyline.init(polyline: NCPolyline.init(points: curPoints), locationId: mSublocation?.location ?? 0, sublocationId: curSublocID)
                    
                    curPolyline = createNewPolyline()
                    curPolyline.setPolyLine(locationPolyline)
                    curPolyline.setVisible(true)
                    mPolylines.append(curPolyline)
                }
                
                curPoints.removeAll()
                curSublocID = point.sublocationId
            }
            curPoints.append(point.point)
        }
        
        if !curPoints.isEmpty {
            let locationPolyline = NCLocationPolyline.init(polyline: NCPolyline.init(points: curPoints), locationId: mSublocation?.location ?? 0, sublocationId: curSublocID)
            
            curPolyline = createNewPolyline()
            curPolyline.setPolyLine(locationPolyline)
            curPolyline.setVisible(true)
            mPolylines.append(curPolyline)
        }
    }
    
    func createNewPolyline() -> NCPolylineMapObject {
        let polyline = mLocationView.locationWindow.addPolylineMapObject()
        polyline?.setColor(76/255, green: 217/255, blue: 100/255, alpha: 1)
        polyline?.setVisible(false)
        polyline?.setWidth(4)
        polyline?.setStyle("{style: 'points', placement_min_length_ratio: 0, placement_spacing: 8px, size: [8px, 8px], placement: 'spaced', collide: false}")
        return polyline!
    }
}
