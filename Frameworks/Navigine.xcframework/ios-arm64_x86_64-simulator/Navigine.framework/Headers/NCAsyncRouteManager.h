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
 * @brief Method is used to create routing session
 * @param wayPoint destination point.
 * @param routeOptions params of @see RouteSession "RouteSession".
 * @return @see RouteSession "RouteSession" instance.
 */
- (nullable NCRouteSession *)createRouteSession:(nonnull NCLocationPoint *)wayPoint
                                   routeOptions:(nonnull NCRouteOptions *)routeOptions;

/**
 * @brief Method is used to cancel routing session
 * @param session @see RouteSession "RouteSession" object to cancel.
 */
- (void)cancelRouteSession:(nullable NCRouteSession *)session;

@end
