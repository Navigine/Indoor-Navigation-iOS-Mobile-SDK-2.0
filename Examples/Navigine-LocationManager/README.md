# LocationManager example

This example shows how to configure the SDK, download a location, and display one of its sublocations using `NCDefaultNavigationView`.

## Setup

1. Open `Navigine-LocationManager.xcodeproj` in Xcode.
2. In `Navigine-LocationManager/ViewController.swift`, set `userHash` and `locationId` to values from your Navigine account. The default server URL is `https://ips.navigine.com`.
3. Build and run the `Navigine-LocationManager` scheme.

## Load and display a location

The example initializes the SDK and subscribes the view controller to location updates:

```swift
let sdk = NCNavigineSdk.getInstance()
sdk?.setServer(serverUrl)
sdk?.setUserHash(userHash)

locationManager = sdk?.getLocationManager()
locationManager?.add(self)
locationManager?.setLocationId(locationId)
```

When `onLocationLoaded(_:)` is called, the controller selects a sublocation by its index and assigns its ID to the map window:

```swift
func onLocationLoaded(_ location: NCLocation?) {
    guard let location,
          let sublocation = location.sublocations.first else { return }

    locationView.locationWindow.setSublocationId(sublocation.id)
}
```

`NCLocationListener` also provides `onLocationFailed(_:error:)` for load failures and `onLocationUploaded(_:)` for upload completion. The example's default navigation view shows the floor selector and follow-me button; built-in zoom controls are not enabled.

## SDK components used

- `NCNavigineSdk` for server and user-hash configuration.
- `NCLocationManager` and `NCLocationListener` to request a location and handle its result.
- `NCDefaultNavigationView` and `NCLocationWindow` to display the selected floor.
