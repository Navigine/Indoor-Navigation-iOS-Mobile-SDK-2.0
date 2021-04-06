#import "NCSensorType.h"
#import "NCVector3d.h"
#import <Foundation/Foundation.h>

@interface NCSensorMeasurement : NSObject
- (nonnull instancetype)initWithType:(NCSensorType)type
                              values:(nonnull NCVector3d *)values;
+ (nonnull instancetype)sensorMeasurementWithType:(NCSensorType)type
                                           values:(nonnull NCVector3d *)values;

@property (nonatomic, readonly) NCSensorType type;

@property (nonatomic, readonly, nonnull) NCVector3d * values;

- (NSComparisonResult)compare:(nonnull NCSensorMeasurement *)other;

@end
