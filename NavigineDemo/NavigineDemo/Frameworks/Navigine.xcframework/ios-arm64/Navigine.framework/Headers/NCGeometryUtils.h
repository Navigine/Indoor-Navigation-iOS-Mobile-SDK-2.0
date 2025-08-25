#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCPoint.h"
#import "NCPolygon.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>


/**
 * @file NCGeometryUtils.h
 * @brief @copybrief NCGeometryUtils
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A set of functions for working with geometries.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGeometryUtils : NSObject

/**
 * @brief Get distance between GPS points
 * @param from start point of calculation @see GlobalPoint "GlobalPoint"
 * @param to end point of calculation @see GlobalPoint "GlobalPoint"
 * @return distance in meters
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_distanceBetweenGlobalPoints
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_distanceBetweenGlobalPoints
 *
 *
 */
+ (float)distanceBetweenGlobalPoints:(nonnull NCGlobalPoint *)from
                                  to:(nonnull NCGlobalPoint *)to;

/**
 * @brief Get distance between points
 * @param from start point of calculation @see Point "Point"
 * @param to end point of calculation @see Point "Point"
 * @return distance in meters
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_distanceBetweenPoints
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_distanceBetweenPoints
 *
 *
 */
+ (float)distanceBetweenPoints:(nonnull NCPoint *)from
                            to:(nonnull NCPoint *)to;

/**
 * @brief Get length of segment
 * @param segment segment object for calculation @see Segment "Segment"
 * @return length in meters
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_segmentLength
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_segmentLength
 *
 *
 */
+ (float)segmentLength:(nonnull NCSegment *)segment;

/**
 * @brief Get polygon area
 * @param polygon polygon object for calculation @see Polygon "Polygon"
 * @return area in meters
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_polygonArea
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_polygonArea
 *
 *
 */
+ (float)polygonArea:(nonnull NCPolygon *)polygon;

/**
 * @brief Get polygon geometric center
 * @param polygon polygon object for calculation @see Polygon "Polygon"
 * @return center point @see Point "Point"
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_polygonCenter
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_polygonCenter
 *
 *
 */
+ (nonnull NCPoint *)polygonCenter:(nonnull NCPolygon *)polygon;

/**
 * @brief Checks that polygon contains point
 * @param polygon polygon object in which looking for contents @see Polygon "Polygon"
 * @param point checking point object @see Point "Point"
 * @return contains or not
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_polygonContainsPoint
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_polygonContainsPoint
 *
 *
 */
+ (BOOL)polygonContainsPoint:(nonnull NCPolygon *)polygon
                       point:(nonnull NCPoint *)point;

/**
 * @brief Get distance from segment to point
 * @param segment start segment of calculation @see Segment "Segment"
 * @param point end point of calculation @see Point "Point"
 * @return distance in meters
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_segmentPointDistance
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_segmentPointDistance
 *
 *
 */
+ (float)segmentPointDistance:(nonnull NCSegment *)segment
                        point:(nonnull NCPoint *)point;

/**
 * @brief Checks the intersection of two segments
 * @param segment1 first segment of calculation @see Segment "Segment"
 * @param segment2 second segment of calculation @see Segment "Segment"
 * @return intersects or not
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_segmentIntersectsSegment
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_segmentIntersectsSegment
 *
 *
 */
+ (BOOL)segmentIntersectsSegment:(nonnull NCSegment *)segment1
                        segment2:(nonnull NCSegment *)segment2;

/**
 * @brief Calculate the intersection point of two segments
 * @param segment1 first segment of calculation @see Segment "Segment"
 * @param segment2 second segment of calculation @see Segment "Segment"
 * @return intersection point @see Point "Point"
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_segmentIntersectionSegment
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_segmentIntersectionSegment
 *
 *
 */
+ (nonnull NCPoint *)segmentIntersectionSegment:(nonnull NCSegment *)segment1
                                       segment2:(nonnull NCSegment *)segment2;

/**
 * @brief Calculate the division ratio of a segment by a given segment(if intersects)
 * @param segment1 first segment of calculation @see Segment "Segment"
 * @param segment2 second segment of calculation @see Segment "Segment"
 * @return division ratio
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_divisionRatioBySegment
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_divisionRatioBySegment
 *
 *
 */
+ (float)divisionRatioBySegment:(nonnull NCSegment *)segment1
                       segment2:(nonnull NCSegment *)segment2;

/**
 * @brief Calculate projection point on a segment
 * @param segment segment of calculation @see Segment "Segment"
 * @param r division ratio
 * @return ratio point @see Point "Point"
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_getRatioPoint
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_getRatioPoint
 *
 *
 */
+ (nonnull NCPoint *)getRatioPoint:(nonnull NCSegment *)segment
                                 r:(double)r;

/**
 * @brief Calculate the division ratio of a segment by a given point
 * Calculate projection point on a segment
 * @param segment segment of calculation @see Segment "Segment"
 * @param point point of calculation @see Point "Point"
 * @return division ratio
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_GeometryUtils_getProjectionRatio
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_GeometryUtils_getProjectionRatio
 *
 *
 */
+ (double)getProjectionRatio:(nonnull NCSegment *)segment
                       point:(nonnull NCPoint *)point;

@end
