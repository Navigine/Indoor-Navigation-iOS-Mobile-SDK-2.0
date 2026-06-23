#import "NCExport.h"
#import "NCSensorType.h"
#import "NCVector3d.h"
#import <Foundation/Foundation.h>

/**
 * Structure representing a sensor measurement with type, values, and timestamp.
 * Referenced from ``NCMeasurementListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSensorMeasurement : NSObject

/** 
 * Default constructor for class NCSensorMeasurement 
 */
- (nonnull instancetype)initWithType:(NCSensorType)type
                              values:(nonnull NCVector3d *)values
                                time:(int64_t)time;

/** 
 * Factory method for class NCSensorMeasurement 
 */
+ (nonnull instancetype)sensorMeasurementWithType:(NCSensorType)type
                                           values:(nonnull NCVector3d *)values
                                             time:(int64_t)time;

/**
 * Type of the sensor
 *
 * @discussion Example:
 * @code
 * // Get sensor type
 * NCSensorType type = measurement.type;
 * NSLog(@"Sensor type: %ld", (long)type);
 * @endcode
 */
@property (nonatomic, readonly) NCSensorType type;

/**
 * 3D vector containing sensor measurement values
 *
 * @discussion Example:
 * @code
 * // Get sensor values
 * NCVector3d *values = measurement.values;
 * NSLog(@"Sensor values - X: %f, Y: %f, Z: %f", values.x, values.y, values.z);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCVector3d * values;

/**
 * Timestamp of the measurement in milliseconds
 *
 * @discussion Example:
 * @code
 * // Get measurement timestamp
 * long long time = measurement.time;
 * NSLog(@"Measurement time: %lld ms", time);
 * @endcode
 */
@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSensorMeasurement *)other;

@end
