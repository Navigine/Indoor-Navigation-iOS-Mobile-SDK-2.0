#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCTransitionEntryEvent.h
 * @brief @copybrief NCTransitionEntryEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Event describing entering another level/sublocation transition.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTransitionEntryEvent : NSObject

/** 
 * @brief Default constructor for class NCTransitionEntryEvent 
 */
- (nonnull instancetype)initWithFrom:(int64_t)from
                                  to:(int64_t)to;

/** 
 * @brief Factory method for class NCTransitionEntryEvent 
 */
+ (nonnull instancetype)transitionEntryEventWithFrom:(int64_t)from
                                                  to:(int64_t)to;

/**
 * @brief Source level identifier.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TransitionEntryEvent_getFrom
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TransitionEntryEvent_getFrom
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
 *@snippet RouteManagerExample.swift swift_TransitionEntryEvent_getTo
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TransitionEntryEvent_getTo
 *
 *
 */
@property (nonatomic, readonly) int64_t to;

@end
