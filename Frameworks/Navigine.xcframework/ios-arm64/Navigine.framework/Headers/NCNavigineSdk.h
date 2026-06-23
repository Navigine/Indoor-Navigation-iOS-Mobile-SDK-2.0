#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCAsyncRouteManager;
@class NCBeaconProximityEstimator;
@class NCLocationEditManager;
@class NCLocationListManager;
@class NCLocationManager;
@class NCLocationWindow;
@class NCMeasurementManager;
@class NCMqttSession;
@class NCNavigationManager;
@class NCNavigineSdk;
@class NCNotificationManager;
@class NCResourceManager;
@class NCRouteManager;
@class NCStorageManager;
@class NCUserLocationLayer;
@class NCView;
@class NCZoneManager;


/**
 * Provides access to all services in the SDK.
 * Class contains a list of static functions for initializing library
 * and list of functions for getting access to the managers,
 * each of which will provide different opportunities for working with SDK
 * @discussion Note: SDK holds objects by weak references. You need
 * to have strong references to them somewhere in the client code.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigineSdk : NSObject

/**
 * Method initializes Navigation library and returns NavigineSdk instance.
 * @return instance of SDK
 *
 * @discussion Example:
 * @code
 * // Get SDK instance
 * self.sdk = [NCNavigineSdk getInstance];
 * @endcode
 */
+ (nullable NCNavigineSdk *)getInstance;

/**
 * Method returns NavigineSdk SDK Version.
 * @return version of SDK
 *
 * @discussion Example:
 * @code
 * // Get SDK version
 * NSLog(@"Navigine SDK Version: %@", [NCNavigineSdk getVersion]);
 * @endcode
 */
+ (nonnull NSString *)getVersion;

/**
 * Method returns persistent device id.
 * @return persistent device id
 *
 * @discussion Example:
 * @code
 * // Get device ID
 * NSLog(@"Device ID: %@", [NCNavigineSdk getDeviceId]);
 * @endcode
 */
+ (nonnull NSString *)getDeviceId;

/**
 * Method returns current User-Agent string.
 * @return User-Agent string
 */
+ (nonnull NSString *)getUserAgent;

/**
 * Method returns current timestamp.
 * @return internal timestamp
 *
 * @discussion Example:
 * @code
 * // Get relative time
 * NSLog(@"Relative Time: %lld", [NCNavigineSdk getRelativeTime]);
 * @endcode
 */
+ (int64_t)getRelativeTime;

/**
 * Method is used to set `USER_HASH` from the user's profile in CMS
 * @param userHash auth token in format XXXX-XXXX-XXXX-XXXX
 *
 * @discussion Example:
 * @code
 * // Set user hash (authorization token)
 * [self.sdk setUserHash:@"XXXX-XXXX-XXXX-XXXX"];
 * @endcode
 */
- (void)setUserHash:(nonnull NSString *)userHash;

/**
 * Method is used to set server url
 * @param server custom server url in format: `http[s]://example.com`
 *
 * @discussion Example:
 * @code
 * // Set server URL (optional)
 * [self.sdk setServer:@"https://custom.navigine.com"];
 * @endcode
 */
- (void)setServer:(nonnull NSString *)server;

/**
 * Resets SDK to the initial connection state: default production server URL, empty user hash, and a new session propagated to managers (same effect on session-aware managers as changing server or user hash). Call from the UI thread.
 */
- (void)reset;

/**
 * ``NCLocationManager`` instance, which could be used for working with the ``NCLocation``.
 * @return ``NCLocationManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get LocationManager for working with locations
 * self.locationManager = [self.sdk getLocationManager];
 * if (self.locationManager) {
 *    NSLog(@"LocationManager successfully initialized");
 * }
 * @endcode
 */
- (nullable NCLocationManager *)getLocationManager;

