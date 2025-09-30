#import "NCCapType.h"
#import "NCExport.h"
#import "NCJoinType.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCPolylineMapObject.h
 * @brief @copybrief NCPolylineMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Represents a polyline object on the location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolylineMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify the source polyline of the object.
 * @param polyline Metrics coordinates of the polyline @see LocationPolyline "LocationPolyline".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setPolyLine
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setPolyLine
 *
 *
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

/**
 *
 * @brief Method is used to specify the width of the polyline.
 * @param width Width of the polyline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setWidth
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setWidth
 *
 *
 */
- (BOOL)setWidth:(float)width;

/**
 *
 * @brief Method is used to specify the fill color of the polyline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setColor
 *
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the rendering order of the polyline.
 * @param order The rendering order value. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOrder
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOrder
 *
 *
 */
- (BOOL)setOrder:(int32_t)order;

/**
 *
 * @brief Method is used to specify the cap style for the polyline ends.
 * @param cap The cap type @see CapType "CapType". Default: BUTT.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setCapType
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setCapType
 *
 *
 */
- (BOOL)setCapType:(NCCapType)cap;

/**
 *
 * @brief Method is used to specify the join style for polyline segments.
 * @param join The join type @see JoinType "JoinType". Default: MITER.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setJoinType
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setJoinType
 *
 *
 */
- (BOOL)setJoinType:(NCJoinType)join;

/**
 *
 * @brief Method is used to specify the miter limit for miter joins.
 * @param miterLimit The miter limit value for miter joins. Default: 3.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setMiterLimit
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setMiterLimit
 *
 *
 */
- (BOOL)setMiterLimit:(float)miterLimit;

/**
 *
 * @brief Method is used to specify the color of the polyline’s outline.
 * @param red Red RGBA component (0 to 1).
 * @param green Green RGBA component (0 to 1).
 * @param blue Blue RGBA component (0 to 1).
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineColor
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineColor
 *
 *
 */
- (BOOL)setOutlineColor:(float)red
                  green:(float)green
                   blue:(float)blue
                  alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the width of the polyline’s outline.
 * @param radius Width of the outline in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineWidth
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineWidth
 *
 *
 */
- (BOOL)setOutlineWidth:(float)radius;

/**
 *
 * @brief Method is used to specify the opacity of the polyline’s outline.
 * @param alpha Opacity multiplier (0 to 1). Values below 0 are set to 0. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineAlpha
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineAlpha
 *
 *
 */
- (BOOL)setOutlineAlpha:(float)alpha;

/**
 *
 * @brief Method is used to specify the cap style for the polyline’s outline ends.
 * @param cap The cap type @see CapType "CapType". Default: BUTT.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineCapType
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineCapType
 *
 *
 */
- (BOOL)setOutlineCapType:(NCCapType)cap;

/**
 *
 * @brief Method is used to specify the join style for the polyline’s outline segments.
 * @param join The join type @see JoinType "JoinType". Default: MITER.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineJoinType
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineJoinType
 *
 *
 */
- (BOOL)setOutlineJoinType:(NCJoinType)join;

/**
 *
 * @brief Method is used to specify the miter limit for the polyline’s outline miter joins.
 * @param miterLimit The miter limit value for outline miter joins. Default: 3.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineMiterLimit
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineMiterLimit
 *
 *
 */
- (BOOL)setOutlineMiterLimit:(float)miterLimit;

/**
 *
 * @brief Method is used to specify the rendering order of the polyline’s outline.
 * @param order The rendering order value for the outline. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_PolylineMapObject_setOutlineOrder
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_PolylineMapObject_setOutlineOrder
 *
 *
 */
- (BOOL)setOutlineOrder:(int32_t)order;

@end
