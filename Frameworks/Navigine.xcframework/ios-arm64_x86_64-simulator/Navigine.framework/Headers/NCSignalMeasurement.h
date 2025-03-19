#import "NCExport.h"
#import "NCSignalType.h"
#import <Foundation/Foundation.h>

/**
 * @file NCSignalMeasurement.h
 * @brief @copybrief NCSignalMeasurement
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSignalMeasurement : NSObject

/** 
 * @brief Default constructor for class NCSignalMeasurement 
 */
- (nonnull instancetype)initWithType:(NCSignalType)type
                                  id:(nonnull NSString *)id
                                rssi:(float)rssi
                            distance:(float)distance
                                time:(int64_t)time;

/** 
 * @brief Factory method for class NCSignalMeasurement 
 */
+ (nonnull instancetype)signalMeasurementWithType:(NCSignalType)type
                                               id:(nonnull NSString *)id
                                             rssi:(float)rssi
                                         distance:(float)distance
                                             time:(int64_t)time;

@property (nonatomic, readonly) NCSignalType type;

@property (nonatomic, readonly, nonnull) NSString * id;

@property (nonatomic, readonly) float rssi;

@property (nonatomic, readonly) float distance;

@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSignalMeasurement *)other;

@end
