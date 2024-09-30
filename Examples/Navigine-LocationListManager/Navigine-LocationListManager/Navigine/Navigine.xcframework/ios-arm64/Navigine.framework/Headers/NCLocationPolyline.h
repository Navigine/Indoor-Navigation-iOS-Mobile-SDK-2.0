#import "NCExport.h"
#import "NCPolyline.h"
#import <Foundation/Foundation.h>

/**
 *
 * Polyline at specified location and sublocation
 * Units: meters
 * Origin: bottom left corner
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolyline : NSObject
- (nonnull instancetype)initWithPolyline:(nonnull NCPolyline *)polyline
                              locationId:(int32_t)locationId
                           sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPolylineWithPolyline:(nonnull NCPolyline *)polyline
                                          locationId:(int32_t)locationId
                                       sublocationId:(int32_t)sublocationId;

/**
 *
 * Metrics polyline (@see Polyline).
 *
 */
@property (nonatomic, readonly, nonnull) NCPolyline * polyline;

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
