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
 * Provides access to all services in the SDK.
 *
 * @note SDK holds objects by weak references. You need
 * to have strong references to them somewhere in the client code.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigineSdk : NSObject

/**
 *
 * Returns instance of SDK
 *
 */
+ (nullable NCNavigineSdk *)getInstance;

/**
 *
 * Returns version of SDK
 *
 */
+ (nonnull NSString *)getVersion;

/**
 *
 * Returns persistent device id
 *
 */
+ (nonnull NSString *)getDeviceId;

/**
 *
 * Returns internal timestamp
 *
 */
+ (int64_t)getRelativeTime;

/**
 *
 * Method is used to set USER_HASH from the user's profile in CMS
 * @param userHash - auth token in format XXXX-XXXX-XXXX-XXXX
 *
 */
- (void)setUserHash:(nonnull NSString *)userHash;

/**
 *
 * Method is used to set server url
 * @param server - custom server url in format: `http[s]://example.com`
 *
 */
- (void)setServer:(nonnull NSString *)server;

/**
 *
 * Returns a manager that allows to listen for new locations
 *     and manage selected one
 *
 */
- (nullable NCLocationManager *)getLocationManager;

/**
 *
 * Returns a manager that allows to listen for position updates
 *
 */
- (nullable NCNavigationManager *)getNavigationManager:(nullable NCLocationManager *)locationManager;

/**
 *
 * Returns a manager that allows to listen for zone events (enter/exit particular zone)
 *
 */
- (nullable NCZoneManager *)getZoneManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * Returns a manager that allows to
 * 1 - build a route from point to point
 * 2 - set target point and subscribe for route updates
 *
 */
- (nullable NCRouteManager *)getRouteManager:(nullable NCLocationManager *)locationManager
                           navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * Returns a manager that allows to manage routing sessions (@see RouteSession class)
 *
 */
- (nullable NCAsyncRouteManager *)getAsyncRouteManager:(nullable NCLocationManager *)locationManager
                                     navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 *
 * Returns a manager that allows to manage resources
 * 1 - download and decode images
 * 2 - managing logs
 *
 */
- (nullable NCResourceManager *)getResourceManager:(nullable NCLocationManager *)locationManager;

/**
 *
 * Returns a manager that allows to manage local notifications based on signal measurements
 *
 */
- (nullable NCNotificationManager *)getNotificationManager:(nullable NCLocationManager *)locationManager;

- (nullable NCLocationEditManager *)getLocationEditManager:(nullable NCLocationManager *)locationManager;

- (nullable NCMeasurementManager *)getMeasurementManager:(nullable NCLocationManager *)locationManager;

- (nullable NCBeaconProximityEstimator *)getBeaconProximityEstimator:(nullable NCLocationManager *)locationManager;

- (nonnull NSString *)getErrorDescription:(int32_t)errorCode;

/**
 *
 * createLocationWindow(platform_view: platform_view): location_window;
 *
 */
- (nullable NCLocationListManager *)getLocationListManager;

@end
