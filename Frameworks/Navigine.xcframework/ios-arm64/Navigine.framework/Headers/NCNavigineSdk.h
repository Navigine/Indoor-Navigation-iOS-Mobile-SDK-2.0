#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCAsyncRouteManager;
@class NCBeaconProximityEstimator;
@class NCLocationEditManager;
@class NCLocationListManager;
@class NCLocationManager;
@class NCMeasurementManager;
@class NCNavigationManager;
@class NCNavigineSdk;
@class NCNotificationManager;
@class NCResourceManager;
@class NCRouteManager;
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
 */
+ (nullable NCNavigineSdk *)getInstance;

/**
 *
 * @brief Method returns NavigineSdk SDK Version.
 * @return version of SDK
 *
 */
+ (nonnull NSString *)getVersion;

/**
 *
 * @brief Method returns persistent device id.
 * @return persistent device id
 *
 */
+ (nonnull NSString *)getDeviceId;

/**
 *
 * @brief Method returns current timestamp.
 * @return internal timestamp
 *
 */
+ (int64_t)getRelativeTime;

/**
 *
 * @brief Method is used to set `USER_HASH` from the user's profile in CMS
 * @param userHash auth token in format XXXX-XXXX-XXXX-XXXX
 *
 */
- (void)setUserHash:(nonnull NSString *)userHash;

/**
 *
 * @brief Method is used to set server url
 * @param server custom server url in format: `http[s]://example.com`
 *
 */
- (void)setServer:(nonnull NSString *)server;

/**
 *
 * @brief @see LocationManager "LocationManager" instance, which could be used for working with the @see Location "Location".
 * @return @see LocationManager "LocationManager" instance
 *
 */
- (nullable NCLocationManager *)getLocationManager;

/**
 *
 * @brief @see NavigationManager "NavigationManager" instance, which could be used for working with the @see Position.
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return @see NavigationManager "NavigationManager" instance
 *
 */
- (nullable NCNavigationManager *)getNavigationManager:(nullable NCLocationManager *)locationManager;

/**
 *
 * @brief @see ZoneManager "ZoneManager" instance, which could be used for working with zones and detecting enter and leave events. @see Zone "Zone"
 * @param navigationManager @see NavigationManager "NavigationManager" instance
 * @return @see ZoneManager "ZoneManager" instance
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
 */
- (nullable NCAsyncRouteManager *)getAsyncRouteManager:(nullable NCLocationManager *)locationManager
                                     navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * @brief @see NotificationManager "NotificationManager" instance, which could be used for working with notifications when detecting beacons. @see Notification "Notification"
 * @param locationManager @see LocationManager "LocationManager" instance
 * @return @see NotificationManager "NotificationManager" instance
 *
 */
- (nullable NCNotificationManager *)getNotificationManager:(nullable NCLocationManager *)locationManager;

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

- (nullable NCMeasurementManager *)getMeasurementManager:(nullable NCLocationManager *)locationManager;

- (nullable NCBeaconProximityEstimator *)getBeaconProximityEstimator:(nullable NCLocationManager *)locationManager;

- (nonnull NSString *)getErrorDescription:(int32_t)errorCode;

/**
 *
 * createLocationWindow(platform_view: platform_view): location_window;
 *
 * @endcond
 *
 * Returns a manager that allows to manage locations list
 * @return Location list manager instance @see LocationListManager "LocationListManager"
 *
 */
- (nullable NCLocationListManager *)getLocationListManager;

@end
