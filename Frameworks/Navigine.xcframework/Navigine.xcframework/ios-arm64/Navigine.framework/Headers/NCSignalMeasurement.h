#import "NCExport.h"
#import "NCSignalType.h"
#import <Foundation/Foundation.h>

/**
 * @file NCSignalMeasurement.h
 * @brief @copybrief NCSignalMeasurement
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Structure representing a signal measurement with type, identifier, RSSI, distance, and timestamp.
 *
 * Referenced from @see MeasurementListener "MeasurementListener".
 *
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

/**
 * @brief Type of the signal
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SignalMeasurement_getType
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SignalMeasurement_getType
 *
 *
 */
@property (nonatomic, readonly) NCSignalType type;

/**
 * @brief Unique identifier of the signal (e.g., MAC address or UUID)
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SignalMeasurement_getId
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SignalMeasurement_getId
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSString * id;

/**
 * @brief Received Signal Strength Indicator (RSSI) in dBm
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SignalMeasurement_getRssi
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SignalMeasurement_getRssi
 *
 *
 */
@property (nonatomic, readonly) float rssi;

/**
 * @brief Estimated distance to the signal source in meters
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SignalMeasurement_getDistance
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SignalMeasurement_getDistance
 *
 *
 */
@property (nonatomic, readonly) float distance;

/**
 * @brief Timestamp of the measurement in milliseconds
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SignalMeasurement_getTime
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SignalMeasurement_getTime
 *
 *
 */
@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSignalMeasurement *)other;

@end
