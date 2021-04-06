#import <Foundation/Foundation.h>
@protocol NCLocationListListener;


@interface NCLocationListManager : NSObject

- (void)addLocationListListener:(nullable id<NCLocationListListener>)listener;

- (void)removeLocationListListener:(nullable id<NCLocationListListener>)listener;

- (void)updateLocationList;

@end
