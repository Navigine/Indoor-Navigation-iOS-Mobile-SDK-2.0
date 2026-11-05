#import <Foundation/Foundation.h>

/**
 * Enum describing possible router states.
 * Referenced from ``NCAsyncRouteListener``.
 *
 * @discussion Example:
 * @code
 * // Demonstrate all RouteStatus values
 * NSLog(@"Available RouteStatus values:");
 * NSArray *allStatuses = @[@(NCRouteStatusMissingGraph), @(NCRouteStatusMissingPosition), @(NCRouteStatusMissingRoute), @(NCRouteStatusMissingProjection), @(NCRouteStatusNewRoute)];
 * for (NSNumber *statusNumber in allStatuses) {
 *    NCRouteStatus status = [statusNumber integerValue];
 *    NSLog(@"  - %@: %@", @(status), @(status));
 * }
 * // Demonstrate status checking
 * NCRouteStatus testStatus = NCRouteStatusNewRoute;
 * switch (testStatus) {
 *    case NCRouteStatusNewRoute:
 *        NSLog(@"Router is ready for navigation");
 *        break;
 *    case NCRouteStatusMissingGraph:
 *        NSLog(@"Router is missing the route graph");
 *        break;
 *    case NCRouteStatusMissingPosition:
 *        NSLog(@"Router is missing the current position");
 *        break;
 *    case NCRouteStatusMissingProjection:
 *        NSLog(@"Current position is off the route graph");
 *        break;
 *    case NCRouteStatusMissingRoute:
 *        NSLog(@"Router unable to find the route to the destination point");
 *        break;
 * }
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCRouteStatus)
{
    /**
     * Router is missing the route graph.
     */
    NCRouteStatusMissingGraph,
    /**
     * Router is missing the current position.
     */
    NCRouteStatusMissingPosition,
    /**
     * Router unable to find the route to the destination point.
     */
    NCRouteStatusMissingRoute,
    /**
     * Current position is off the route graph.
     */
    NCRouteStatusMissingProjection,
    /**
     * Router is ready and has a valid route.
     */
    NCRouteStatusNewRoute,
};
