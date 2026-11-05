#import "NCExport.h"
#import "NCSensorMeasurement.h"
#import "NCSensorType.h"
#import "NCSignalMeasurement.h"
#import <Foundation/Foundation.h>


/**
 * Class provides callbacks to be invoked when ``NCMeasurementManager``
 * detects new sensor or signal measurements.
 * Referenced from ``NCMeasurementManager``.
 * @discussion Note: The callbacks are invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCMeasurementListener <NSObject>

/**
 * Called when new sensor measurements are detected.
 * @param sensors A map of sensor types to their corresponding ``NCSensorMeasurement`` values.
 *
 * @discussion Example:
 * @code
 * - (void)onSensorMeasurementDetected:(NSDictionary<NSNumber *, NCSensorMeasurement *> *)sensors {
 *    NSLog(@"Sensor measurements detected");
 *    [self.example demonstrateSensorMeasurements:sensors];
 * }
 * @endcode
 */
- (void)onSensorMeasurementDetected:(nonnull NSDictionary<NSNumber *, NCSensorMeasurement *> *)sensors;

/**
 * Called when new signal measurements are detected.
 * @param signals A map of signal identifiers to their corresponding ``NCSignalMeasurement`` values.
 *
 * @discussion Example:
 * @code
 * - (void)onSignalMeasurementDetected:(NSDictionary<NSString *, NCSignalMeasurement *> *)signals {
 *    NSLog(@"Signal measurements detected");
 *    [self.example demonstrateSignalMeasurements:signals];
 * }
 * @endcode
 */
- (void)onSignalMeasurementDetected:(nonnull NSDictionary<NSString *, NCSignalMeasurement *> *)signals;

@end
