import Foundation

class NavigineApp {
    static var mNavigineSdk: NCNavigineSdk?
    static var mLocationListManager: NCLocationListManager?
    static var mLocationManager: NCLocationManager?
    static var mNavigationManager: NCNavigationManager?
    static var mZoneManager: NCZoneManager?
    static var mResourceManager: NCResourceManager?
    static var mMeasurementManager: NCMeasurementManager?
    static var mInspectManager: NCLocationEditManager?
    static var mRouteManager: NCRouteManager?
    
    static func initWith(userHash: String, serverUrl: String) {
        NCNavigineSdk.setServer(serverUrl)
        NCNavigineSdk.setUserHash(userHash)
        mNavigineSdk = NCNavigineSdk.getInstance()
        mLocationListManager = mNavigineSdk?.getLocationListManager()
        mLocationManager = mNavigineSdk?.getLocationManager()
        mNavigationManager = mNavigineSdk?.getNavigationManager(mLocationManager)
        mResourceManager = mNavigineSdk?.getResourceManager(mLocationManager)
        mMeasurementManager = mNavigineSdk?.getMeasurementManager()
        mInspectManager = mNavigineSdk?.getLocationEdit(mLocationManager)
        mRouteManager = mNavigineSdk?.getRouteManager(mLocationManager, navigationManager: mNavigationManager)
        mZoneManager = mNavigineSdk?.getZoneManager(mLocationManager, navigationManager: mNavigationManager)
    }
}
