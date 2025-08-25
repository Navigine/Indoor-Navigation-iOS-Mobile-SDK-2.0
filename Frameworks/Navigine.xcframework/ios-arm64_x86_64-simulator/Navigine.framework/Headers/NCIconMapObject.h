#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * @file NCIconMapObject.h
 * @brief @copybrief NCIconMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Represents an icon object on the location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 * @note IconMapObject maintains orientation to the screen surface by default.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCIconMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify the center of the icon.
 * @param point Metrics coordinates of the center @see LocationPoint "LocationPoint".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setPosition
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setPosition
 *
 *
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 *
 * @brief Method is used to move the center of the icon with the specified animation.
 * @param point Metrics coordinates of the center @see LocationPoint "LocationPoint".
 * @param duration Animation duration in seconds.
 * @param type Animation type @see AnimationType "AnimationType".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setPositionAnimated
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setPositionAnimated
 *
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 *
 * @brief Method is used to specify the bitmap image for the icon.
 * @param bitmap Platform bitmap object.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setBitmap
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setBitmap
 *
 *
 */
- (BOOL)setBitmap:(nullable UIImage *)bitmap;

/**
 *
 * @brief Method is used to specify the size of the icon.
 * @param width Width of the icon in pixels.
 * @param height Height of the icon in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setSize
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setSize
 *
 *
 */
- (BOOL)setSize:(float)width
         height:(float)height;

/**
 *
 * @brief Method is used to enable or disable collision detection for the icon.
 * @param enabled Specifies whether collision detection is enabled (true) or disabled (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setCollisionEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setCollisionEnabled
 *
 *
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 *
 * @brief Method is used to specify the rotation angle of the icon.
 * @param angle Rotation angle in degrees. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setAngle
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setAngle
 *
 *
 */
- (BOOL)setAngle:(float)angle;

/**
 *
 * @brief Method is used to rotate the icon with the specified animation.
 * @param angle Rotation angle in degrees.
 * @param duration Animation duration in seconds.
 * @param type Animation type @see AnimationType "AnimationType".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setAngleAnimated
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setAngleAnimated
 *
 *
 */
- (BOOL)setAngleAnimated:(float)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

/**
 *
 * @brief Method is used to specify the buffer size around the icon for collision detection.
 * @param width Width of the buffer in pixels. Default: 0.
 * @param height Height of the buffer in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setBuffer
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setBuffer
 *
 *
 */
- (BOOL)setBuffer:(float)width
           height:(float)height;

/**
 *
 * @brief Method is used to specify an offset for the circle’s position.
 * @param width Horizontal offset in pixels.
 * @param height Vertical offset in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setOffset
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setOffset
 *
 *
 */
- (BOOL)setOffset:(float)width
           height:(float)height;

/**
 *
 * @brief Method is used to specify the priority of the icon.
 * @param priority The priority value for rendering or interaction. Default: max.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setPriority
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setPriority
 *
 *
 */
- (BOOL)setPriority:(float)priority;

/**
 *
 * @brief Method is used to specify whether the icon is flat or billboarded.
 * @param flat If true, the icon aligns with the location view surface; if false, it maintains orientation to the screen surface. Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_IconMapObject_setFlat
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_IconMapObject_setFlat
 *
 *
 */
- (BOOL)setFlat:(BOOL)flat;

@end
