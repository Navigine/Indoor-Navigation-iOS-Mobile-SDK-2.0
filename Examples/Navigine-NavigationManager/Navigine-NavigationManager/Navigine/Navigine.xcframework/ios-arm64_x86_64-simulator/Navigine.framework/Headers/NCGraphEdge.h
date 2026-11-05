#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing graph edge.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphEdge : NSObject

/**
 * Edge weight.
 *
 * @discussion Example:
 * @code
 * // Get edge weight
 * float weight = [edge getWeight];
 * NSLog(@"Edge weight: %f", weight);
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * weight;

/**
 * Destination vertex id ``NCGraphVertex``
 *
 * @discussion Example:
 * @code
 * // Get destination vertex ID
 * int32_t dst = [edge getDst];
 * NSLog(@"Edge destination ID: %d", dst);
 * @endcode
 */
@property (nonatomic, readonly) int32_t dst;

/**
 * Source vertex id ``NCGraphVertex``
 *
 * @discussion Example:
 * @code
 * // Get source vertex ID
 * int32_t src = [edge getSrc];
 * NSLog(@"Edge source ID: %d", src);
 * @endcode
 */
@property (nonatomic, readonly) int32_t src;

/**
 * Edge weight coefficient.
 *
 * @discussion Example:
 * @code
 * // Get edge weight coefficient
 * int32_t weightCoef = [edge getWeightCoef];
 * NSLog(@"Edge weight coefficient: %d", weightCoef);
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * weightCoef;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
