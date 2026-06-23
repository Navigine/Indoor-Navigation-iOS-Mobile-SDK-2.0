#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * A point at the specified metrics coordinates.
 *
 * @discussion Example:
 * @code
 * // Create points with x, y coordinates
 * NCPoint *point1 = [[NCPoint alloc] initWithX:10.0 y:20.0];
 * NCPoint *point2 = [[NCPoint alloc] initWithX:30.0 y:40.0];
 * NCPoint *point3 = [[NCPoint alloc] initWithX:50.0 y:60.0];
 * NSLog(@"Created points: P1(%.1f, %.1f), P2(%.1f, %.1f), P3(%.1f, %.1f)",
 *      point1.x, point1.y, point2.x, point2.y, point3.x, point3.y);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPoint : NSObject

/** 
 * Default constructor for class NCPoint 
 */
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y;

/** 
 * Factory method for class NCPoint 
 */
+ (nonnull instancetype)pointWithX:(float)x
                                 y:(float)y;

/**
 * point's `x` coordinate in meters.
 *
 * @discussion Example:
 * @code
 * // Get X coordinate
 * double x1 = point1.x;
 * NSLog(@"Point1 X coordinate: %.1f", x1);
 * @endcode
 */
@property (nonatomic, readonly) float x;

/**
 * point's `y` coordinate in meters.
 *
 * @discussion Example:
 * @code
 * // Get Y coordinate
 * double y1 = point1.y;
 * NSLog(@"Point1 Y coordinate: %.1f", y1);
 * @endcode
 */
@property (nonatomic, readonly) float y;

@end
