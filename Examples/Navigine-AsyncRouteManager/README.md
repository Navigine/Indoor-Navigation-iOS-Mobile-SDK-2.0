NCAsyncRouteManager class is used for class is used for evaluating route path from point to point.

You can download [example project](Examples/Navigine-AsyncRouteManager) to try it on your location.

# Step 1
Replace all user data with your own

```swift
    let serverUrl = "https://ips.navigine.com"
    let userHash = "0000-0000-0000-0000"
    let locationId: Int32 = 0
```

# Step 2
Initialize SDK by following methods

```swift

    var mNavigineSdk: NCNavigineSdk?
    var mLocationManager: NCLocationManager?
    var mNavigationManager: NCNavigationManager?
    var mAsyncRouteManager: NCAsyncRouteManager?
    var mAsyncRouteSession: NCRouteSession?

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
```

# Step 3 
Set your location ID

```swift
mLocationManager?.setLocationId(locationId)
```

# Step 4
Subscribe your class to the NCLocationListener

```swift
extension ViewController: NCLocationListener {
    
    //this func called when new location loaded or updated from server, **don't forget to set floor** to update map on the screen
    func onLocationLoaded(_ location: NCLocation?) {
    }
    
    //when location loading failed you can check why
    func onLocationFailed(_ locationId: Int32, error: Error?) {
    }
    
    //when you change location and update it on the server called this func
    func onLocationUploaded(_ locationId: Int32) {
    }
}
```

# Step 5
Subscribe your class to NCPositionListener

```swift
extension ViewController: NCPositionListener {
  func onPositionUpdated(_ position: NCPosition) {
      //here you should update position of user icon on map (NCFlatIconMapObject)
  }
  
  
  func onPositionError(_ error: Error?) {
    //usually we remove user position icon from map if we have position error
  }
}
```

# Step 6
Subscribe to NCInputListener to use gestures on the map. **Here we start navigation by long tap.**

```swift
extension ViewController : NCInputListener {
  func onViewTap(_ screenPoint: CGPoint) {
      //here you redirect to Step 7 if user taped on venue
      mLocationView.locationWindow.pickMapFeature(at: screenPoint)
  }
  
  func onViewDoubleTap(_ screenPoint: CGPoint) {
   
  }
  
  func onViewLongTap(_ screenPoint: CGPoint) {
        //func to convert screen point to location point on the map
        let point = mLocationView.locationWindow.screenPosition(toMeters: screenPoint)
        let locPoint = NCLocationPoint(point: point, locationId: mLocation!.id , sublocationId: mLocation!.sublocations[floor].id)
        
        //here is an example how to start routing by long tap
        mFinishPoint = locPoint
        startRouting()
  }

  func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeLongPressGesture location: CGPoint) {

  }
}
```

# Step 7
To start routing you should create session in NCAsyncRouteManager like in this example.
 
```swift
    func startRouting() {
        if let asyncRouteSession = mAsyncRouteSession {
            mAsyncRouteManager?.cancel(asyncRouteSession)
        }
        let options =  NCRouteOptions(smoothRadius: 0, maxProjectionDistance: 3, maxAdvance: 2)
        mAsyncRouteSession = mAsyncRouteManager?.createRouteSession(mFinishPoint, routeOptions: options)
        mAsyncRouteSession?.add(self)
    }
```

# Step 8
Subscribe to NCAsyncRouteListener to track actual route status

```swift
extension ViewController: NCAsyncRouteListener {
    func onRouteChanged(_ currentPath: NCRoutePath?) {
        
    }
    
    func onRouteAdvanced(_ distance: Float, point: NCLocationPoint) {
        
    }
}
```

You will find a full example of use NCAsyncRouteManager, in this small [project](Examples/Navigine-AsyncRouteManager) we showed how we use the NCAsyncRouteManager in our application
