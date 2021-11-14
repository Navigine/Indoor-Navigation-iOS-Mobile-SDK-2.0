#import "NCExport.h"
#import "NCSensorMeasurement.h"
#import "NCSensorType.h"
#import "NCSignalMeasurement.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@protocol NCMeasurementListener

- (void)onSensorMeasurementDetected:(nonnull NSDictionary<NSNumber *, NCSensorMeasurement *> *)sensors;

- (void)onSignalMeasurementDetected:(nonnull NSDictionary<NSString *, NCSignalMeasurement *> *)signals;

@end
