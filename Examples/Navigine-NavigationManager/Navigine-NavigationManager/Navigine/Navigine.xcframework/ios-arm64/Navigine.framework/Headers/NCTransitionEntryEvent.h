#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Event describing entering another level/sublocation transition.
 * Referenced from ``NCRouteEvent``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTransitionEntryEvent : NSObject

/** 
 * Default constructor for class NCTransitionEntryEvent 
 */
- (nonnull instancetype)initWithFrom:(int64_t)from
                                  to:(int64_t)to;

/** 
 * Factory method for class NCTransitionEntryEvent 
 */
+ (nonnull instancetype)transitionEntryEventWithFrom:(int64_t)from
                                                  to:(int64_t)to;

/**
 * Source level identifier.
 *
 * @discussion Example:
 * @code
 * int64_t from = [event getFrom];
 * NSLog(@"Transition entry from: %lld", from);
 * @endcode
 */
@property (nonatomic, readonly) int64_t from;

/**
 * Destination level identifier.
 *
 * @discussion Example:
 * @code
 * int64_t to = [event getTo];
 * NSLog(@"Transition entry to: %lld", to);
 * @endcode
 */
@property (nonatomic, readonly) int64_t to;

@end
