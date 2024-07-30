#import "NCExport.h"
#import "NCRouteEventType.h"
#import <Foundation/Foundation.h>

/**
 *
 * A route event handle information about incoming events on the route.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteEvent : NSObject
- (nonnull instancetype)initWithType:(NCRouteEventType)type
                               value:(int32_t)value
                            distance:(float)distance;
+ (nonnull instancetype)routeEventWithType:(NCRouteEventType)type
                                     value:(int32_t)value
                                  distance:(float)distance;

/** Incoming event type. */
@property (nonatomic, readonly) NCRouteEventType type;

/**
 * Indicates angle in degrees for TURN_LEFT/TURN_RIGHT types (@see RouteEventType)
 * and target sublocation unique identifier if type is TRANSITION (@see Sublocation)
 */
@property (nonatomic, readonly) int32_t value;

/** distance from the beginning of the route to incoming event in meters. */
@property (nonatomic, readonly) float distance;

@end
