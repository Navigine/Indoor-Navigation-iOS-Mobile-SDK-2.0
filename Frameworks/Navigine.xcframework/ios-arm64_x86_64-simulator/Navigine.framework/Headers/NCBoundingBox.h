#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCBoundingBox.h
 * @brief @copybrief NCBoundingBox
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief Axis-aligned bounding box defined by two corner points.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_BoundingBox_constructor
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_BoundingBox_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBoundingBox : NSObject

/** 
 * @brief Default constructor for class NCBoundingBox 
 */
- (nonnull instancetype)initWithBottomLeft:(nonnull NCPoint *)bottomLeft
                                  topRight:(nonnull NCPoint *)topRight;

/** 
 * @brief Factory method for class NCBoundingBox 
 */
+ (nonnull instancetype)boundingBoxWithBottomLeft:(nonnull NCPoint *)bottomLeft
                                         topRight:(nonnull NCPoint *)topRight;

/**
 * @brief Lower-left corner of the bounding box.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_BoundingBox_getBottomLeft
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_BoundingBox_getBottomLeft
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCPoint * bottomLeft;

/**
 * @brief Upper-right corner of the bounding box.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_BoundingBox_getTopRight
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_BoundingBox_getTopRight
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCPoint * topRight;

@end
