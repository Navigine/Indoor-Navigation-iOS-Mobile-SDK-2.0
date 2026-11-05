# LocationListManager example

This example shows how to request the locations available to a Navigine user and receive the result through `NCLocationListListener`.

## Setup

1. Open `Navigine-LocationListManager.xcodeproj` in Xcode.
2. In `Navigine-LocationListManager/ViewController.swift`, replace `userHash` with the hash from your Navigine account. The example uses `https://ips.navigine.com` as its server URL.
3. Build and run the `Navigine-LocationListManager` scheme.

## Request the location list

After configuring the SDK, obtain `NCLocationListManager`, add a listener, and request the list:

```swift
let sdk = NCNavigineSdk.getInstance()
sdk?.setServer(serverUrl)
sdk?.setUserHash(userHash)

locationListManager = sdk?.getLocationListManager()
locationListManager?.add(self)
locationListManager?.getLocationList()
```

The example prints the returned `[NSNumber: NCLocationInfo]` dictionary in `onLocationListLoaded(_:)`. Its **Update** action calls `updateLocationList()` to request an update. `onLocationListFailed(_:)` receives a loading error.

Use a location ID from the returned list when configuring an example that loads a specific location.

## SDK components used

- `NCNavigineSdk` for server and user-hash configuration.
- `NCLocationListManager` to request or update the available locations.
- `NCLocationListListener` to handle the loaded list or an error.
