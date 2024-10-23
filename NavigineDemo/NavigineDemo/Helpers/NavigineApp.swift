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
    static var locationState = NCLocationState.none
    
    static func initWith(userHash: String, serverUrl: String) {
        mNavigineSdk = NCNavigineSdk.getInstance()
        mNavigineSdk?.setServer(serverUrl)
        mNavigineSdk?.setUserHash(userHash)
        mLocationListManager = mNavigineSdk?.getLocationListManager()
        mLocationManager = mNavigineSdk?.getLocationManager()
        mNavigationManager = mNavigineSdk?.getNavigationManager(mLocationManager)
        mResourceManager = mNavigineSdk?.getResourceManager(mLocationManager)
        mMeasurementManager = mNavigineSdk?.getMeasurementManager(mLocationManager)
        mInspectManager = mNavigineSdk?.getLocationEdit(mLocationManager)
        mRouteManager = mNavigineSdk?.getRouteManager(mLocationManager, navigationManager: mNavigationManager)
        mZoneManager = mNavigineSdk?.getZoneManager(mNavigationManager)
    }
}
