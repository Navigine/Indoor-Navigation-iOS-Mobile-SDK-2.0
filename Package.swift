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
            url: "https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/releases/download/v.2.26.1/Navigine.xcframework.zip",
            checksum: "11cc03d904905e1c7bdabf7a43a9076db0e8d5fadfb5dece0f33abba629c818b"
        ),
        .target(
            name: "NavigineDependencies",
            path: "NavigineDependencies",
            linkerSettings: navigineLinkerSettings
        ),
    ]
)
