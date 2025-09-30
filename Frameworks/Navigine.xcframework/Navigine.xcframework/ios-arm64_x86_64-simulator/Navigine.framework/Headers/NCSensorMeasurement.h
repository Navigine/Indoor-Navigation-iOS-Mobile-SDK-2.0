#import "NCExport.h"
#import "NCSensorType.h"
#import "NCVector3d.h"
#import <Foundation/Foundation.h>

/**
 * @file NCSensorMeasurement.h
 * @brief @copybrief NCSensorMeasurement
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Structure representing a sensor measurement with type, values, and timestamp.
 *
 * Referenced from @see MeasurementListener "MeasurementListener".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSensorMeasurement : NSObject

/** 
 * @brief Default constructor for class NCSensorMeasurement 
 */
- (nonnull instancetype)initWithType:(NCSensorType)type
                              values:(nonnull NCVector3d *)values
                                time:(int64_t)time;

/** 
 * @brief Factory method for class NCSensorMeasurement 
 */
+ (nonnull instancetype)sensorMeasurementWithType:(NCSensorType)type
                                           values:(nonnull NCVector3d *)values
                                             time:(int64_t)time;

/**
 * @brief Type of the sensor
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SensorMeasurement_getType
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SensorMeasurement_getType
 *
 *
 */
@property (nonatomic, readonly) NCSensorType type;

/**
 * @brief 3D vector containing sensor measurement values
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SensorMeasurement_getValues
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SensorMeasurement_getValues
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCVector3d * values;

/**
 * @brief Timestamp of the measurement in milliseconds
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_SensorMeasurement_getTime
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_SensorMeasurement_getTime
 *
 *
 */
@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSensorMeasurement *)other;

@end
