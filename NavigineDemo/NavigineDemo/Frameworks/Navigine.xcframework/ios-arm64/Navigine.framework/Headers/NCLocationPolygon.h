#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLocationPolygon.h
 * @brief @copybrief NCLocationPolygon
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief Class is used for representing certain polygon within the location @see Polygon "Polygon"
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolygon : NSObject

/** 
 * @brief Default constructor for class NCLocationPolygon 
 */
- (nonnull instancetype)initWithPolygon:(nonnull NCPolygon *)polygon
                             locationId:(int32_t)locationId
                          sublocationId:(int32_t)sublocationId;

/** 
 * @brief Factory method for class NCLocationPolygon 
 */
+ (nonnull instancetype)locationPolygonWithPolygon:(nonnull NCPolygon *)polygon
                                        locationId:(int32_t)locationId
                                     sublocationId:(int32_t)sublocationId;

/**
 *
 * @brief Metrics polygon @see Polygon "Polygon".
 *
 */
@property (nonatomic, readonly, nonnull) NCPolygon * polygon;

/**
 *
 * @brief location polygon location identifier.
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 *
 * @brief location polygon sublocation identifier.
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
