#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCPoint.h
 * @brief @copybrief NCPoint
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A point at the specified metrics coordinates.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Point_constructor
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Point_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPoint : NSObject

/** 
 * @brief Default constructor for class NCPoint 
 */
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y;

/** 
 * @brief Factory method for class NCPoint 
 */
+ (nonnull instancetype)pointWithX:(float)x
                                 y:(float)y;

/**
 * @brief point's `x` coordinate in meters.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Point_getX
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Point_getX
 *
 *
 */
@property (nonatomic, readonly) float x;

/**
 * @brief point's `y` coordinate in meters.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Point_getY
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Point_getY
 *
 *
 */
@property (nonatomic, readonly) float y;

@end
