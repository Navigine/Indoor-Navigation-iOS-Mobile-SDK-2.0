#import <Foundation/Foundation.h>
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


@interface NCNavigineSdk : NSObject

+ (void)setUserHash:(nonnull NSString *)userHash;

+ (void)setServer:(nonnull NSString *)server;

+ (nullable NCNavigineSdk *)getInstance;

- (nullable NCLocationManager *)getLocationManager;

- (nullable NCNavigationManager *)getNavigationManager:(nullable NCLocationManager *)locationManager;

- (nullable NCZoneManager *)getZoneManager:(nullable NCLocationManager *)locationManager
                         navigationManager:(nullable NCNavigationManager *)navigationManager;

- (nullable NCRouteManager *)getRouteManager:(nullable NCLocationManager *)locationManager
                           navigationManager:(nullable NCNavigationManager *)navigationManager;

- (nullable NCResourceManager *)getResourceManager:(nullable NCLocationManager *)locationManager;

- (nullable NCNotificationManager *)getNotificationManager:(nullable NCLocationManager *)locationManager;

- (nullable NCLocationEditManager *)getLocationEditManager:(nullable NCLocationManager *)locationManager;

- (nullable NCMeasurementManager *)getMeasurementManager;

- (nonnull NSString *)getErrorDescription:(int32_t)errorCode;

- (nullable NCLocationListManager *)getLocationListManager;

@end
