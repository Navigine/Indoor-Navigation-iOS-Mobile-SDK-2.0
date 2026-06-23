#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * Represents an icon object on the location view.
 * Referenced from ``NCLocationWindow``.
 * @discussion Note: IconMapObject maintains orientation to the screen surface by default.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCIconMapObject : NCMapObject

/**
 * Method is used to specify the center of the icon.
 * @param point Metrics coordinates of the center ``NCLocationPoint``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon position
 * NCLocationPoint *newPosition = [[NCLocationPoint alloc] initWithX:35.0 y:45.0];
 * BOOL positionSuccess = [iconObject setPosition:newPosition];
 * NSLog(@"Set icon position to (%.1f, %.1f): %@", newPosition.x, newPosition.y, positionSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 * Method is used to move the center of the icon with the specified animation.
 * @param point Metrics coordinates of the center ``NCLocationPoint``.
 * @param duration Animation duration in seconds.
 * @param type Animation type ``NCAnimationType``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon position with animation
 * NCLocationPoint *animatedPosition = [[NCLocationPoint alloc] initWithX:40.0 y:50.0];
 * BOOL animatedSuccess = [iconObject setPositionAnimated:animatedPosition duration:2.0 animationType:NCLinear];
 * NSLog(@"Set icon position with animation to (%.1f, %.1f): %@", animatedPosition.x, animatedPosition.y, animatedSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 * Method is used to specify the decoded raster for the icon.
 * @param bitmap Image provider: Android com.navigine.image.ImageProvider; iOS UIImage via binding; Flutter navigine_sdk ImageProvider.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * UIImage *iconImage = [UIImage imageWithContentsOfFile:@"/path/to/icon.png"];
 * BOOL bitmapSuccess = (iconImage != nil) && [iconObject setBitmap:iconImage];
 * NSLog(@"Set icon bitmap (UIImage): %@", bitmapSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setBitmap:(nullable UIImage *)bitmap;

/**
 * Method is used to specify the size of the icon.
 * @param width Width of the icon in pixels.
 * @param height Height of the icon in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon size
 * NCSize *size = [[NCSize alloc] initWithWidth:32.0 height:32.0];
 * BOOL sizeSuccess = [iconObject setSize:size];
 * NSLog(@"Set icon size to (%.1f, %.1f): %@", size.width, size.height, sizeSuccess ? @"YES" : @"NO");
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
 * BOOL collisionSuccess = [iconObject setCollisionEnabled:YES];
 * NSLog(@"Enabled collision detection for icon: %@", collisionSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 * Method is used to specify the rotation angle of the icon.
 * @param angle Rotation angle in degrees. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon rotation angle
 * BOOL angleSuccess = [iconObject setAngle:45.0];
 * NSLog(@"Set icon rotation angle to 45 degrees: %@", angleSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAngle:(float)angle;

/**
 * Method is used to rotate the icon with the specified animation.
 * @param angle Rotation angle in degrees.
 * @param duration Animation duration in seconds.
 * @param type Animation type ``NCAnimationType``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon rotation with animation
 * BOOL angleAnimatedSuccess = [iconObject setAngleAnimated:90.0 duration:2.0 animationType:NCSine];
 * NSLog(@"Set icon rotation with animation to 90 degrees: %@", angleAnimatedSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAngleAnimated:(float)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

/**
 * Method is used to specify the buffer size around the icon for collision detection.
 * @param width Width of the buffer in pixels. Default: 0.
 * @param height Height of the buffer in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set collision buffer
 * BOOL bufferSuccess = [iconObject setBufferWithWidth:10.0 height:10.0];
 * NSLog(@"Set collision buffer to 10x10 pixels: %@", bufferSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setBuffer:(float)width
           height:(float)height;

/**
 * Method is used to specify an offset for the icon’s anchor on screen.
 * @param width Horizontal offset in pixels.
 * @param height Vertical offset in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon offset
 * BOOL offsetSuccess = [iconObject setOffsetWithWidth:5.0 height:5.0];
 * NSLog(@"Set icon offset to 5x5 pixels: %@", offsetSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setOffset:(float)width
           height:(float)height;

/**
 * Method is used to specify the priority of the icon.
 * @param priority The priority value for rendering or interaction. Default: max.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon priority
 * BOOL prioritySuccess = [iconObject setPriority:1];
 * NSLog(@"Set icon priority to 1: %@", prioritySuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPriority:(float)priority;

/**
 * Method is used to specify whether the icon is flat or billboarded.
 * @param flat If true, the icon aligns with the location view surface; if false, it maintains orientation to the screen surface. Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set icon flat mode
 * BOOL flatSuccess = [iconObject setFlat:YES];
 * NSLog(@"Set icon flat mode to true: %@", flatSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setFlat:(BOOL)flat;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
