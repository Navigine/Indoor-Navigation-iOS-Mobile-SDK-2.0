#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * Class is used to handle events coming from RouteManager (@see RouteManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteListener <NSObject>

/**
 *
 * @method onPathsUpdated - called when new route has been calculated
 * @parameter paths - calculated list of paths to added targets (@see RoutePath).
 *
 */
- (void)onPathsUpdated:(nonnull NSArray<NCRoutePath *> *)paths;

@end
