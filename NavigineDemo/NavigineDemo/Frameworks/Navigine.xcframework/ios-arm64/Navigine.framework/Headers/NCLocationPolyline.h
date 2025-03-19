#import "NCExport.h"
#import "NCPolyline.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLocationPolyline.h
 * @brief @copybrief NCLocationPolyline
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief Class is used for representing certain polyline within the location @see Polyline "Polyline"
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolyline : NSObject

/** 
 * @brief Default constructor for class NCLocationPolyline 
 */
- (nonnull instancetype)initWithPolyline:(nonnull NCPolyline *)polyline
                              locationId:(int32_t)locationId
                           sublocationId:(int32_t)sublocationId;

/** 
 * @brief Factory method for class NCLocationPolyline 
 */
+ (nonnull instancetype)locationPolylineWithPolyline:(nonnull NCPolyline *)polyline
                                          locationId:(int32_t)locationId
                                       sublocationId:(int32_t)sublocationId;

/**
 *
 * @brief Metrics polyline @see Polyline.
 *
 */
@property (nonatomic, readonly, nonnull) NCPolyline * polyline;

/**
 *
 * @brief location polyline location identifier.
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 *
 * @brief location polyline sublocation identifier.
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
