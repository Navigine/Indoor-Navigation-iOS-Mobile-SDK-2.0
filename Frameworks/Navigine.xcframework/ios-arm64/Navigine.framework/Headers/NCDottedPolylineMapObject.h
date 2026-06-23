#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import "NCPlacement.h"
#import <Foundation/Foundation.h>


/**
 * Represents a polyline object with points placed along it on the location view.
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCDottedPolylineMapObject : NCMapObject

/**
 * Method is used to specify the source polyline for the points.
 * @param polyline Metrics coordinates of the polyline ``NCLocationPolyline``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set dotted polyline geometry
 * NSArray<NCPoint *> *dottedPoints = @[
 *    [[NCPoint alloc] initWithX:160.0 y:170.0],
 *    [[NCPoint alloc] initWithX:165.0 y:175.0],
 *    [[NCPoint alloc] initWithX:170.0 y:180.0],
 *    [[NCPoint alloc] initWithX:175.0 y:185.0],
 * ];
 * NCPolyline *dottedPl = [[NCPolyline alloc] initWithPoints:dottedPoints];
 * NCLocationPolyline *dottedPolyline = [[NCLocationPolyline alloc] initWithPolyline:dottedPl locationId:1 sublocationId:0];
 * BOOL dottedSuccess = [dottedPolylineObject setPolyline:dottedPolyline];
 * NSLog(@"Set dotted polyline with %lu points: %@", (unsigned long)dottedPoints.count, dottedSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

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
 * // Set dotted polyline color
 * BOOL colorSuccess = [dottedPolylineObject setColorWithRed:0.5 green:0.0 blue:1.0 alpha:0.8];
 * NSLog(@"Set dotted polyline color to purple with 80%% opacity: %@", colorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 * Method is used to specify the size of the points.
 * @param width Width of the points in pixels.
 * @param height Height of the points in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set size
 * NCSize *size = [[NCSize alloc] initWithWidth:16.0 height:16.0];
 * BOOL sizeSuccess = [dottedPolylineObject setSize:size];
 * NSLog(@"Set dotted polyline size to (%.1f, %.1f): %@", size.width, size.height, sizeSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setSize:(float)width
         height:(float)height;

/**
 * Method is used to enable or disable collision detection for the icon.
 * @param enabled Specifies whether collision detection is enabled (true) or disabled (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Enable collision detection
 * BOOL collisionSuccess = [dottedPolylineObject setCollisionEnabled:YES];
 * NSLog(@"Enabled collision detection for dotted polyline: %@", collisionSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 * Method is used to specify the placement mode for points along the polyline.
 * @param placement The placement mode ``NCPlacement``. Default: VERTEX.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set placement type
 * BOOL placementSuccess = [dottedPolylineObject setPlacement:NCCenter];
 * NSLog(@"Set dotted polyline placement to CENTER: %@", placementSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPlacement:(NCPlacement)placement;

/**
 * Method is used to specify the minimum ratio of the polyline length for point placement.
 * @param ratio The minimum ratio of the polyline length (typically between 0 and 1). Default: 1.0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set placement min ratio
 * BOOL minRatioSuccess = [dottedPolylineObject setPlacementMinRatio:0.5];
 * NSLog(@"Set dotted polyline placement min ratio to 0.5: %@", minRatioSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPlacementMinRatio:(float)ratio;

/**
 * Method is used to specify the spacing between points for spaced placement.
 * @param spacing The spacing distance in pixels. Default: 80.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set placement spacing
 * BOOL spacingSuccess = [dottedPolylineObject setPlacementSpacing:10.0];
 * NSLog(@"Set dotted polyline placement spacing to 10.0: %@", spacingSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPlacementSpacing:(float)spacing;

/**
 * Method is used to specify the distance interval for repeating points along the polyline.
 * @param distance The repeat distance in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set repeat distance
 * BOOL repeatDistanceSuccess = [dottedPolylineObject setRepeatDistance:20.0];
 * NSLog(@"Set dotted polyline repeat distance to 20.0: %@", repeatDistanceSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setRepeatDistance:(float)distance;

/**
 * Method is used to specify the group identifier for repeating points.
 * @param group The group identifier for point repetition. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set repeat group
 * BOOL repeatGroupSuccess = [dottedPolylineObject setRepeatGroup:1];
 * NSLog(@"Set dotted polyline repeat group to 1: %@", repeatGroupSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setRepeatGroup:(int32_t)group;

/**
 * Method is used to specify the priority of the icon.
 * @param priority The priority value for rendering or interaction. Default: max.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set rendering priority
 * BOOL prioritySuccess = [dottedPolylineObject setPriority:1];
 * NSLog(@"Set dotted polyline rendering priority to 1: %@", prioritySuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPriority:(float)priority;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
