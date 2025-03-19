#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * @file NCAsyncRouteListener.h
 * @brief @copybrief NCAsyncRouteListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see RouteSession "RouteSession"
 * handle changed/advanced events.
 *
 * Referenced from @see AsyncRouteManager "AsyncRouteManager" @see RouteSession "RouteSession".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCAsyncRouteListener <NSObject>

/**
 * @brief Called when new route was built or
 *     old route was rebuilt after missing previouse one.
 *
 * @param currentPath @see RoutePath "RoutePath" from current postion to destination point
 *
 */
- (void)onRouteChanged:(nullable NCRoutePath *)currentPath;

/**
 * @brief Called when user has progressed along the route
 *     that was built in the method `onRouteChanged`
 *
 * @param distance distance from the beginning or the route (unit meters)
 * @param point current location point on the route
 *
 */
- (void)onRouteAdvanced:(float)distance
                  point:(nonnull NCLocationPoint *)point;

@end
