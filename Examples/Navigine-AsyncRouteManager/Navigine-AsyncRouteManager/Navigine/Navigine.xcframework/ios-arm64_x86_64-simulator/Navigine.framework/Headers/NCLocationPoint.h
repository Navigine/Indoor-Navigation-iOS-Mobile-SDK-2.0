#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 *
 * Point at specified location and sublocation
 * Units: meters
 * Origin: bottom left corner
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPoint : NSObject
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                           locationId:(int32_t)locationId
                        sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPointWithPoint:(nonnull NCPoint *)point
                                    locationId:(int32_t)locationId
                                 sublocationId:(int32_t)sublocationId;

/**
 *
 * Metrics coordinates (@see Point).
 *
 */
@property (nonatomic, readonly, nonnull) NCPoint * point;

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
