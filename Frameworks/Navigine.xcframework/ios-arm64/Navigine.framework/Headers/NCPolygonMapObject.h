#import "NCExport.h"
#import "NCLocationPolygon.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


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
 * NSArray<NCGlobalPoint *> *points = @[
 *    [[NCGlobalPoint alloc] initWithLatitude:100.0 longitude:200.0],
 *    [[NCGlobalPoint alloc] initWithLatitude:150.0 longitude:250.0],
 *    [[NCGlobalPoint alloc] initWithLatitude:200.0 longitude:200.0],
 *    [[NCGlobalPoint alloc] initWithLatitude:150.0 longitude:150.0],
 * ];
 * NCLocationPolygon *polygon = [[NCLocationPolygon alloc] initWithPoints:points sublocationId:@(0)];
 * BOOL success = [polygonObject setPolygon:polygon];
 * NSLog(@"Set polygon with %lu points: %@", (unsigned long)points.count, success ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPolygon:(nonnull NCLocationPolygon *)polygon;

/**
 * Method is used to specify the color of the object.
 * @param color Fill color.
 * @return true if success, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon color
 * BOOL colorSuccess = [polygonObject setColor:[UIColor colorWithRed:0.0 green:1.0 blue:0.0 alpha:0.7]];
 * NSLog(@"Set polygon color to green with 70%% opacity: %@", colorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setColor:(nonnull UIColor *)color;

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
 * Method is used to specify the color of the polygon’s outline.
 * @param color Outline color.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon outline color
 * BOOL outlineColorSuccess = [polygonObject setOutlineColor:[UIColor colorWithRed:0.0 green:0.0 blue:1.0 alpha:1.0]];
 * NSLog(@"Set polygon outline color to blue: %@", outlineColorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineColor:(nonnull UIColor *)color;

/**
 * Method is used to specify the width of the polygon’s outline.
 * @param width Width of the outline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon outline width
 * BOOL outlineWidthSuccess = [polygonObject setOutlineWidth:2.0];
 * NSLog(@"Set polygon outline width to 2.0 pixels: %@", outlineWidthSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineWidth:(float)width;

/**
 * Method is used to specify the opacity of the polygon’s outline.
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon outline alpha
 * BOOL outlineAlphaSuccess = [polygonObject setOutlineAlpha:0.8];
 * NSLog(@"Set polygon outline alpha to 0.8: %@", outlineAlphaSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineAlpha:(float)alpha;

/**
 * Method is used to specify the rendering order of the polygon’s outline.
 * @param order The rendering order value. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polygon outline order
 * BOOL outlineOrderSuccess = [polygonObject setOutlineOrder:1];
 * NSLog(@"Set polygon outline order to 1: %@", outlineOrderSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineOrder:(int32_t)order;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
