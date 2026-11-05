# LocationView example

This example demonstrates the SDK's lower-level `NCLocationView` API. Unlike the other map examples, it intentionally uses `NCLocationView` directly so you can work with the location window and build your own controls.

## Setup

1. Open `Navigine-LocationView.xcodeproj` in Xcode.
2. In `Navigine-LocationView/ViewController.swift`, set `userHash` and `locationId` to values from your Navigine account. The server URL defaults to `https://ips.navigine.com`.
3. Build and run the `Navigine-LocationView` scheme.

## Example controls

- The floor label and stepper show and change the selected sublocation.
- **Circle** adds an interactive circle map object.
- **Icon** adds a map icon.
- **Line** draws a polyline through three points.
- **Center** flies the camera to the center of the selected sublocation.
- **Camera Info** displays the current camera position, zoom, and rotation.

## Map objects and coordinates

The example creates map objects through `NCLocationWindow`. It converts local location points to global coordinates before placing the objects:

```swift
let locationPoint = NCLocationPoint(
    point: NCPoint(x: sublocation.width / 2, y: sublocation.height / 2),
    locationId: sublocation.location,
    sublocationId: sublocation.id
)
let globalPoint = sublocation.local(toGlobal: locationPoint)
_ = circle?.setPosition(globalPoint, sublocationId: NSNumber(value: sublocation.id))
```

For camera movement, the example builds an `NCCamera` from the selected sublocation's center and calls `fly(to:duration:callback:)`. `NCPickListener` and `NCInputListener` are registered on the location window for map picking and gestures; their callbacks are empty in this example, ready for experimentation.

## SDK components used

- `NCLocationView` and `NCLocationWindow` for displaying and controlling the map.
- `NCLocationManager` and `NCLocationListener` for loading a location.
- `NCSublocation` coordinate conversion methods for placing objects and positioning the camera.
- `NCCircleMapObject`, `NCIconMapObject`, `NCPolylineMapObject`, `NCLocationPolyline`, and `NCCamera`.
- `NCPickListener` and `NCInputListener` for map events.
