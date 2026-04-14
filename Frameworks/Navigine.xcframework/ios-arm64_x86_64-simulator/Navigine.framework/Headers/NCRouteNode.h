#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteEvent.h"
#import <Foundation/Foundation.h>

/**
 * @file NCRouteNode.h
 * @brief @copybrief NCRouteNode
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Class describing one node of the evaluated route.
 *
 * Referenced from @see RoutePath "RoutePath".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteNode : NSObject

/** 
 * @brief Default constructor for class NCRouteNode 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCLocationPoint *)point
                               weight:(float)weight
                             distance:(float)distance
                               events:(nonnull NSArray<NCRouteEvent *> *)events;

/** 
 * @brief Factory method for class NCRouteNode 
 */
+ (nonnull instancetype)routeNodeWithPoint:(nonnull NCLocationPoint *)point
                                    weight:(float)weight
                                  distance:(float)distance
                                    events:(nonnull NSArray<NCRouteEvent *> *)events;

/**
 * @brief Location point of this node.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteNode_getPoint
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteNode_getPoint
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCLocationPoint * point;

/**
 * @brief Route cost/weight value at this node.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteNode_getWeight
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteNode_getWeight
 *
 *
 */
@property (nonatomic, readonly) float weight;

/**
 * @brief Distance from route start to this node (meters).
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteNode_getDistance
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteNode_getDistance
 *
 *
 */
@property (nonatomic, readonly) float distance;

/**
 * @brief Events associated with this node.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteNode_getEvents
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteNode_getEvents
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NCRouteEvent *> * events;

@end
