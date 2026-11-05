#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;
@protocol NCRouteListener;


/**
 * Class is used for evaluating ``NCRoutePath`` from point to point.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteManager : NSObject

/**
 * Method is used to build a route between points
 * about evaluated ``NCRoutePath`` from your position to target point.
 * @param from starting ``NCLocationPoint``.
 * @param to destination ``NCLocationPoint``.
 * @return ``NCRoutePath`` from starting to destination point.
 *
 * @discussion Example:
 * @code
 * // Make route from point to point
 * NCRoutePath *routePath = [self.routeManager makeRoute:startLocationPoint to:endLocationPoint];
 * NSLog(@"Route created with length: %f meters", [routePath getLength]);
 * @endcode
 */
- (nullable NCRoutePath *)makeRoute:(nonnull NCLocationPoint *)from
                                 to:(nonnull NCLocationPoint *)to;

/**
 * Method is used to build a route between the starting point and several destination points
 * @param from starting ``NCLocationPoint``.
 * @param to destination list of ``NCLocationPoint``s.
 * @return vector of ``NCRoutePath``s from starting to destination point.
 *
 * @discussion Example:
 * @code
 * // Make routes to multiple destinations
 * NSArray<NCLocationPoint *> *destinations = @[
 *    [[NCLocationPoint alloc] initWithPoint:[[NCPoint alloc] initWithX:30.0 y:40.0] locationId:12345 sublocationId:1],
 *    [[NCLocationPoint alloc] initWithPoint:[[NCPoint alloc] initWithX:70.0 y:80.0] locationId:12345 sublocationId:1]
 * ];
 * NSArray<NCRoutePath *> *routePaths = [self.routeManager makeRoutes:startLocationPoint to:destinations];
 * NSLog(@"Created %lu routes", (unsigned long)routePaths.count);
 * @endcode
 */
- (nonnull NSArray<NCRoutePath *> *)makeRoutes:(nonnull NCLocationPoint *)from
                                            to:(nonnull NSArray<NCLocationPoint *> *)to;

/**
 * Method is used to set target point in your location.
 * Through ``NCRouteListener`` you will be notified about new paths to target point.
 * @param target finish ``NCLocationPoint``.
 *
 * @discussion Example:
 * @code
 * // Set target point
 * [self.routeManager setTarget:endLocationPoint];
 * @endcode
 */
- (void)setTarget:(nonnull NCLocationPoint *)target;

/**
 * Method is used to add target point in your location.
 * Through ``NCRouteListener`` you will be notified about new paths to target point.
 * @param target finish ``NCLocationPoint``.
 *
 * @discussion Example:
 * @code
 * // Add additional target point
 * NCLocationPoint *additionalTarget = [[NCLocationPoint alloc] initWithPoint:[[NCPoint alloc] initWithX:90.0 y:100.0] locationId:12345 sublocationId:1];
 * [self.routeManager addTarget:additionalTarget];
 * @endcode
 */
- (void)addTarget:(nonnull NCLocationPoint *)target;

/**
 * Method is used for removing current target points to where the routes were built.
 *
 * @discussion Example:
 * @code
 * // Cancel current target
 * [self.routeManager cancelTarget];
 * @endcode
 */
- (void)cancelTarget;

/**
 * Method is used for removing all target points to where the routes were built.
 *
 * @discussion Example:
 * @code
 * // Clear all targets
 * [self.routeManager clearTargets];
 * @endcode
 */
- (void)clearTargets;

/**
 * Method is used to select graph tag (Default: "default").
 *
 * @discussion Example:
 * @code
 * // Set graph tag
 * [self.routeManager setGraphTag:@"main"];
 * @endcode
 */
- (void)setGraphTag:(nonnull NSString *)tag;

/**
 * Method is used to get current graph tag (Default: "default").
 *
 * @discussion Example:
 * @code
 * // Get current graph tag
 * NSString *currentGraphTag = [self.routeManager getGraphTag];
 * NSLog(@"Current graph tag: %@", currentGraphTag);
 * @endcode
 */
- (nonnull NSString *)getGraphTag;

/**
 * Method is used to get all graph tags,
 *
 * @discussion Example:
 * @code
 * // Get all graph tags
 * NSArray<NSString *> *graphTags = [self.routeManager getGraphTags];
 * NSLog(@"Available graph tags: %@", graphTags);
 * @endcode
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 * Method is used to add ``NCRouteListener`` class element
 * which will notify about evaluated route path from your position to target point.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCRouteListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add route listener
 * [self.routeManager addRouteListener:self];
 * @endcode
 */
- (void)addRouteListener:(nullable id<NCRouteListener>)listener;

/**
 * Method is used for removing previously added ``NCRouteListener`` class element.
 * @param listener Corresponding ``NCRouteListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove route listener
 * [self.routeManager removeRouteListener:self];
 * @endcode
 */
- (void)removeRouteListener:(nullable id<NCRouteListener>)listener;

@end
