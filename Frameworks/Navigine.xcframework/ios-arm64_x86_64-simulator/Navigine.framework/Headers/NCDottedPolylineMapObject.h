#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import "NCPlacement.h"
#import <Foundation/Foundation.h>


/**
 * @file NCDottedPolylineMapObject.h
 * @brief @copybrief NCDottedPolylineMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Represents a polyline object with points placed along it on the location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCDottedPolylineMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify the source polyline for the points.
 * @param polyline Metrics coordinates of the polyline @see LocationPolyline "LocationPolyline".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setPolyline
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setPolyline
 *
 *
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

/**
 *
 * @brief Method is used to specify the color of the object.
 * @param red Red RGBA component.
 * @param green Green RGBA component.
 * @param blue Blue RGBA component.
 * @param alpha Opacity multiplier. Values below 0 will be set to 0. Default: 1.
 * @return true if success, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setColor
 *
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the size of the points.
 * @param width Width of the points in pixels.
 * @param height Height of the points in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setSize
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setSize
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
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setCollisionEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setCollisionEnabled
 *
 *
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 *
 * @brief Method is used to specify the placement mode for points along the polyline.
 * @param placement The placement mode @see Placement "Placement". Default: VERTEX.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setPlacement
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setPlacement
 *
 *
 */
- (BOOL)setPlacement:(NCPlacement)placement;

/**
 *
 * @brief Method is used to specify the minimum ratio of the polyline length for point placement.
 * @param ratio The minimum ratio of the polyline length (typically between 0 and 1). Default: 1.0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setPlacementMinRatio
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setPlacementMinRatio
 *
 *
 */
- (BOOL)setPlacementMinRatio:(float)ratio;

/**
 *
 * @brief Method is used to specify the spacing between points for spaced placement.
 * @param spacing The spacing distance in pixels. Default: 80.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setPlacementSpacing
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setPlacementSpacing
 *
 *
 */
- (BOOL)setPlacementSpacing:(float)spacing;

/**
 *
 * @brief Method is used to specify the distance interval for repeating points along the polyline.
 * @param distance The repeat distance in pixels. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setRepeatDistance
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setRepeatDistance
 *
 *
 */
- (BOOL)setRepeatDistance:(float)distance;

/**
 *
 * @brief Method is used to specify the group identifier for repeating points.
 * @param group The group identifier for point repetition. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setRepeatGroup
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setRepeatGroup
 *
 *
 */
- (BOOL)setRepeatGroup:(int32_t)group;

/**
 *
 * @brief Method is used to specify the priority of the icon.
 * @param priority The priority value for rendering or interaction. Default: max.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_DottedPolylineMapObject_setPriority
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_DottedPolylineMapObject_setPriority
 *
 *
 */
- (BOOL)setPriority:(float)priority;

@end