/**
 * ``NCNavigationManager`` instance, which could be used for working with the @see Position.
 * @param locationManager ``NCLocationManager`` instance
 * @return ``NCNavigationManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get NavigationManager for navigation
 * if (self.locationManager) {
 *    self.navigationManager = [self.sdk getNavigationManager:self.locationManager];
 *    if (self.navigationManager) {
 *        NSLog(@"NavigationManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCNavigationManager *)getNavigationManager:(nullable NCLocationManager *)locationManager;

/**
 * ``NCZoneManager`` instance, which could be used for working with zones and detecting enter and leave events. ``NCZone``
 * @param navigationManager ``NCNavigationManager`` instance
 * @return ``NCZoneManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get ZoneManager for working with zones
 * if (self.navigationManager) {
 *    self.zoneManager = [self.sdk getZoneManager:self.navigationManager];
 *    if (self.zoneManager) {
 *        NSLog(@"ZoneManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCZoneManager *)getZoneManager:(nullable NCNavigationManager *)navigationManager;

/**
 * ``NCAsyncRouteManager`` instance, which could be used for working with routing sessions. ``NCRouteSession``
 * @param locationManager ``NCLocationManager`` instance
 * @param navigationManager ``NCNavigationManager`` instance
 * @return ``NCAsyncRouteManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get AsyncRouteManager for async route operations
 * if (self.locationManager && self.navigationManager) {
 *    self.asyncRouteManager = [self.sdk getAsyncRouteManager:self.locationManager
 *                                         navigationManager:self.navigationManager];
 *    if (self.asyncRouteManager) {
 *        NSLog(@"AsyncRouteManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCAsyncRouteManager *)getAsyncRouteManager:(nullable NCLocationManager *)locationManager
                                     navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 * ``NCNotificationManager`` instance, which could be used for working with notifications when detecting beacons. ``NCNotification``
 * @param locationManager ``NCLocationManager`` instance
 * @return ``NCNotificationManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get NotificationManager for notifications
 * if (self.locationManager) {
 *    self.notificationManager = [self.sdk getNotificationManager:self.locationManager];
 *    if (self.notificationManager) {
 *        NSLog(@"NotificationManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCNotificationManager *)getNotificationManager:(nullable NCLocationManager *)locationManager;

- (nonnull NSString *)getErrorDescription:(int32_t)errorCode;

- (nullable NCLocationWindow *)createLocationWindow:(nullable NCView *)platformView;

/**
 * Returns a manager that allows to manage user storages
 * @return Storage manager instance ``NCStorageManager``
 *
 * @discussion Example:
 * @code
 * // Get StorageManager for working with storages
 * self.storageManager = [self.sdk getStorageManager];
 * if (self.storageManager) {
 *    NSLog(@"StorageManager successfully initialized");
 * }
 * @endcode
 */
- (nullable NCStorageManager *)getStorageManager;

/**
 * Create layer with the user location icon.
 */
- (nullable NCUserLocationLayer *)getUserLocationLayer:(nullable NCLocationWindow *)locationWindow;

/**
 * ``NCRouteManager`` instance, which could be used for working making routes, setting target points. ``NCRoutePath``
 * @param locationManager ``NCLocationManager`` instance
 * @param navigationManager ``NCNavigationManager`` instance
 * @return ``NCRouteManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get RouteManager for building routes
 * if (self.locationManager && self.navigationManager) {
 *    self.routeManager = [self.sdk getRouteManager:self.locationManager
 *                               navigationManager:self.navigationManager];
 *    if (self.routeManager) {
 *        NSLog(@"RouteManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCRouteManager *)getRouteManager:(nullable NCLocationManager *)locationManager
                           navigationManager:(nullable NCNavigationManager *)navigationManager;

/**
 * ``NCMeasurementManager`` instance, which could be used for managing measurement generators and handling sensor and signal measurements.
 * @param locationManager ``NCLocationManager`` instance
 * @return ``NCMeasurementManager`` instance
 *
 * @discussion Example:
 * @code
 * // Get MeasurementManager for measurements
 * if (self.locationManager) {
 *    self.measurementManager = [self.sdk getMeasurementManager:self.locationManager];
 *    if (self.measurementManager) {
 *        NSLog(@"MeasurementManager successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCMeasurementManager *)getMeasurementManager:(nullable NCLocationManager *)locationManager;

/**
 * Returns a manager that allows to manage resources
 * 1 - download and decode images
 * 2 - managing logs
 * @param locationManager ``NCLocationManager`` instance
 * @return Resource manager instance
 */
- (nullable NCResourceManager *)getResourceManager:(nullable NCLocationManager *)locationManager;

- (nullable NCLocationEditManager *)getLocationEditManager:(nullable NCLocationManager *)locationManager;

- (nullable NCBeaconProximityEstimator *)getBeaconProximityEstimator:(nullable NCLocationManager *)locationManager;

/**
 * ``NCMqttSession`` instance, which could be used for working with MQTT sessions.
 * @param navigationManager ``NCNavigationManager`` instance
 * @return ``NCMqttSession`` instance
 *
 * @discussion Example:
 * @code
 * // Get MqttSession for publishing position data via MQTT
 * if (self.navigationManager) {
 *    self.mqttSession = [self.sdk getMqttSession:self.navigationManager];
 *    if (self.mqttSession) {
 *        NSLog(@"MqttSession successfully initialized");
 *    }
 * }
 * @endcode
 */
- (nullable NCMqttSession *)getMqttSession:(nullable NCNavigationManager *)navigationManager;

/**
 * Returns a manager that allows to manage locations list
 * @return Location list manager instance ``NCLocationListManager``
 *
 * @discussion Example:
 * @code
 * // Get LocationListManager for location list operations
 * self.locationListManager = [self.sdk getLocationListManager];
 * if (self.locationListManager) {
 *    NSLog(@"LocationListManager successfully initialized");
 * }
 * @endcode
 */
- (nullable NCLocationListManager *)getLocationListManager;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
