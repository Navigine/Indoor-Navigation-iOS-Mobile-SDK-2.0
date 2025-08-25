#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCPolygon.h
 * @brief @copybrief NCPolygon
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A polygon with specified list of points.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Polygon_constructor
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Polygon_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygon : NSObject

/** 
 * @brief Default constructor for class NCPolygon 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;

/** 
 * @brief Factory method for class NCPolygon 
 */
+ (nonnull instancetype)polygonWithPoints:(nonnull NSArray<NCPoint *> *)points;

/**
 * @brief Ring specifying the area.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Polygon_getPoints
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Polygon_getPoints
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
