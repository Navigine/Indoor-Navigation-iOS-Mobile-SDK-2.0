#import <Foundation/Foundation.h>
@protocol NCZoneListener;


@interface NCZoneManager : NSObject

- (void)addZoneListener:(nullable id<NCZoneListener>)listener;

- (void)removeZoneListener:(nullable id<NCZoneListener>)listener;

@end
