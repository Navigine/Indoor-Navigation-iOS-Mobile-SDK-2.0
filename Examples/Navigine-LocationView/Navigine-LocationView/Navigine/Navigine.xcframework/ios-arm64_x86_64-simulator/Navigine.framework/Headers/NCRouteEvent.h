#import "NCExport.h"
#import "NCRouteEventType.h"
#import "NCTargetReachedEvent.h"
#import "NCTransitionEntryEvent.h"
#import "NCTransitionExitEvent.h"
#import "NCTurnEvent.h"
#import <Foundation/Foundation.h>

/**
 * Class storing one route event payload.
 * Referenced from ``NCRoutePath``, ``NCRouteNode``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteEvent : NSObject

/** 
 * Default constructor for class NCRouteEvent 
 */
- (nonnull instancetype)initWithType:(NCRouteEventType)type
                           turnEvent:(nullable NCTurnEvent *)turnEvent
                transitionEntryEvent:(nullable NCTransitionEntryEvent *)transitionEntryEvent
                 transitionExitEvent:(nullable NCTransitionExitEvent *)transitionExitEvent
                  targetReachedEvent:(nullable NCTargetReachedEvent *)targetReachedEvent;

/** 
 * Factory method for class NCRouteEvent 
 */
+ (nonnull instancetype)routeEventWithType:(NCRouteEventType)type
                                 turnEvent:(nullable NCTurnEvent *)turnEvent
                      transitionEntryEvent:(nullable NCTransitionEntryEvent *)transitionEntryEvent
                       transitionExitEvent:(nullable NCTransitionExitEvent *)transitionExitEvent
                        targetReachedEvent:(nullable NCTargetReachedEvent *)targetReachedEvent;

/**
 * Active event variant discriminator.
 *
 * @discussion Example:
 * @code
 * // Get event type
 * NCRouteEventType type = [event getType];
 * NSLog(@"Event type: %ld", (long)type);
 * @endcode
 */
@property (nonatomic, readonly) NCRouteEventType type;

/**
 * Payload for turn events, set when type is TURN_EVENT.
 *
 * @discussion Example:
 * @code
 * NCTurnEvent *turnEvent = [event getTurnEvent];
 * if (turnEvent != nil) {
 *    [self demonstrateTurnEventUsage:turnEvent];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NCTurnEvent * turnEvent;

/**
 * Payload for transition entry events.
 *
 * @discussion Example:
 * @code
 * NCTransitionEntryEvent *entryEvent = [event getTransitionEntryEvent];
 * if (entryEvent != nil) {
 *    [self demonstrateTransitionEntryEventUsage:entryEvent];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NCTransitionEntryEvent * transitionEntryEvent;

/**
 * Payload for transition exit events.
 *
 * @discussion Example:
 * @code
 * NCTransitionExitEvent *exitEvent = [event getTransitionExitEvent];
 * if (exitEvent != nil) {
 *    [self demonstrateTransitionExitEventUsage:exitEvent];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NCTransitionExitEvent * transitionExitEvent;

/**
 * Payload for target reached events.
 *
 * @discussion Example:
 * @code
 * NCTargetReachedEvent *targetEvent = [event getTargetReachedEvent];
 * if (targetEvent != nil) {
 *    [self demonstrateTargetReachedEventUsage:targetEvent];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NCTargetReachedEvent * targetReachedEvent;

@end
