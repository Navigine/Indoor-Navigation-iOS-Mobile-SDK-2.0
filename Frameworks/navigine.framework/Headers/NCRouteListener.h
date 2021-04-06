#import <Foundation/Foundation.h>
@class NCRoutePath;


@protocol NCRouteListener

- (void)onPathsUpdated:(nonnull NSArray<NCRoutePath *> *)paths;

@end
