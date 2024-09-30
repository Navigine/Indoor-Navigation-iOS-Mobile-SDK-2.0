#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteOptions.h"
#import <Foundation/Foundation.h>
@class NCRouteSession;


/** Class is used to manage routing sessions */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCAsyncRouteManager : NSObject

/**
 * Method is used to create routing session
 * @param wayPoint - destination point
 * @param routeOptions - params of routing session (@see RouteSession class)
 */
- (nullable NCRouteSession *)createRouteSession:(nonnull NCLocationPoint *)wayPoint
                                   routeOptions:(nonnull NCRouteOptions *)routeOptions;

/** Method is used to cancel routing session */
- (void)cancelRouteSession:(nullable NCRouteSession *)session;

@end
