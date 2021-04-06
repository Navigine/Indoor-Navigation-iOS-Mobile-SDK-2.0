#import <Foundation/Foundation.h>
@protocol NCLocationListener;


@interface NCLocationManager : NSObject

- (void)addLocationListener:(nullable id<NCLocationListener>)listener;

- (void)removeLocationListener:(nullable id<NCLocationListener>)listener;

- (void)setLocation:(int32_t)locationId;

- (int32_t)getLocationId;

@end
