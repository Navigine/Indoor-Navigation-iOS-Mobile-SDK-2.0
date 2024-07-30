#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteEvent.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 *
 * Class describing path calculated by SDK. It could be
 * 1 - point to point request via `makeRoute` function of RouteManager (@see RouteManager)
 * 2 - path from current user position to destination point (@see RouteManager and @RouteSession)
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRoutePath : NSObject

/**
 *
 * Method is used to split route path by distance
 * @param advance - distance on the route from the start.
 * @return - pair of splitted route paths.
 *
 */
- (nonnull NSArray<NCRoutePath *> *)split:(float)advance;

/** Total lenth of the route path in meters. */
@property (nonatomic, readonly) float length;

/** List of consecutive incoming events (@see RouteEvent). */
@property (nonatomic, nonnull, readonly) NSArray<NCRouteEvent *> * events;

/**
 * List of consecutive points. (@see LocationPoint).
 * NOTE! points could be on different sublocations if target sublocation is different from the starting one
 */
@property (nonatomic, nonnull, readonly) NSArray<NCLocationPoint *> * points;

@end
