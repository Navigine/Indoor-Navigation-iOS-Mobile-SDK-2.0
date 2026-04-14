#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCTransitionExitEvent.h
 * @brief @copybrief NCTransitionExitEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Event describing exiting a level/sublocation transition.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTransitionExitEvent : NSObject

/** 
 * @brief Default constructor for class NCTransitionExitEvent 
 */
- (nonnull instancetype)initWithFrom:(int64_t)from
                                  to:(int64_t)to;

/** 
 * @brief Factory method for class NCTransitionExitEvent 
 */
+ (nonnull instancetype)transitionExitEventWithFrom:(int64_t)from
                                                 to:(int64_t)to;

/**
 * @brief Source level identifier.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TransitionExitEvent_getFrom
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TransitionExitEvent_getFrom
 *
 *
 */
@property (nonatomic, readonly) int64_t from;

/**
 * @brief Destination level identifier.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TransitionExitEvent_getTo
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TransitionExitEvent_getTo
 *
 *
 */
@property (nonatomic, readonly) int64_t to;

@end
