// swift-tools-version:5.9
import PackageDescription

let navigineLinkerSettings: [LinkerSetting] = [
    .linkedFramework("CoreFoundation"),
    .linkedFramework("CoreGraphics"),
    .linkedFramework("CoreLocation"),
    .linkedFramework("CoreText"),
    .linkedFramework("CoreBluetooth"),
    .linkedFramework("GLKit"),
    .linkedFramework("SystemConfiguration"),
    .linkedFramework("OpenGLES"),
    .linkedFramework("QuartzCore"),
    .linkedFramework("UIKit"),
    .linkedFramework("Metal"),
    .linkedLibrary("c++"),
]

let package = Package(
    name: "Navigine",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "Navigine",
            targets: ["Navigine", "NavigineDependencies"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "Navigine",
            url: "https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/releases/download/v.2.27.0/Navigine.xcframework.zip",
            checksum: "6e58784aab259901ece40c5b5da20243ebc5dd31bf78d787219563cbe3b1d345"
        ),
        .target(
            name: "NavigineDependencies",
            path: "NavigineDependencies",
            linkerSettings: navigineLinkerSettings
        ),
    ]
)
