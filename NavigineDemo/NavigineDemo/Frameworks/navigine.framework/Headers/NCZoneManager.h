#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCZoneListener;


NAVIGINE_EXPORT
@interface NCZoneManager : NSObject

- (void)addZoneListener:(nullable id<NCZoneListener>)listener;

- (void)removeZoneListener:(nullable id<NCZoneListener>)listener;

@end
