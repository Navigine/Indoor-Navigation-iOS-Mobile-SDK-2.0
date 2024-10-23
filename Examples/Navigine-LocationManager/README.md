NCLocationManager class is used for downloading and working with location.
You can download [example project](Examples/Navigine-LocationManager) to try it on your location

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

   func initSDK() {
        //the main funcions to init Navigine SDK
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)

        //get location manager and add your class to listen updates of location manager
        mLocationManager = mNavigineSdk?.getLocationManager()
        mLocationManager?.add(self)
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

You will find a full example of use LocationManager, in this small [project](Examples/Navigine-LocationManager/Navigine-LocationManager) we showed how we use the LocationManager in our application
