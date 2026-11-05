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
            url: "https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/releases/download/v.2.29.1/Navigine.xcframework.zip",
            checksum: "04057d7bfed49233866c2d44acee09c8ef5a1dcd69f0a6a1e8d1ca2eaf3125a6"
        ),
        .target(
            name: "NavigineDependencies",
            path: "NavigineDependencies",
            linkerSettings: navigineLinkerSettings
        ),
    ]
)
