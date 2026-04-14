#import "NCExport.h"
#import "NCRouteEventType.h"
#import "NCTargetReachedEvent.h"
#import "NCTransitionEntryEvent.h"
#import "NCTransitionExitEvent.h"
#import "NCTurnEvent.h"
#import <Foundation/Foundation.h>

/**
 * @file NCRouteEvent.h
 * @brief @copybrief NCRouteEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class storing one route event payload.
 *
 * Referenced from @see RoutePath "RoutePath", @see RouteNode "RouteNode".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteEvent : NSObject

/** 
 * @brief Default constructor for class NCRouteEvent 
 */
- (nonnull instancetype)initWithType:(NCRouteEventType)type
                           turnEvent:(nullable NCTurnEvent *)turnEvent
                transitionEntryEvent:(nullable NCTransitionEntryEvent *)transitionEntryEvent
                 transitionExitEvent:(nullable NCTransitionExitEvent *)transitionExitEvent
                  targetReachedEvent:(nullable NCTargetReachedEvent *)targetReachedEvent;

/** 
 * @brief Factory method for class NCRouteEvent 
 */
+ (nonnull instancetype)routeEventWithType:(NCRouteEventType)type
                                 turnEvent:(nullable NCTurnEvent *)turnEvent
                      transitionEntryEvent:(nullable NCTransitionEntryEvent *)transitionEntryEvent
                       transitionExitEvent:(nullable NCTransitionExitEvent *)transitionExitEvent
                        targetReachedEvent:(nullable NCTargetReachedEvent *)targetReachedEvent;

/**
 * @brief Active event variant discriminator.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEvent_getType
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEvent_getType
 *
 *
 */
@property (nonatomic, readonly) NCRouteEventType type;

/**
 * @brief Payload for turn events, set when type is TURN_EVENT.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEvent_getTurnEvent
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEvent_getTurnEvent
 *
 *
 */
@property (nonatomic, readonly, nullable) NCTurnEvent * turnEvent;

/**
 * @brief Payload for transition entry events.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEvent_getTransitionEntryEvent
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEvent_getTransitionEntryEvent
 *
 *
 */
@property (nonatomic, readonly, nullable) NCTransitionEntryEvent * transitionEntryEvent;

/**
 * @brief Payload for transition exit events.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEvent_getTransitionExitEvent
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEvent_getTransitionExitEvent
 *
 *
 */
@property (nonatomic, readonly, nullable) NCTransitionExitEvent * transitionExitEvent;

/**
 * @brief Payload for target reached events.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEvent_getTargetReachedEvent
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEvent_getTargetReachedEvent
 *
 *
 */
@property (nonatomic, readonly, nullable) NCTargetReachedEvent * targetReachedEvent;

@end
