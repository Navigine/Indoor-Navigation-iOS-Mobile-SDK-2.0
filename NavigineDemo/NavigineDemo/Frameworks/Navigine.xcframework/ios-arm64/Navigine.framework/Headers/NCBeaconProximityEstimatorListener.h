#import "NCBeaconProximityEntry.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCBeaconProximityEstimatorListener.h
 * @brief @copybrief NCBeaconProximityEstimatorListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCBeaconProximityEstimatorListener <NSObject>

- (void)onScanResultReady:(nonnull NSArray<NCBeaconProximityEntry *> *)beacons;

- (void)onProgressChanged:(float)progress;

- (void)onFinished:(nonnull NSArray<NCBeaconProximityEntry *> *)beacons;

- (void)onFailed:(nullable NSError *)error;

@end
