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
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_makeRoute
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_makeRoute
 *
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
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_makeRoutes
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_makeRoutes
 *
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
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_setTarget
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_setTarget
 *
 *
 */
- (void)setTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * @brief Method is used to add target point in your location.
 * Through @see RouteListener "RouteListener" you will be notified about new paths to target point.
 * @param target finish @see LocationPoint "LocationPoint".
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_addTarget
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_addTarget
 *
 *
 */
- (void)addTarget:(nonnull NCLocationPoint *)target;

/**
 *
 * @brief Method is used for removing current target points to where the routes were built.
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_cancelTarget
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_cancelTarget
 *
 *
 */
- (void)cancelTarget;

/**
 *
 * @brief Method is used for removing all target points to where the routes were built.
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_clearTargets
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_clearTargets
 *
 *
 */
- (void)clearTargets;

/**
 *
 * @brief Method is used to select graph tag (Default: "default").
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_setGraphTag
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_setGraphTag
 *
 *
 */
- (void)setGraphTag:(nonnull NSString *)tag;

/**
 *
 * @brief Method is used to get current graph tag (Default: "default").
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_getGraphTag
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_getGraphTag
 *
 *
 */
- (nonnull NSString *)getGraphTag;

/**
 *
 * @brief Method is used to get all graph tags,
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_getGraphTags
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_getGraphTags
 *
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
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_addRouteListener
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_addRouteListener
 *
 *
 */
- (void)addRouteListener:(nullable id<NCRouteListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see RouteListener "RouteListener" class element.
 * @param listener Сorresponding @see RouteListener "RouteListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteManager_removeRouteListener
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteManager_removeRouteListener
 *
 *
 */
- (void)removeRouteListener:(nullable id<NCRouteListener>)listener;

@end
