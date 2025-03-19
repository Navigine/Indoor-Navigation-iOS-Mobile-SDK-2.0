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
 * @brief Method is used to split route path by distance
 * @param advance distance on the route from the start.
 * @return pair of splitted route paths.
 *
 */
- (nonnull NSArray<NCRoutePath *> *)split:(float)advance;

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
