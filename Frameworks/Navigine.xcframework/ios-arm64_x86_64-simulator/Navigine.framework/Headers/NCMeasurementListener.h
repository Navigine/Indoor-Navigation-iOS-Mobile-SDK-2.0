#import "NCExport.h"
#import "NCSensorMeasurement.h"
#import "NCSensorType.h"
#import "NCSignalMeasurement.h"
#import <Foundation/Foundation.h>


/**
 * @file NCMeasurementListener.h
 * @brief @copybrief NCMeasurementListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCMeasurementListener <NSObject>

- (void)onSensorMeasurementDetected:(nonnull NSDictionary<NSNumber *, NCSensorMeasurement *> *)sensors;

- (void)onSignalMeasurementDetected:(nonnull NSDictionary<NSString *, NCSignalMeasurement *> *)signals;

@end
