#import "NCExport.h"
#import "NCTurnType.h"
#import <Foundation/Foundation.h>

/**
 * Class describing turn guidance event.
 * Referenced from ``NCRouteEvent``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTurnEvent : NSObject

/** 
 * Default constructor for class NCTurnEvent 
 */
- (nonnull instancetype)initWithType:(NCTurnType)type
                               angle:(int32_t)angle;

/** 
 * Factory method for class NCTurnEvent 
 */
+ (nonnull instancetype)turnEventWithType:(NCTurnType)type
                                    angle:(int32_t)angle;

/**
 * Turn direction/severity type.
 *
 * @discussion Example:
 * @code
 * NCTurnType type = [event getType];
 * NSLog(@"Turn type: %ld", (long)type);
 * @endcode
 */
@property (nonatomic, readonly) NCTurnType type;

/**
 * Signed turn angle in degrees.
 *
 * @discussion Example:
 * @code
 * int32_t angle = [event getAngle];
 * NSLog(@"Turn angle: %d", angle);
 * @endcode
 */
@property (nonatomic, readonly) int32_t angle;

@end
