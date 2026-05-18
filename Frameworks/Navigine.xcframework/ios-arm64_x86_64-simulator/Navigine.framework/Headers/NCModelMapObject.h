#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import "NCModelProvider.h"
#import <Foundation/Foundation.h>


/**
 * @file NCModelMapObject.h
 * @brief @copybrief NCModelMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief A 3D model map object (Wavefront OBJ) placed on the location view.
 *
 * Geometry and texture come from @see ModelProvider "ModelProvider". The mesh is loaded asynchronously in the render pipeline; blocking calls occur only inside provider callbacks.
 *
 * Referenced from @see LocationWindow "LocationWindow" (addModelMapObject).
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCModelMapObject : NCMapObject

/**
 * @brief Sets the anchor position of the model in metric coordinates.
 * @param point Center / placement point @see LocationPoint "LocationPoint".
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setPosition
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setPosition
 *
 *
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 * @brief Animates the model anchor to a new position.
 * @param point Target metrics coordinates @see LocationPoint "LocationPoint".
 * @param duration Animation duration in seconds.
 * @param type Animation easing @see AnimationType "AnimationType".
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setPositionAnimated
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setPositionAnimated
 *
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 * @brief Sets the 3D asset (OBJ source + texture ImageProvider).
 * @param model Model provider @see ModelProvider "ModelProvider".
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setModel
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setModel
 *
 *
 */
- (BOOL)setModel:(nullable id<NCModelProvider>)model;

/**
 * @brief Sets the on-screen size of the model in pixels (width and height).
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setSize
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setSize
 *
 *
 */
- (BOOL)setSize:(float)width
         height:(float)height;

/**
 * @brief Enables or disables collision tests for this object.
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setCollisionEnabled
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setCollisionEnabled
 *
 *
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 * @brief Sets rotation angle in degrees (around the placement axis used by the engine).
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setAngle
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setAngle
 *
 *
 */
- (BOOL)setAngle:(float)angle;

/**
 * @brief Animates rotation to the given angle.
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setAngleAnimated
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setAngleAnimated
 *
 *
 */
- (BOOL)setAngleAnimated:(float)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

/**
 * @brief Extra hit-test padding around the model in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setBuffer
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setBuffer
 *
 *
 */
- (BOOL)setBuffer:(float)width
           height:(float)height;

/**
 * @brief Render order priority (higher draws above).
 * @return true if the operation is successful, false otherwise.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowMapObjectsExample.swift swift_ModelMapObject_setPriority
 *
 *Objective C code snippet:
 *@snippet LocationWindowMapObjectsExample.m objc_ModelMapObject_setPriority
 *
 *
 */
- (BOOL)setPriority:(float)priority;

@end
