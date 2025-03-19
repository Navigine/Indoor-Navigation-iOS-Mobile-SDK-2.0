#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCBeaconProximityEstimatorListener;


/**
 * @file NCBeaconProximityEstimator.h
 * @brief @copybrief NCBeaconProximityEstimator
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBeaconProximityEstimator : NSObject

- (void)start;

- (void)stop;

- (void)pause;

- (void)resume;

- (void)addListener:(nullable id<NCBeaconProximityEstimatorListener>)listener;

- (void)removeListener:(nullable id<NCBeaconProximityEstimatorListener>)listener;

@end
