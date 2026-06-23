#import "NCExport.h"
#import "NCLocationPolygon.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * Represents a polygon object on the location view.
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygonMapObject : NCMapObject

/**
 * Method is used to specify the source polygon of the object.
 * @param polygon Metrics coordinates of the polygon ``NCLocationPolygon``.
 * @return true if success, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon geometry
 * NSArray<NCPoint *> *points = @[
 *    [[NCPoint alloc] initWithX:100.0 y:200.0],
 *    [[NCPoint alloc] initWithX:150.0 y:250.0],
 *    [[NCPoint alloc] initWithX:200.0 y:200.0],
 *    [[NCPoint alloc] initWithX:150.0 y:150.0],
 * ];
 * NCPolygon *metricPolygon = [[NCPolygon alloc] initWithPoints:points];
 * NCLocationPolygon *polygon = [[NCLocationPolygon alloc] initWithPolygon:metricPolygon locationId:1 sublocationId:0];
 * BOOL success = [polygonObject setPolygon:polygon];
 * NSLog(@"Set polygon with %lu points: %@", (unsigned long)points.count, success ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPolygon:(nonnull NCLocationPolygon *)polygon;

/**
 * Method is used to specify the color of the object.
 * @param red Red RGBA component.
 * @param green Green RGBA component.
 * @param blue Blue RGBA component.
 * @param alpha Opacity multiplier. Values below 0 will be set to 0. Default: 1.
 * @return true if success, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon color
 * BOOL colorSuccess = [polygonObject setColorWithRed:0.0 green:1.0 blue:0.0 alpha:0.7];
 * NSLog(@"Set polygon color to green with 70%% opacity: %@", colorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 * Method is used to specify the rendering order of the object.
 * @param order The rendering order value. Default: 0.
 * @return true if success, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon rendering order
 * BOOL orderSuccess = [polygonObject setOrder:2];
 * NSLog(@"Set polygon rendering order to 2: %@", orderSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOrder:(int32_t)order;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
