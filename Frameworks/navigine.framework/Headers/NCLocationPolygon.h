#import "NCPolygon.h"
#import <Foundation/Foundation.h>

@interface NCLocationPolygon : NSObject
- (nonnull instancetype)initWithPolygon:(nonnull NCPolygon *)polygon
                             locationId:(int32_t)locationId
                          sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPolygonWithPolygon:(nonnull NCPolygon *)polygon
                                        locationId:(int32_t)locationId
                                     sublocationId:(int32_t)sublocationId;

@property (nonatomic, readonly, nonnull) NCPolygon * polygon;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@end
