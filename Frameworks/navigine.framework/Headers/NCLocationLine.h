#import "NCLine.h"
#import <Foundation/Foundation.h>

@interface NCLocationLine : NSObject
- (nonnull instancetype)initWithLine:(nonnull NCLine *)line
                          locationId:(int32_t)locationId
                       sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationLineWithLine:(nonnull NCLine *)line
                                  locationId:(int32_t)locationId
                               sublocationId:(int32_t)sublocationId;

@property (nonatomic, readonly, nonnull) NCLine * line;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@end
