#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteStatus.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * Class provides a callback to be invoked when ``NCRouteSession``
 * handle changed/advanced events.
 * Referenced from ``NCAsyncRouteManager`` ``NCRouteSession``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCAsyncRouteListener <NSObject>

/**
 * Called when new route was built or
 * old route was rebuilt after missing previous one.
 * @param status ``NCRouteStatus`` indicating the current router state
 * @param currentPath ``NCRoutePath`` from current position to destination point (null if status is not new_route)
 *
 * @discussion Example:
 * @code
 * - (void)onRouteChanged:(NCRouteStatus)status currentPath:(NCRoutePath *)currentPath {
 *    NSLog(@"Route changed with status: %@", @(status));
 *    if (status == NCRouteStatusNewRoute && currentPath != nil) {
 *        [self demonstrateRoutePathUsage:currentPath];
 *    } else {
 *        NSLog(@"Route not ready, status: %@", @(status));
 *    }
 * }
 * @endcode
 */
- (void)onRouteChanged:(NCRouteStatus)status
           currentPath:(nullable NCRoutePath *)currentPath;

/**
 * Called when user has progressed along the route
 * that was built in the method `onRouteChanged`
 * @param distance distance from the beginning or the route (unit meters)
 * @param point current location point on the route
 *
 * @discussion Example:
 * @code
 * - (void)onRouteAdvanced:(float)distance point:(NCLocationPoint *)point {
 *    NSLog(@"Route advanced: %f meters", distance);
 *    [self demonstrateLocationPointUsage:point];
 * }
 * @endcode
 */
- (void)onRouteAdvanced:(float)distance
                  point:(nonnull NCLocationPoint *)point;

@end
