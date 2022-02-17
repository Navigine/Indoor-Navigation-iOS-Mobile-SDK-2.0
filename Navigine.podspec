Pod::Spec.new do |spec|
  spec.name                 = 'Navigine'
  spec.version              = '2.0.5'
  spec.license              = { :type => 'Custom', :text => 'Navigine Licence'}
  spec.summary              = "iOS SDK for performing indoor navigation"
  spec.platform             = :ios, "11.0"
  spec.homepage             = 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0'
  spec.authors              = { 'Pavel Tychinin' => 'p.tychinin@navigine.com' }
  spec.source               = { :git => 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0.git', :tag => 'v.2.0.5' }
  spec.documentation_url    = 'https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/wiki/Getting-Started'
  spec.vendored_frameworks  = 'Frameworks/navigine.framework'
#  spec.vendored_libraries   = 'Frameworks/navigine.framework/Navigine'
  spec.public_header_files  = 'Frameworks/navigine.framework/Headers/*.h'
  spec.source_files         = 'Frameworks/navigine.framework/Headers'
  spec.pod_target_xcconfig  = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.exclude_files        = "Classes/Exclude"
  spec.requires_arc         =  true
end
