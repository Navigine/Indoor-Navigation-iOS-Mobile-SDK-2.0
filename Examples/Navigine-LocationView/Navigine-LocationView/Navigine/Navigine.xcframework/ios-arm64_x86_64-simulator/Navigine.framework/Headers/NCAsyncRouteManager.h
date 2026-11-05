#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteOptions.h"
#import <Foundation/Foundation.h>
@class NCRouteSession;


/**
 * Class is used for managing ``NCRouteSession``s
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCAsyncRouteManager : NSObject

/**
 * Method is used to create routing session with 'default' graph tag
 * @param wayPoint destination point.
 * @param routeOptions params of ``NCRouteSession``.
 * @return ``NCRouteSession`` instance.
 *
 * @discussion Example:
 * @code
 * // Create route session with default graph tag
 * NCRouteSession *session = [self.asyncRouteManager createRouteSession:destinationLocationPoint routeOptions:routeOptions];
 * NSLog(@"Created route session with default graph tag");
 * @endcode
 */
- (nullable NCRouteSession *)createRouteSession:(nonnull NCLocationPoint *)wayPoint
                                   routeOptions:(nonnull NCRouteOptions *)routeOptions;

/**
 * Creates a routing session using a specific graph tag.
 * Initializes a ``NCRouteSession`` for building a route to the given waypoint using the specified routing options and graph tag.
 * If the specified tag is not present in the current location (i.e., the corresponding sublocation graph is not yet available),
 * the returned ``NCRouteSession`` will produce an empty route and will not trigger any listeners until the location data
 * for that tag becomes available (e.g., after a location update).
 * @param wayPoint Destination point for the route.
 * @param routeOptions Routing parameters ``NCRouteSession`` used to build the route.
 * @param tag Graph tag identifying which sublocation graph to use. ``NCSublocation``
 * @return A RouteSession instance, which may initially be empty if the tag is not available. ``NCRouteSession``
 *
 * @discussion Example:
 * @code
 * // Create route session with specific graph tag
 * NCRouteSession *sessionWithTag = [self.asyncRouteManager createRouteSessionWithTag:destinationLocationPoint routeOptions:routeOptions tag:@"main"];
 * NSLog(@"Created route session with 'main' graph tag");
 * @endcode
 */
- (nullable NCRouteSession *)createRouteSessionWithTag:(nonnull NCLocationPoint *)wayPoint
                                          routeOptions:(nonnull NCRouteOptions *)routeOptions
                                                   tag:(nonnull NSString *)tag;

/**
 * Method is used to cancel routing session
 * @param session ``NCRouteSession`` object to cancel.
 *
 * @discussion Example:
 * @code
 * // Cancel route session
 * [self.asyncRouteManager cancelRouteSession:sessions[i]];
 * NSLog(@"Cancelled session %d", i + 1);
 * @endcode
 */
- (void)cancelRouteSession:(nullable NCRouteSession *)session;

@end
