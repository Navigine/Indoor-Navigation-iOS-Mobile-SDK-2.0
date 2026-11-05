#import "NCExport.h"
#import "NCSignalType.h"
#import <Foundation/Foundation.h>

/**
 * Structure representing a signal measurement with type, identifier, RSSI, distance, and timestamp.
 * Referenced from ``NCMeasurementListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSignalMeasurement : NSObject

/** 
 * Default constructor for class NCSignalMeasurement 
 */
- (nonnull instancetype)initWithType:(NCSignalType)type
                                  id:(nonnull NSString *)id
                                rssi:(float)rssi
                            distance:(float)distance
                                time:(int64_t)time;

/** 
 * Factory method for class NCSignalMeasurement 
 */
+ (nonnull instancetype)signalMeasurementWithType:(NCSignalType)type
                                               id:(nonnull NSString *)id
                                             rssi:(float)rssi
                                         distance:(float)distance
                                             time:(int64_t)time;

/**
 * Type of the signal
 *
 * @discussion Example:
 * @code
 * // Get signal type
 * NCSignalType type = measurement.type;
 * NSLog(@"Signal type: %ld", (long)type);
 * @endcode
 */
@property (nonatomic, readonly) NCSignalType type;

/**
 * Unique identifier of the signal (e.g., MAC address or UUID)
 *
 * @discussion Example:
 * @code
 * // Get signal identifier
 * NSString *id = measurement.id;
 * NSLog(@"Signal ID: %@", id);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSString * id;

/**
 * Received Signal Strength Indicator (RSSI) in dBm
 *
 * @discussion Example:
 * @code
 * // Get RSSI value
 * double rssi = measurement.rssi;
 * NSLog(@"Signal RSSI: %f dBm", rssi);
 * @endcode
 */
@property (nonatomic, readonly) float rssi;

/**
 * Estimated distance to the signal source in meters
 *
 * @discussion Example:
 * @code
 * // Get estimated distance
 * double distance = measurement.distance;
 * NSLog(@"Signal distance: %f meters", distance);
 * @endcode
 */
@property (nonatomic, readonly) float distance;

/**
 * Timestamp of the measurement in milliseconds
 *
 * @discussion Example:
 * @code
 * // Get measurement timestamp
 * long long time = measurement.time;
 * NSLog(@"Signal measurement time: %lld ms", time);
 * @endcode
 */
@property (nonatomic, readonly) int64_t time;

- (NSComparisonResult)compare:(nonnull NCSignalMeasurement *)other;

@end
