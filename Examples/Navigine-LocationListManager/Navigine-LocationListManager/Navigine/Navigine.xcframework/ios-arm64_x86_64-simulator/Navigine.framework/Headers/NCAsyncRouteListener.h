#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * Class is used to handle events coming from routing session (@see RouteSession)
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCAsyncRouteListener <NSObject>

/**
 * @method onRouteChanged - called when new route was built or
 *     old route was rebuilt after missing previouse one.
 *
 * @parameter currentPath - path from current postion to destination point
 */
- (void)onRouteChanged:(nullable NCRoutePath *)currentPath;

/**
 * @method onRouteAdvanced - called when user has progressed along the route
 *     that was built in the method `onRouteChanged`
 *
 * @parameter distance - distance from the beginning or the route (unit meters)
 * @parameter point - current location point on the route
 */
- (void)onRouteAdvanced:(float)distance
                  point:(nonnull NCLocationPoint *)point;

@end
