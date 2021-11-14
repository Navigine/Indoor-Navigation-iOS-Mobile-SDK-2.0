#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


NAVIGINE_EXPORT
@protocol NCAsyncRouteListener

- (void)onRouteChanged:(nullable NCRoutePath *)currentPath
          pendingPaths:(nonnull NSArray<NCRoutePath *> *)pendingPaths;

- (void)onRouteAdvanced:(float)distance
                  point:(nonnull NCLocationPoint *)point;

@end
