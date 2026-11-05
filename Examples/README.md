# Navigine iOS SDK examples

This folder contains small Xcode projects demonstrating common ways to use the Navigine iOS SDK. Each example focuses on one SDK manager or map-view workflow and includes its own setup notes.

## Quick start

1. Open the selected `.xcodeproj` in Xcode.
2. Use a valid server URL, user hash, and—when the example loads a specific location—a location ID from your [Navigine account](https://locations.navigine.com/).
3. Update the example's `ViewController.swift` values before running it. The projects use `https://ips.navigine.com` as the server URL; replace the user hash and location ID placeholders with values available to your account.
4. Build and run the project on an iOS device. Availability requirements are set per Xcode project.

The SDK is included in the example projects. Each project uses its own SDK framework copy, so examples can be opened and run independently.

## Example catalog

| Example | Demonstrates |
| --- | --- |
| [LocationListManager](Navigine-LocationListManager/README.md) | Requesting and updating the list of locations available to the user. |
| [LocationManager](Navigine-LocationManager/README.md) | Loading a location and displaying a sublocation with `NCDefaultNavigationView`. |
| [NavigationManager](Navigine-NavigationManager/README.md) | Receiving user position updates, displaying a position icon, and handling map input and feature picking. |
| [AsyncRouteManager](Navigine-AsyncRouteManager/README.md) | Creating an asynchronous route session, drawing route segments, and processing route progress. |
| [LocationView](Navigine-LocationView/README.md) | Working directly with `NCLocationView`, map objects, floor selection, and camera controls. |

## Shared SDK setup

The examples configure the SDK before requesting a manager:

```swift
let sdk = NCNavigineSdk.getInstance()
sdk?.setServer("https://ips.navigine.com")
sdk?.setUserHash("YOUR_USER_HASH")
```

For projects that load one location, set its ID on `NCLocationManager`:

```swift
let locationManager = sdk?.getLocationManager()
locationManager?.setLocationId(locationId) // Int32 from your location list
```

See the individual README for the manager setup, listener callbacks, and map interactions used by each project.
