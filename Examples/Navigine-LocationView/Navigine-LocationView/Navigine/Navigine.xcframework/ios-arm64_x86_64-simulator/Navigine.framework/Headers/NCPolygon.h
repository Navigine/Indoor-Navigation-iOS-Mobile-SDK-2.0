#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * A polygon with specified list of points.
 *
 * @discussion Example:
 * @code
 * // Create polygon
 * NCPolygon *polygon = [[NCPolygon alloc] initWithPoints:polygonPoints];
 * NSLog(@"Created polygon with %lu points", (unsigned long)polygon.points.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygon : NSObject

/** 
 * Default constructor for class NCPolygon 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;

/** 
 * Factory method for class NCPolygon 
 */
+ (nonnull instancetype)polygonWithPoints:(nonnull NSArray<NCPoint *> *)points;

/**
 * Ring specifying the area.
 *
 * @discussion Example:
 * @code
 * // Get polygon points
 * NSArray<NCPoint *> *points = polygon.points;
 * NSMutableString *pointsString = [NSMutableString string];
 * for (NCPoint *point in points) {
 *    if (pointsString.length > 0) {
 *        [pointsString appendString:@", "];
 *    }
 *    [pointsString appendFormat:@"(%.1f, %.1f)", point.x, point.y];
 * }
 * NSLog(@"Polygon points: %@", pointsString);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
