#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteOptions.h"
#import <Foundation/Foundation.h>
@class NCRouteSession;


/**
 * @file NCAsyncRouteManager.h
 * @brief @copybrief NCAsyncRouteManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for managing @see RouteSession "RouteSession"s
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCAsyncRouteManager : NSObject

/**
 * @brief Method is used to create routing session with 'default' graph tag
 * @param wayPoint destination point.
 * @param routeOptions params of @see RouteSession "RouteSession".
 * @return @see RouteSession "RouteSession" instance.
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_AsyncRouteManager_createRouteSession
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_AsyncRouteManager_createRouteSession
 *
 *
 */
- (nullable NCRouteSession *)createRouteSession:(nonnull NCLocationPoint *)wayPoint
                                   routeOptions:(nonnull NCRouteOptions *)routeOptions;

/**
 * @brief Creates a routing session using a specific graph tag.
 *
 * Initializes a @see RouteSession "RouteSession" for building a route to the given waypoint using the specified routing options and graph tag.
 * If the specified tag is not present in the current location (i.e., the corresponding sublocation graph is not yet available),
 * the returned @see RouteSession "RouteSession" will produce an empty route and will not trigger any listeners until the location data
 * for that tag becomes available (e.g., after a location update).
 *
 * @param wayPoint Destination point for the route.
 * @param routeOptions Routing parameters @see RouteSession "RouteSession" used to build the route.
 * @param tag Graph tag identifying which sublocation graph to use. @see Sublocation "Sublocation"
 * @return A RouteSession instance, which may initially be empty if the tag is not available. @see RouteSession "RouteSession"
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_AsyncRouteManager_createRouteSessionWithTag
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_AsyncRouteManager_createRouteSessionWithTag
 *
 *
 */
- (nullable NCRouteSession *)createRouteSessionWithTag:(nonnull NCLocationPoint *)wayPoint
                                          routeOptions:(nonnull NCRouteOptions *)routeOptions
                                                   tag:(nonnull NSString *)tag;

/**
 * @brief Method is used to cancel routing session
 * @param session @see RouteSession "RouteSession" object to cancel.
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_AsyncRouteManager_cancelRouteSession
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_AsyncRouteManager_cancelRouteSession
 *
 *
 */
- (void)cancelRouteSession:(nullable NCRouteSession *)session;

@end
