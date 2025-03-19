#import "NCExport.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLine.h
 * @brief @copybrief NCLine
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A polyline with specified list of segments @see Segment "Segment"
 *
 * Referenced from @see PolylineMapObject "PolylineMapObject".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLine : NSObject

/** 
 * @brief Default constructor for class NCLine 
 */
- (nonnull instancetype)initWithSegments:(nonnull NSArray<NCSegment *> *)segments;

/** 
 * @brief Factory method for class NCLine 
 */
+ (nonnull instancetype)lineWithSegments:(nonnull NSArray<NCSegment *> *)segments;

/**
 * List of segments to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCSegment *> * segments;

@end
