#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing graph vertex.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphVertex : NSObject

/**
 * graph vertex unique identifier.
 *
 * @discussion Example:
 * @code
 * // Get vertex ID
 * int32_t vertexId = [vertex getId];
 * NSLog(@"Vertex ID: %d", vertexId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * graph vertex position in meters ``NCPoint``.
 *
 * @discussion Example:
 * @code
 * // Get vertex point
 * NCPoint *point = [vertex getPoint];
 * if (point != nil) {
 *    [self demonstratePointUsage:point];
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * graph vertex name.
 *
 * @discussion Example:
 * @code
 * // Get vertex name
 * NSString *name = [vertex getName];
 * NSLog(@"Vertex name: %@", name);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * graph vertex can be used to communicate with external graphs or not.
 *
 * @discussion Example:
 * @code
 * // Get vertex external flag
 * BOOL isExternal = [vertex getIsExternal];
 * NSLog(@"Vertex is external: %@", isExternal ? @"YES" : @"NO");
 * @endcode
 */
@property (nonatomic, readonly) BOOL isExternal;

/**
 * graph vertex used in elevation graph ``NCElevationGraph`` or not.
 *
 * @discussion Example:
 * @code
 * // Get vertex elevation flag
 * BOOL isElevation = [vertex getIsElevation];
 * NSLog(@"Vertex is elevation: %@", isElevation ? @"YES" : @"NO");
 * @endcode
 */
@property (nonatomic, readonly) BOOL isElevation;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
