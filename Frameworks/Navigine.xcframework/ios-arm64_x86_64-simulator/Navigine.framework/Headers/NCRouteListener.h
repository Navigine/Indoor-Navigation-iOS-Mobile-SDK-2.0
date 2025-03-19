#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * @file NCRouteListener.h
 * @brief @copybrief NCRouteListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see RouteManager "RouteManager"
 * updates routes to the target point or from point to point.
 *
 * Referenced from @see RouteManager "RouteManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteListener <NSObject>

/**
 *
 * @brief Called when new route has been calculated
 * @param paths calculated list of @see RoutePath "RoutePath"s to added targets.
 *
 */
- (void)onPathsUpdated:(nonnull NSArray<NCRoutePath *> *)paths;

@end
