#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteEvent.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * @file NCRoutePath.h
 * @brief @copybrief NCRoutePath
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief class is used for storing the route path between the two points on the location.
 *
 * Referenced from: @see AsyncRouteListener "AsyncRouteListener", @see AsyncRouteManager "AsyncRouteManager", @see Location "Location",
 * @see RouteListener "RouteListener", @see RouteManager "RouteManager"
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRoutePath : NSObject

/**
 *
 * @brief Returns the leading segment of the route.
 *
 * Returns the portion of the route from the start up to the specified advance distance along the route.
 * If advance exceeds the total route length, the entire route is returned.
 *
 * @param advance Distance along the route (in meters).
 * @return The covered (passed) segment of the route (from start to advance), or nil if the segment is empty.
 *
 */
- (nullable NCRoutePath *)head:(float)advance;

/**
 *
 * @brief Returns the remaining segment of the route.
 *
 * Returns the portion of the route starting from the specified advance distance to the end of the route.
 * If advance is less than or equal to zero, the entire route is returned.
 *
 * @param advance Distance along the route (in meters).
 * @return The remaining segment of the route (from advance to end), or nil if the segment is empty.
 *
 */
- (nullable NCRoutePath *)tail:(float)advance;

/**
 * @brief Total lenth of the route path in meters.
 */
@property (nonatomic, readonly) float length;

/**
 * @brief List of consecutive incoming events @see RouteEvent "RouteEvent".
 */
@property (nonatomic, nonnull, readonly) NSArray<NCRouteEvent *> * events;

/**
 * @brief List of consecutive points. @see LocationPoint.
 *
 * @note points could be on different sublocations if target sublocation is different from the starting one
 */
@property (nonatomic, nonnull, readonly) NSArray<NCLocationPoint *> * points;

@end
