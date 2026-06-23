#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

/**
 * Event indicating the route target has been reached.
 * Referenced from ``NCRouteEvent``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTargetReachedEvent : NSObject

/** 
 * Default constructor for class NCTargetReachedEvent 
 */
- (nonnull instancetype)initWithIndex:(int64_t)index
                                point:(nonnull NCLocationPoint *)point;

/** 
 * Factory method for class NCTargetReachedEvent 
 */
+ (nonnull instancetype)targetReachedEventWithIndex:(int64_t)index
                                              point:(nonnull NCLocationPoint *)point;

/**
 * Index of reached target in target list.
 *
 * @discussion Example:
 * @code
 * int64_t index = [event getIndex];
 * NSLog(@"Reached target index: %lld", index);
 * @endcode
 */
@property (nonatomic, readonly) int64_t index;

/**
 * Location point where target was reached.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *point = [event getPoint];
 * [self demonstrateLocationPointUsage:point];
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCLocationPoint * point;

@end
