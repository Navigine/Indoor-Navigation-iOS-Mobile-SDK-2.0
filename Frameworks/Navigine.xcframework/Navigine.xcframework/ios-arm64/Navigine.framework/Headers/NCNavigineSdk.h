#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCAsyncRouteManager;
@class NCBeaconProximityEstimator;
@class NCLocationEditManager;
@class NCLocationListManager;
@class NCLocationManager;
@class NCLocationWindow;
@class NCMeasurementManager;
@class NCNavigationManager;
@class NCNavigineSdk;
@class NCNotificationManager;
@class NCResourceManager;
@class NCRouteManager;
@class NCStorageManager;
@class NCView;
@class NCZoneManager;


/**
 * @file NCNavigineSdk.h
 * @brief @copybrief NCNavigineSdk
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_sdk
 * @brief Provides access to all services in the SDK.
 *
 * Class contains a list of static functions for initializing library
 * and list of functions for getting access to the managers,
 * each of which will provide different opportunities for working with SDK
 *
 * @note SDK holds objects by weak references. You need
 * to have strong references to them somewhere in the client code.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigineSdk : NSObject

/**
 *
 * @brief Method initializes Navigation library and returns NavigineSdk instance.
 * @return instance of SDK
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getInstance
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getInstance
 *
 *
 */
+ (nullable NCNavigineSdk *)getInstance;

/**
 *
 * @brief Method returns NavigineSdk SDK Version.
 * @return version of SDK
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getVersion
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getVersion
 *
 *
 */
+ (nonnull NSString *)getVersion;

/**
 *
 * @brief Method returns persistent device id.
 * @return persistent device id
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getDeviceId
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getDeviceId
 *
 *
 */
+ (nonnull NSString *)getDeviceId;

/**
 *
 * @brief Method returns current timestamp.
 * @return internal timestamp
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getRelativeTime
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getRelativeTime
 *
 *
 */
+ (int64_t)getRelativeTime;

/**
 *
 * @brief Method is used to set `USER_HASH` from the user's profile in CMS
 * @param userHash auth token in format XXXX-XXXX-XXXX-XXXX
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_setUserHash
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_setUserHash
 *
 *
 */
- (void)setUserHash:(nonnull NSString *)userHash;

/**
 *
 * @brief Method is used to set server url
 * @param server custom server url in format: `http[s]://example.com`
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_setServer
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_setServer
 *
 *
 */
- (void)setServer:(nonnull NSString *)server;

/**
 *
 * @brief @see LocationManager "LocationManager" instance, which could be used for working with the @see Location "Location".
 * @return @see LocationManager "LocationManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getLocationManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getLocationManager
 *
 *
 */
- (nullable NCLocationManager *)getLocationManager;

/**
 *
 * @brief @see NavigationManager "NavigationManager" instance, which could be used for working with the @see Position.
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return @see NavigationManager "NavigationManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getNavigationManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getNavigationManager
 *
 *
 */
- (nullable NCNavigationManager *)getNavigationManager:(nullable NCLocationManager *)locationManager;

/**
 *
 * @brief @see ZoneManager "ZoneManager" instance, which could be used for working with zones and detecting enter and leave events. @see Zone "Zone"
 * @param navigationManager @see NavigationManager "NavigationManager" instance
 * @return @see ZoneManager "ZoneManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getZoneManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getZoneManager
 *
 *
 */
- (nullable NCZoneManager *)getZoneManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * @brief @see RouteManager "RouteManager" instance, which could be used for working making routes, setting target points. @see RoutePath "RoutePath"
 * @param locationManager @see LocationManager "LocationManager" instance
 * @param navigationManager @see NavigationManager "NavigationManager" instance
 * @return @see RouteManager "RouteManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getRouteManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getRouteManager
 *
 *
 */
- (nullable NCRouteManager *)getRouteManager:(nullable NCLocationManager *)locationManager
                           navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * @brief @see AsyncRouteManager "AsyncRouteManager" instance, which could be used for working with routing sessions. @see RouteSession "RouteSession"
 * @param locationManager @see LocationManager "LocationManager" instance
 * @param navigationManager @see NavigationManager "NavigationManager" instance
 * @return @see AsyncRouteManager "AsyncRouteManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getAsyncRouteManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getAsyncRouteManager
 *
 *
 */
- (nullable NCAsyncRouteManager *)getAsyncRouteManager:(nullable NCLocationManager *)locationManager
                                     navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * @brief @see NotificationManager "NotificationManager" instance, which could be used for working with notifications when detecting beacons. @see Notification "Notification"
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return @see NotificationManager "NotificationManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getNotificationManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getNotificationManager
 *
 *
 */
- (nullable NCNotificationManager *)getNotificationManager:(nullable NCLocationManager *)locationManager;

/**
 *
 * @brief @see MeasurementManager "MeasurementManager" instance, which could be used for managing measurement generators and handling sensor and signal measurements.
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return @see MeasurementManager "MeasurementManager" instance
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getMeasurementManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getMeasurementManager
 *
 *
 */
- (nullable NCMeasurementManager *)getMeasurementManager:(nullable NCLocationManager *)locationManager;

/**
 * @cond
 *
 * Returns a manager that allows to manage resources
 * 1 - download and decode images
 * 2 - managing logs
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return Resource manager instance
 *
 */
- (nullable NCResourceManager *)getResourceManager:(nullable NCLocationManager *)locationManager;

- (nullable NCLocationEditManager *)getLocationEditManager:(nullable NCLocationManager *)locationManager;

- (nullable NCBeaconProximityEstimator *)getBeaconProximityEstimator:(nullable NCLocationManager *)locationManager;

- (nonnull NSString *)getErrorDescription:(int32_t)errorCode;

- (nullable NCLocationWindow *)createLocationWindow:(nullable NCView *)platformView;

/**
 * @endcond
 *
 * Returns a manager that allows to manage locations list
 * @return Location list manager instance @see LocationListManager "LocationListManager"
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getLocationListManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getLocationListManager
 *
 *
 */
- (nullable NCLocationListManager *)getLocationListManager;

/**
 * Returns a manager that allows to manage user storages
 * @return Storage manager instance @see StorageManager "StorageManager"
 *
 *
 * Swift code snippet:
 * @snippet NavigineSdkExample.swift swift_NavigineSdk_getStorageManager
 *
 * Objective C code snippet:
 * @snippet NavigineSdkExample.m objc_NavigineSdk_getStorageManager
 *
 *
 */
- (nullable NCStorageManager *)getStorageManager;

@end
