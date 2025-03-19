#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCPolyline.h
 * @brief @copybrief NCPolyline
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A polyline with specified number of points.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolyline : NSObject

/** 
 * @brief Default constructor for class NCPolyline 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;

/** 
 * @brief Factory method for class NCPolyline 
 */
+ (nonnull instancetype)polylineWithPoints:(nonnull NSArray<NCPoint *> *)points;

/**
 * @brief List of points to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
