#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCCircleMapObject.h
 * @brief @copybrief NCCircleMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Represents a circle on the location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCircleMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify the center of the circle.
 * @param point Metrics coordinates of the center @see LocationPoint "LocationPoint".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setPosition
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setPosition
 *
 *
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 *
 * @brief Method is used to move the center of the circle with the specified animation.
 * @param point Metrics coordinates of the center @see LocationPoint "LocationPoint".
 * @param duration Animation duration in seconds.
 * @param type Animation type @see AnimationType "AnimationType". Default: CENTER.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setPositionAnimated
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setPositionAnimated
 *
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 *
 * @brief Method is used to specify the fill color of the circle.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setColor
 *
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the size of the circle.
 * @param radius Radius of the circle in meters.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setRadius
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setRadius
 *
 *
 */
- (BOOL)setRadius:(float)radius;

/**
 *
 * @brief Method is used to enable or disable collision detection for the circle.
 * @param enabled Specifies whether collision detection is enabled (true) or disabled (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setCollisionEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setCollisionEnabled
 *
 *
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 *
 * @brief Method is used to specify the buffer size around the circle for collision detection.
 * @param width Width of the buffer in pixels. Default: 0.
 * @param height Height of the buffer in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setBuffer
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setBuffer
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
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setOffset
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setOffset
 *
 *
 */
- (BOOL)setOffset:(float)width
           height:(float)height;

/**
 *
 * @brief Method is used to specify the priority of the circle.
 * @param priority The priority value for rendering or interaction. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setPriority
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setPriority
 *
 *
 */
- (BOOL)setPriority:(float)priority;

/**
 *
 * @brief Method is used to specify the color of the circle’s outline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setOutlineColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setOutlineColor
 *
 *
 */
- (BOOL)setOutlineColor:(float)red
                  green:(float)green
                   blue:(float)blue
                  alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the thickness of the circle’s outline.
 * @param radius Thickness of the outline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setOutlineRadius
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setOutlineRadius
 *
 *
 */
- (BOOL)setOutlineRadius:(float)radius;

/**
 *
 * @brief Method is used to specify the opacity of the circle’s outline.
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_CircleMapObject_setOutlineAlpha
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_CircleMapObject_setOutlineAlpha
 *
 *
 */
- (BOOL)setOutlineAlpha:(float)alpha;

@end
