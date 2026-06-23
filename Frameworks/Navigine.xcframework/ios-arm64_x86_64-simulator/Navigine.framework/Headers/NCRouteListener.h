#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * Class provides a callback to be invoked when ``NCRouteManager``
 * updates routes to the target point or from point to point.
 * Referenced from ``NCRouteManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteListener <NSObject>

/**
 * Called when new route has been calculated
 * @param paths calculated list of ``NCRoutePath``s to added targets.
 *
 * @discussion Example:
 * @code
 * - (void)onPathsUpdated:(NSArray<NCRoutePath *> *)paths {
 *    NSLog(@"Routes updated successfully");
 *    [self demonstrateRoutePathUsage:paths];
 * }
 * @endcode
 */
- (void)onPathsUpdated:(nonnull NSArray<NCRoutePath *> *)paths;

@end
