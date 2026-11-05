#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Event describing exiting a level/sublocation transition.
 * Referenced from ``NCRouteEvent``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTransitionExitEvent : NSObject

/** 
 * Default constructor for class NCTransitionExitEvent 
 */
- (nonnull instancetype)initWithFrom:(int64_t)from
                                  to:(int64_t)to;

/** 
 * Factory method for class NCTransitionExitEvent 
 */
+ (nonnull instancetype)transitionExitEventWithFrom:(int64_t)from
                                                 to:(int64_t)to;

/**
 * Source level identifier.
 *
 * @discussion Example:
 * @code
 * int64_t from = [event getFrom];
 * NSLog(@"Transition exit from: %lld", from);
 * @endcode
 */
@property (nonatomic, readonly) int64_t from;

/**
 * Destination level identifier.
 *
 * @discussion Example:
 * @code
 * int64_t to = [event getTo];
 * NSLog(@"Transition exit to: %lld", to);
 * @endcode
 */
@property (nonatomic, readonly) int64_t to;

@end
