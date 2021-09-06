<a href="http://navigine.com"><img src="https://navigine.com/assets/web/images/logo.svg" align="right" height="60" width="180" hspace="10" vspace="5"></a>

# iOS SDK 2.0 Beta version

The following sections describe the contents of the Navigine iOS SDK repository. Files in our public repository for iOS are:

- Sources of the Navigine Demo Application for iOS
- Navigine SDK for iOS - header files and resources

## Useful Links

- [SDK documentation](https://github.com/Navigine/Indoor-Navigation-iOS-Mobile-SDK-2.0/wiki)
- Refer to the [Navigine official documentation](https://docs.navigine.com) for complete list of downloads, useful materials, information about the company, and so on.
- [Get started](http://client.navigine.com/login) with Navigine to get full access to Navigation services, SDKs, and applications.
- Refer to the Navigine [User Manual](http://docs.navigine.com/) for complete product usage guidelines.
- Find company contact information at the official website under <a href="https://navigine.com/contacts/">Contact</a> tab.

## iOS Demo Application

Navigine demo application for iOS enables you to test indoor navigation that you set up using Navigine CMS.
The NavigineDemo subfolder in this repository contains source files that you can use for compiling the Demo application.

To get the Navigine demo application for iOS, 

- Either find the [Navigine application in the Apple Store](https://itunes.apple.com/ru/app/navigine/id972099798) using your iOS device
- Or compile the application yourself [using source code, available at GitHub](https://github.com/Navigine/iOS-SDK-2.0).

For complete guidelines on using the Demo, refer to the [corresponding sections in the Navigine User Manual](http://docs.navigine.com/ud_ios_demo.html), or refer to the Help file incorporated into the application.

## Navigation SDK and Implementation

Navigine SDK for iOS applications enables you to develop your own indoor navigation apps using the well-developed methods, classes, and functions created by the Navigine team.
The SDK file resides in the libs folder.

Find formal description of Navigine-SDK API including the list of classes and their public fields and methods at [Navigine SDK wiki](https://github.com/Navigine/iOS-SDK-2.0/wiki).

### Using .framework file in XCode

- Download `navigine.framework.zip` file from current repositories `Frameworks` folder and unarchive it;
- In your project create `Frameworks` folder and move `navigine.framework` to there;
- Embed and sign it, add Bridging Headers file;
- Start using Navigine SDK.

### Using with CocoaPods

Will be added soon...
