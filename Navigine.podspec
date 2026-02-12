Pod::Spec.new do |spec|
  spec.name                 = 'Navigine'
  spec.version              = '2.24.4'
  spec.license              = { :type => 'Custom', :text => 'Navigine Licence'}
  spec.summary              = "iOS SDK for performing indoor navigation"
  spec.platform             = :ios, "13.0"
  spec.frameworks           = ["CoreFoundation", "CoreGraphics", "CoreLocation", "CoreText", "CoreBluetooth", "GLKit", "SystemConfiguration", "OpenGLES", "QuartzCore", "UIKit", "Metal"]
  spec.libraries            = ["c++"]
  spec.homepage             = 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0'
  spec.authors              = { 'Pavel Tychinin' => 'p.tychinin@navigine.com' }
  spec.source               = { :git => 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0.git', :tag => 'v.2.24.4' }
  spec.documentation_url    = 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/wiki/Getting-Started'
  spec.vendored_frameworks  = 'Frameworks/Navigine.xcframework'
  spec.preserve_paths       = 'Frameworks/Navigine.xcframework'
end