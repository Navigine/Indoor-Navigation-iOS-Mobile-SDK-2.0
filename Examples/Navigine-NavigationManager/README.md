
NCNavigationManager class is used for evaluating navigation and calculating users' position.

You can download [example project](Examples/Navigine-NavigationManager) to try it on your location.

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
Subscribe to NCInputListener to use gestures on the map.

```swift
extension ViewController : NCInputListener {
  func onViewTap(_ screenPoint: CGPoint) {
      //here you redirect to Step 7 if user taped on venue
      mLocationView.locationWindow.pickMapFeature(at: screenPoint)
  }
  
  func onViewDoubleTap(_ screenPoint: CGPoint) {
   
  }
  
  func onViewLongTap(_ screenPoint: CGPoint) {

  }

  func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeLongPressGesture location: CGPoint) {

  }
}
```

# Step 7
You can get all info about venue if user tap it on map.
Just subscribe to NCPickListener

```swift
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
    
  }
}
```

You will find a full example of use NCNavigationManager, in this small [project](Examples/Navigine-NavigationManager) we showed how we use the NCNavigationManager in our application
