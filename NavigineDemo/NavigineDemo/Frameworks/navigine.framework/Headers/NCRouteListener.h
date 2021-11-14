#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


NAVIGINE_EXPORT
@protocol NCRouteListener

- (void)onPathsUpdated:(nonnull NSArray<NCRoutePath *> *)paths;

@end
