#import "NCExport.h"
#import "NCSensorMeasurement.h"
#import "NCSensorType.h"
#import "NCSignalMeasurement.h"
#import <Foundation/Foundation.h>


/**
 * @file NCMeasurementListener.h
 * @brief @copybrief NCMeasurementListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides callbacks to be invoked when @see MeasurementManager "MeasurementManager"
 * detects new sensor or signal measurements.
 *
 * Referenced from @see MeasurementManager "MeasurementManager".
 *
 * @note The callbacks are invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCMeasurementListener <NSObject>

/**
 *
 * @brief Called when new sensor measurements are detected.
 * @param sensors A map of sensor types to their corresponding @see SensorMeasurement "SensorMeasurement" values.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementListener_onSensorMeasurementDetected
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementListener_onSensorMeasurementDetected
 *
 *
 */
- (void)onSensorMeasurementDetected:(nonnull NSDictionary<NSNumber *, NCSensorMeasurement *> *)sensors;

/**
 *
 * @brief Called when new signal measurements are detected.
 * @param signals A map of signal identifiers to their corresponding @see SignalMeasurement "SignalMeasurement" values.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementListener_onSignalMeasurementDetected
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementListener_onSignalMeasurementDetected
 *
 *
 */
- (void)onSignalMeasurementDetected:(nonnull NSDictionary<NSString *, NCSignalMeasurement *> *)signals;

@end
