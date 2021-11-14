#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

NAVIGINE_EXPORT
@interface NCLocationPoint : NSObject
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                           locationId:(int32_t)locationId
                        sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPointWithPoint:(nonnull NCPoint *)point
                                    locationId:(int32_t)locationId
                                 sublocationId:(int32_t)sublocationId;

@property (nonatomic, readonly, nonnull) NCPoint * point;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@end
