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
 */
@property (nonatomic, readonly, nonnull) NCPoint * start;

/**
 * @brief End point of the segment.
 */
@property (nonatomic, readonly, nonnull) NCPoint * end;

@end
