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
 */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
