#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCSegment.h
 * @brief @copybrief NCSegment
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief line between two points.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Segment_constructor
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Segment_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSegment : NSObject

/** 
 * @brief Default constructor for class NCSegment 
 */
- (nonnull instancetype)initWithStart:(nonnull NCPoint *)start
                                  end:(nonnull NCPoint *)end;

/** 
 * @brief Factory method for class NCSegment 
 */
+ (nonnull instancetype)segmentWithStart:(nonnull NCPoint *)start
                                     end:(nonnull NCPoint *)end;

/**
 * @brief Start point of the segment.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Segment_getStart
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Segment_getStart
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCPoint * start;

/**
 * @brief End point of the segment.
 *
 *
 * Swift code snippet:
 * @snippet GeometryUtilsExample.swift swift_Segment_getEnd
 *
 * Objective C code snippet:
 * @snippet GeometryUtilsExample.m objc_Segment_getEnd
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCPoint * end;

@end
