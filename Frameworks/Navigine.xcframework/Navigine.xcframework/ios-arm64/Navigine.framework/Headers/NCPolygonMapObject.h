#import "NCExport.h"
#import "NCLocationPolygon.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCPolygonMapObject.h
 * @brief @copybrief NCPolygonMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Represents a polygon object on the location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygonMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify the source polygon of the object.
 * @param polygon Metrics coordinates of the polygon @see LocationPolygon "LocationPolygon".
 * @return true if success, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolygonMapObject_setPolygon
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolygonMapObject_setPolygon
 *
 *
 */
- (BOOL)setPolygon:(nonnull NCLocationPolygon *)polygon;

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
 * @snippet LocationWindowMapObjectsExample.swift swift_PolygonMapObject_setColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolygonMapObject_setColor
 *
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the rendering order of the object.
 * @param order The rendering order value. Default: 0.
 * @return true if success, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolygonMapObject_setOrder
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolygonMapObject_setOrder
 *
 *
 */
- (BOOL)setOrder:(int32_t)order;

@end
