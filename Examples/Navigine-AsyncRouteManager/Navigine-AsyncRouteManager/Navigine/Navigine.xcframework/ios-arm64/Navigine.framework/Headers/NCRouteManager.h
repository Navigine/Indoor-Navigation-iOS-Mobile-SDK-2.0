#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;
@protocol NCRouteListener;


/** Class is used to build a route between points and subscribe for route updates */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteManager : NSObject

/**
 *
 * Method is used to build a route between points
 * @param from - starting point (@see LocationPoint class).
 * @param to - destination point (@see LocationPoint class).
 * @return RoutePath from starting to destination point (@see RoutePath).
 *
 */
- (nullable NCRoutePath *)makeRoute:(nonnull NCLocationPoint *)from
                                 to:(nonnull NCLocationPoint *)to;

/**
 *
 * Method is used to set target point.
 * Navigation manager will build new route path (@see RoutePath) each navigation tick.
 * Results will be available in RouteListener (@see RouteListener).
 * @param target - finish point (@see LocationPoint class).
 *
 */
- (void)setTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * Method is used to add one more target point.
 * Navigation manager will build new route path (@see RoutePath) to each target each navigation tick.
 * Results will be available in RouteListener (@see RouteListener).
 * @param target - finish point (@see LocationPoint class).
 *
 */
- (void)addTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * Method is used to cancel all routing processes.
 *
 */
- (void)cancelTarget;

/** @internal */
- (void)clearTargets;

/**
 *
 * Method is used to select graph tag (Default: "default").
 *
 */
- (void)setGraphTag:(nonnull NSString *)tag;

/**
 *
 * Method is used to get current graph tag (Default: "default").
 *
 */
- (nonnull NSString *)getGraphTag;

/**
 *
 * Method is used to get all graph tags,
 *
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 *
 * Method is used to add listener to handle new routes (@see RouteListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addRouteListener:(nullable id<NCRouteListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeRouteListener:(nullable id<NCRouteListener>)listener;

@end
