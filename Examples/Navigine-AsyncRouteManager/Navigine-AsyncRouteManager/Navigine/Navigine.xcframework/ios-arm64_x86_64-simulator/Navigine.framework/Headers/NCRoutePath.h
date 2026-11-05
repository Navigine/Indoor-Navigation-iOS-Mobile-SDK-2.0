#import "NCExport.h"
#import "NCRouteNode.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * Class is used for storing the route path between two points in location.
 * Referenced from: ``NCAsyncRouteListener``, ``NCAsyncRouteManager``, ``NCLocation``,
 * ``NCRouteListener``, ``NCRouteManager``
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRoutePath : NSObject

/**
 * Returns the leading segment of the route up to advance meters.
 * @param advance distance along route (meters).
 * @return route head segment.
 *
 * @discussion Example:
 * @code
 * // Get head of route (first 10 meters)
 * NCRoutePath *headPath = [path head:10.0];
 * if (headPath != nil) {
 *    NSLog(@"Head path length: %f meters", [headPath getLength]);
 * }
 * @endcode
 */
- (nullable NCRoutePath *)head:(float)advance;

/**
 * Returns the route segment after advance meters.
 * @param advance distance along route (meters).
 * @return route tail segment.
 *
 * @discussion Example:
 * @code
 * // Get tail of route (remaining after 10 meters)
 * NCRoutePath *tailPath = [path tail:10.0];
 * if (tailPath != nil) {
 *    NSLog(@"Tail path length: %f meters", [tailPath getLength]);
 * }
 * @endcode
 */
- (nullable NCRoutePath *)tail:(float)advance;

/**
 * Returns route nodes with points and events.
 *
 * @discussion Example:
 * @code
 * // Get route nodes
 * NSArray<NCRouteNode *> *nodes = [path getNodes];
 * NSLog(@"Route has %lu nodes", (unsigned long)nodes.count);
 * for (int j = 0; j < nodes.count; j++) {
 *    [self demonstrateRouteNodeUsage:nodes[j]];
 * }
 * @endcode
 */
- (nonnull NSArray<NCRouteNode *> *)nodes;

/**
 * Total route length in meters.
 *
 * @discussion Example:
 * @code
 * // Get route length
 * double length = [path getLength];
 * NSLog(@"Route length: %f meters", length);
 * @endcode
 */
@property (nonatomic, readonly) float length;

/**
 * Total route weight/cost.
 *
 * @discussion Example:
 * @code
 * // Get total route weight
 * double weight = [path getWeight];
 * NSLog(@"Route weight: %f", weight);
 * @endcode
 */
@property (nonatomic, readonly) float weight;

@end
