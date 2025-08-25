#import "NCExport.h"
#import "NCRouteEventType.h"
#import <Foundation/Foundation.h>

/**
 * @file NCRouteEvent.h
 * @brief @copybrief NCRouteEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class is used for storing the route path events.
 *
 * Referenced from: @see RoutePath "RoutePath".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteEvent : NSObject

/** 
 * @brief Default constructor for class NCRouteEvent 
 */
- (nonnull instancetype)initWithType:(NCRouteEventType)type
                               value:(int32_t)value
                            distance:(float)distance;

/** 
 * @brief Factory method for class NCRouteEvent 
 */
+ (nonnull instancetype)routeEventWithType:(NCRouteEventType)type
                                     value:(int32_t)value
                                  distance:(float)distance;

/**
 * @brief Incoming event type @see RouteEventType "RouteEventType"
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteEvent_getType
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteEvent_getType
 *
 *
 */
@property (nonatomic, readonly) NCRouteEventType type;

/**
 * @brief Indicates angle in degrees for TURN_LEFT/TURN_RIGHT types @see RouteEventType "RouteEventType"
 * and target sublocation unique identifier if type is TRANSITION @see Sublocation "Sublocation"
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteEvent_getValue
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteEvent_getValue
 *
 *
 */
@property (nonatomic, readonly) int32_t value;

/**
 * @brief distance from the beginning of the route to incoming event in meters.
 *
 *
 * Swift code snippet:
 * @snippet RouteManagerExample.swift swift_RouteEvent_getDistance
 *
 * Objective C code snippet:
 * @snippet RouteManagerExample.m objc_RouteEvent_getDistance
 *
 *
 */
@property (nonatomic, readonly) float distance;

@end
