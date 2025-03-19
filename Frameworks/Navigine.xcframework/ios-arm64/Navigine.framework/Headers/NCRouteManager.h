#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;
@protocol NCRouteListener;


/**
 * @file NCRouteManager.h
 * @brief @copybrief NCRouteManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for evaluating @see RoutePath "RoutePath" from point to point.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteManager : NSObject

/**
 *
 * @brief Method is used to build a route between points
 * about evaluated @see RoutePath "RoutePath" from your position to target point.
 * @param from starting @see LocationPoint "LocationPoint".
 * @param to destination @see LocationPoint "LocationPoint".
 * @return @see RoutePath "RoutePath" from starting to destination point.
 *
 */
- (nullable NCRoutePath *)makeRoute:(nonnull NCLocationPoint *)from
                                 to:(nonnull NCLocationPoint *)to;

/**
 *
 * @brief Method is used to build a route between the starting point and several destination points
 * @param from starting @see LocationPoint "LocationPoint".
 * @param to destination list of @see LocationPoint "LocationPoint"s.
 * @return vector of @see RoutePath "RoutePath"s from starting to destination point.
 *
 */
- (nonnull NSArray<NCRoutePath *> *)makeRoutes:(nonnull NCLocationPoint *)from
                                            to:(nonnull NSArray<NCLocationPoint *> *)to;

/**
 *
 * @brief Method is used to set target point in your location.
 * Through @see RouteListener "RouteListener" you will be notified about new paths to target point.
 * @param target finish @see LocationPoint "LocationPoint".
 *
 */
- (void)setTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * @brief Method is used to add target point in your location.
 * Through @see RouteListener "RouteListener" you will be notified about new paths to target point.
 * @param target finish @see LocationPoint "LocationPoint".
 *
 */
- (void)addTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * @brief Method is used for removing current target points to where the routes were built.
 *
 */
- (void)cancelTarget;

/**
 *
 * @brief Method is used for removing all target points to where the routes were built.
 *
 */
- (void)clearTargets;

/**
 *
 * @brief Method is used to select graph tag (Default: "default").
 *
 */
- (void)setGraphTag:(nonnull NSString *)tag;

/**
 *
 * @brief Method is used to get current graph tag (Default: "default").
 *
 */
- (nonnull NSString *)getGraphTag;

/**
 *
 * @brief Method is used to get all graph tags,
 *
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 *
 * @brief Method is used to add @see RouteListener "RouteListener" class element
 * which will notify about evaluated route path from your position to target point.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see RouteListener "RouteListener" class.
 *
 */
- (void)addRouteListener:(nullable id<NCRouteListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see RouteListener "RouteListener" class element.
 * @param listener Сorresponding @see RouteListener "RouteListener" class to remove.
 *
 */
- (void)removeRouteListener:(nullable id<NCRouteListener>)listener;

@end
