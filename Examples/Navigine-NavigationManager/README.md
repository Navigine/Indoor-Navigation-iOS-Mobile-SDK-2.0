# NavigationManager example

This example shows how to load a location, receive the user's position, and display it on an indoor map. It also demonstrates selecting a venue feature and converting a long-press on the map to a location point. The map uses `NCDefaultNavigationView` with the floor selector and follow-me button.

## Setup

1. Open `Navigine-NavigationManager.xcodeproj` in Xcode.
2. In `Navigine-NavigationManager/ViewController.swift`, set `userHash` and `locationId` to values from your Navigine account. The server URL defaults to `https://ips.navigine.com`.
3. Build and run the `Navigine-NavigationManager` scheme on an iOS device with a valid location.

## Receive position updates

The example creates `NCLocationManager` and `NCNavigationManager`, then subscribes to `NCPositionListener`. On each position update, it converts the location point to the map's global coordinate system and moves an `NCIconMapObject` to that position:

```swift
func onPositionUpdated(_ position: NCPosition) {
    guard let point = position.locationPoint,
          let sublocation = location.sublocations.first(where: { $0.id == point.sublocationId }) else { return }

    let globalPoint = sublocation.local(toGlobal: point)
    userIcon.setPosition(globalPoint, sublocationId: NSNumber(value: sublocation.id))
}
```

The example hides the user icon when `onPositionError(_:)` is called.

## Map interaction

- Tap a map feature to receive its attributes through `NCPickListener`.
- Long-press the map to convert the screen position into a local point using `screenPosition(toGlobal:)` and `NCSublocation.global(toLocal:)`.
- Change floors with the view's built-in floor selector.

## SDK components used

- `NCLocationManager` and `NCLocationListener` to load the location.
- `NCNavigationManager` and `NCPositionListener` to receive position updates.
- `NCIconMapObject` to display the user position.
- `NCInputListener` and `NCPickListener` for map gestures and feature picking.
- `NCDefaultNavigationView` to provide the map and built-in navigation controls.
