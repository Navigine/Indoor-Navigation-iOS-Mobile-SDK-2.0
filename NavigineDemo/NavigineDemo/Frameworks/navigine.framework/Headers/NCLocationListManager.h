#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListListener;


NAVIGINE_EXPORT
@interface NCLocationListManager : NSObject

- (void)addLocationListListener:(nullable id<NCLocationListListener>)listener;

- (void)removeLocationListListener:(nullable id<NCLocationListListener>)listener;

- (void)updateLocationList;

- (nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)getLocationList;

@end
