#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * Represents a circle on the location view.
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCircleMapObject : NCMapObject

/**
 * Method is used to specify the center of the circle.
 * @param point Metrics coordinates of the center ``NCLocationPoint``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set circle position
 * NCLocationPoint *centerPoint = [[NCLocationPoint alloc] initWithX:100.0 y:200.0];
 * BOOL success = [circleObject setPosition:centerPoint];
 * NSLog(@"Set circle position to (%f, %f): %@", centerPoint.x, centerPoint.y, success ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 * Method is used to move the center of the circle with the specified animation.
 * @param point Metrics coordinates of the center ``NCLocationPoint``.
 * @param duration Animation duration in seconds.
 * @param type Animation type ``NCAnimationType``. Default: CENTER.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set circle position with animation
 * NCLocationPoint *animatedPoint = [[NCLocationPoint alloc] initWithX:150.0 y:250.0];
 * BOOL animatedSuccess = [circleObject setPositionAnimated:animatedPoint duration:2.0 animationType:AnimationTypeLinear];
 * NSLog(@"Set circle position with animation to (%f, %f): %@", animatedPoint.x, animatedPoint.y, animatedSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 * Method is used to specify the fill color of the circle.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set circle color
 * BOOL colorSuccess = [circleObject setColorWithRed:1.0 green:0.0 blue:0.0 alpha:0.8];
 * NSLog(@"Set circle color to red with 80%% opacity: %@", colorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 * Method is used to specify the size of the circle.
 * @param radius Radius of the circle in meters.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set circle radius
 * BOOL radiusSuccess = [circleObject setRadius:10.0];
 * NSLog(@"Set circle radius to 10.0 meters: %@", radiusSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setRadius:(float)radius;

/**
 * Method is used to enable or disable collision detection for the circle.
 * @param enabled Specifies whether collision detection is enabled (true) or disabled (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Enable collision detection
 * BOOL collisionSuccess = [circleObject setCollisionEnabled:YES];
 * NSLog(@"Enabled collision detection for circle: %@", collisionSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 * Method is used to specify the buffer size around the circle for collision detection.
 * @param width Width of the buffer in pixels. Default: 0.
 * @param height Height of the buffer in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set collision buffer
 * BOOL bufferSuccess = [circleObject setBufferWithWidth:5.0 height:5.0];
 * NSLog(@"Set collision buffer to 5x5 pixels: %@", bufferSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setBuffer:(float)width
           height:(float)height;

/**
 * Method is used to specify an offset for the circle’s position.
 * @param width Horizontal offset in pixels.
 * @param height Vertical offset in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set position offset
 * BOOL offsetSuccess = [circleObject setOffsetWithX:2.0 y:3.0];
 * NSLog(@"Set position offset to (2.0, 3.0) pixels: %@", offsetSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOffset:(float)width
           height:(float)height;

/**
 * Method is used to specify the priority of the circle.
 * @param priority The priority value for rendering or interaction. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set rendering priority
 * BOOL prioritySuccess = [circleObject setPriority:1];
 * NSLog(@"Set rendering priority to 1: %@", prioritySuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPriority:(float)priority;

/**
 * Method is used to specify the color of the circle’s outline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set outline color
 * BOOL outlineColorSuccess = [circleObject setOutlineColorWithRed:0.0 green:0.0 blue:1.0 alpha:1.0];
 * NSLog(@"Set circle outline color to blue: %@", outlineColorSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineColor:(float)red
                  green:(float)green
                   blue:(float)blue
                  alpha:(float)alpha;

/**
 * Method is used to specify the thickness of the circle’s outline.
 * @param radius Thickness of the outline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set outline radius
 * BOOL outlineRadiusSuccess = [circleObject setOutlineRadius:2.0];
 * NSLog(@"Set circle outline radius to 2.0: %@", outlineRadiusSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineRadius:(float)radius;

/**
 * Method is used to specify the opacity of the circle’s outline.
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set outline alpha
 * BOOL outlineAlphaSuccess = [circleObject setOutlineAlpha:0.5];
 * NSLog(@"Set circle outline alpha to 0.5: %@", outlineAlphaSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOutlineAlpha:(float)alpha;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
