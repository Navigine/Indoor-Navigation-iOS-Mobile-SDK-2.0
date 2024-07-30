#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>

/**
 *
 * Polygon at specified location and sublocation
 * Units: meters
 * Origin: bottom left corner
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolygon : NSObject
- (nonnull instancetype)initWithPolygon:(nonnull NCPolygon *)polygon
                             locationId:(int32_t)locationId
                          sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPolygonWithPolygon:(nonnull NCPolygon *)polygon
                                        locationId:(int32_t)locationId
                                     sublocationId:(int32_t)sublocationId;

/**
 *
 * Metrics polygon (@see Polygon).
 *
 */
@property (nonatomic, readonly, nonnull) NCPolygon * polygon;

/**
 *
 * Location unique identifier in CMS
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 *
 * Sublocation unique identifier in CMS
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
