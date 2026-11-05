# AsyncRouteManager example

This example shows how to calculate a route asynchronously, draw its path on the map, and update the route as navigation progresses. It uses `NCDefaultNavigationView` with the floor selector and follow-me button.

## Setup

1. Open `Navigine-AsyncRouteManager.xcodeproj` in Xcode.
2. In `Navigine-AsyncRouteManager/ViewController.swift`, set `userHash` and `locationId` to values from your Navigine account. Keep `serverUrl` set to your server (the example defaults to `https://ips.navigine.com`).
3. Build and run the `Navigine-AsyncRouteManager` scheme on an iOS device with a valid location.

## How it works

The controller initializes `NCNavigineSdk`, then obtains `NCLocationManager`, `NCNavigationManager`, and `NCAsyncRouteManager`. Once the location is loaded, it selects a sublocation and prepares map icons for the user's position and route destination.

Long-press a destination on the map to create a route session. The example converts the screen coordinate through the map window and selected sublocation, then starts a session with `NCRouteOptions`:

```swift
let globalPoint = mLocationView.locationWindow.screenPosition(toGlobal: screenPoint)
let localPoint = sublocation.global(toLocal: globalPoint)
let destination = NCLocationPoint(
    point: localPoint,
    locationId: location.id,
    sublocationId: sublocation.id
)

let options = NCRouteOptions(smoothRadius: 0, maxProjectionDistance: 3, maxAdvance: 2)
let session = mAsyncRouteManager?.createRouteSession(destination, routeOptions: options)
session?.add(self)
```

`NCAsyncRouteListener` reports route status and progress through `onRouteChanged(_ status: NCRouteStatus, currentPath: NCRoutePath?)` and `onRouteAdvanced(_ distance: Float, point: NCLocationPoint)`. The example draws route segments as `NCLocationPolyline` objects and updates the user marker when the route advances. Long-pressing another destination cancels the previous session and starts a new one.

## SDK components used

- `NCLocationManager` to load the location.
- `NCNavigationManager` and `NCPositionListener` to receive position updates.
- `NCAsyncRouteManager`, `NCRouteSession`, and `NCAsyncRouteListener` to calculate and track a route.
- `NCInputListener` to handle map gestures and `NCPickListener` to read tapped map features.
- `NCDefaultNavigationView` to display the map with its built-in floor and follow-me controls.
