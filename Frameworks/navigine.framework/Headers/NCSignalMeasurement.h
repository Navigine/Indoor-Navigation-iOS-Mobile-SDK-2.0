#import "NCSignalType.h"
#import <Foundation/Foundation.h>

@interface NCSignalMeasurement : NSObject
- (nonnull instancetype)initWithType:(NCSignalType)type
                                  id:(nonnull NSString *)id
                                rssi:(float)rssi
                            distance:(float)distance;
+ (nonnull instancetype)signalMeasurementWithType:(NCSignalType)type
                                               id:(nonnull NSString *)id
                                             rssi:(float)rssi
                                         distance:(float)distance;

@property (nonatomic, readonly) NCSignalType type;

@property (nonatomic, readonly, nonnull) NSString * id;

@property (nonatomic, readonly) float rssi;

@property (nonatomic, readonly) float distance;

- (NSComparisonResult)compare:(nonnull NCSignalMeasurement *)other;

@end
