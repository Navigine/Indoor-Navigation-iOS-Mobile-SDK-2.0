#import "NCCapType.h"
#import "NCExport.h"
#import "NCJoinType.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * Represents a polyline object on the location view.
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolylineMapObject : NCMapObject

/**
 * Method is used to specify the source polyline of the object.
 * @param polyline Metrics coordinates of the polyline ``NCLocationPolyline``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline geometry
 * NSArray<NCPoint *> *polylinePoints = @[
 *    [[NCPoint alloc] initWithX:100.0 y:200.0],
 *    [[NCPoint alloc] initWithX:150.0 y:250.0],
 *    [[NCPoint alloc] initWithX:200.0 y:300.0],
 *    [[NCPoint alloc] initWithX:250.0 y:350.0],
 * ];
 * NCPolyline *metricPl = [[NCPolyline alloc] initWithPoints:polylinePoints];
 * NCLocationPolyline *polyline = [[NCLocationPolyline alloc] initWithPolyline:metricPl locationId:1 sublocationId:0];
 * BOOL polylineSuccess = [polylineObject setPolyLine:polyline];
 * NSLog(@"Set polyline with %lu points: %@", (unsigned long)polylinePoints.count, polylineSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

/**
 * Method is used to specify the width of the polyline.
 * @param width Width of the polyline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline width
 * BOOL widthSuccess = [polylineObject setWidth:3.0];
 * NSLog(@"Set polyline width to 3.0 pixels: %@", widthSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setWidth:(float)width;

/**
 * Method is used to specify the fill color of the polyline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline color
 * BOOL polylineColorSuccess = [polylineObject setColorWithRed:0.0 green:1.0 blue:0.0 alpha:0.8];
 * NSLog(@"Set polyline color to green with 80%% opacity: %@", polylineColorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 * Method is used to specify the rendering order of the polyline.
 * @param order The rendering order value. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline rendering order
 * BOOL polylineOrderSuccess = [polylineObject setOrder:1];
 * NSLog(@"Set polyline rendering order to 1: %@", polylineOrderSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOrder:(int32_t)order;

/**
 * Method is used to specify the cap style for the polyline ends.
 * @param cap The cap type ``NCCapType``. Default: BUTT.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline cap type
 * BOOL capTypeSuccess = [polylineObject setCapType:NCCapTypeRound];
 * NSLog(@"Set polyline cap type to ROUND: %@", capTypeSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setCapType:(NCCapType)cap;

/**
 * Method is used to specify the join style for polyline segments.
 * @param join The join type ``NCJoinType``. Default: MITER.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline join type
 * BOOL joinTypeSuccess = [polylineObject setJoinType:NCJoinTypeRound];
 * NSLog(@"Set polyline join type to ROUND: %@", joinTypeSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setJoinType:(NCJoinType)join;

/**
 * Method is used to specify the miter limit for miter joins.
 * @param miterLimit The miter limit value for miter joins. Default: 3.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline miter limit
 * BOOL miterLimitSuccess = [polylineObject setMiterLimit:2.0];
 * NSLog(@"Set polyline miter limit to 2.0: %@", miterLimitSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setMiterLimit:(float)miterLimit;

/**
 * Method is used to specify the color of the polyline’s outline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline color
 * BOOL outlineColorSuccess = [polylineObject setOutlineColorWithRed:0.0 green:0.0 blue:0.0 alpha:1.0];
 * NSLog(@"Set polyline outline color to black: %@", outlineColorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineColor:(float)red
                  green:(float)green
                   blue:(float)blue
                  alpha:(float)alpha;

/**
 * Method is used to specify the width of the polyline’s outline.
 * @param radius Width of the outline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline width
 * BOOL outlineWidthSuccess = [polylineObject setOutlineWidth:1.0];
 * NSLog(@"Set polyline outline width to 1.0 pixels: %@", outlineWidthSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineWidth:(float)radius;

/**
 * Method is used to specify the opacity of the polyline’s outline.
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline alpha
 * BOOL outlineAlphaSuccess = [polylineObject setOutlineAlpha:0.5];
 * NSLog(@"Set polyline outline alpha to 0.5: %@", outlineAlphaSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineAlpha:(float)alpha;

/**
 * Method is used to specify the cap style for the polyline’s outline ends.
 * @param cap The cap type ``NCCapType``. Default: BUTT.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline cap type
 * BOOL outlineCapTypeSuccess = [polylineObject setOutlineCapType:NCCapTypeSquare];
 * NSLog(@"Set polyline outline cap type to SQUARE: %@", outlineCapTypeSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineCapType:(NCCapType)cap;

/**
 * Method is used to specify the join style for the polyline’s outline segments.
 * @param join The join type ``NCJoinType``. Default: MITER.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline join type
 * BOOL outlineJoinTypeSuccess = [polylineObject setOutlineJoinType:NCJoinTypeMiter];
 * NSLog(@"Set polyline outline join type to MITER: %@", outlineJoinTypeSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineJoinType:(NCJoinType)join;

/**
 * Method is used to specify the miter limit for the polyline’s outline miter joins.
 * @param miterLimit The miter limit value for outline miter joins. Default: 3.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline miter limit
 * BOOL outlineMiterLimitSuccess = [polylineObject setOutlineMiterLimit:3.0];
 * NSLog(@"Set polyline outline miter limit to 3.0: %@", outlineMiterLimitSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineMiterLimit:(float)miterLimit;

/**
 * Method is used to specify the rendering order of the polyline’s outline.
 * @param order The rendering order value for the outline. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set polyline outline rendering order
 * BOOL outlineOrderSuccess = [polylineObject setOutlineOrder:0];
 * NSLog(@"Set polyline outline rendering order to 0: %@", outlineOrderSuccess ? @"YES" : @"NO");
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
