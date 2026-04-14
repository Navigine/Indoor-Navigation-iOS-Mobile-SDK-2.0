#import "NCExport.h"
#import "NCRouteNode.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;


/**
 * @file NCRoutePath.h
 * @brief @copybrief NCRoutePath
 */
/**
 *
 * @brief Class is used for storing the route path between two points in location.
 *
 * Referenced from: @see AsyncRouteListener "AsyncRouteListener", @see AsyncRouteManager "AsyncRouteManager", @see Location "Location",
 * @see RouteListener "RouteListener", @see RouteManager "RouteManager"
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRoutePath : NSObject

/**
 * @brief Returns the leading segment of the route up to advance meters.
 * @param advance distance along route (meters).
 * @return route head segment.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RoutePath_head
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RoutePath_head
 *
 *
 */
- (nullable NCRoutePath *)head:(float)advance;

/**
 * @brief Returns the route segment after advance meters.
 * @param advance distance along route (meters).
 * @return route tail segment.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RoutePath_tail
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RoutePath_tail
 *
 *
 */
- (nullable NCRoutePath *)tail:(float)advance;

/**
 * @brief Returns route nodes with points and events.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RoutePath_getNodes
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RoutePath_getNodes
 *
 *
 */
- (nonnull NSArray<NCRouteNode *> *)nodes;

/**
 * @brief Total route length in meters.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RoutePath_getLength
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RoutePath_getLength
 *
 *
 */
@property (nonatomic, readonly) float length;

/**
 * @brief Total route weight/cost.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RoutePath_getWeight
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RoutePath_getWeight
 *
 *
 */
@property (nonatomic, readonly) float weight;

@end
