#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@protocol NCAsyncRouteListener;


NAVIGINE_EXPORT
@interface NCRouteSession : NSObject

- (void)addRouteListener:(nullable id<NCAsyncRouteListener>)listener;

- (void)removeRouteListener:(nullable id<NCAsyncRouteListener>)listener;

- (void)checkIn:(nonnull NCLocationPoint *)point;

@end
