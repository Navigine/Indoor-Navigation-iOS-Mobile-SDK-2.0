#import "NCExport.h"
#import "NCSensorType.h"
#import "NCVector3d.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCSensorMeasurement : NSObject
- (nonnull instancetype)initWithType:(NCSensorType)type
                              values:(nonnull NCVector3d *)values
                                time:(int64_t)time;
+ (nonnull instancetype)sensorMeasurementWithType:(NCSensorType)type
                                           values:(nonnull NCVector3d *)values
                                             time:(int64_t)time;

@property (nonatomic, readonly) NCSensorType type;

@property (nonatomic, readonly, nonnull) NCVector3d * values;

@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSensorMeasurement *)other;

@end
