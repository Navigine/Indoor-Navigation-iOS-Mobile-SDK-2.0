#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCMeasurementListener;


/**
 * @file NCMeasurementManager.h
 * @brief @copybrief NCMeasurementManager
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMeasurementManager : NSObject

- (void)addMeasurementListener:(nullable id<NCMeasurementListener>)listener;

- (void)removeMeasurementListener:(nullable id<NCMeasurementListener>)listener;

- (nonnull NSString *)addBeaconGenerator:(nonnull NSString *)uuid
                                   major:(int32_t)major
                                   minor:(int32_t)minor
                                   power:(int32_t)power
                                 timeout:(int32_t)timeout
                                 rssiMin:(int32_t)rssiMin
                                 rssiMax:(int32_t)rssiMax;

- (nonnull NSString *)addEddystoneGenerator:(nonnull NSString *)namespaceId
                                 instanceId:(nonnull NSString *)instanceId
                                      power:(int32_t)power
                                    timeout:(int32_t)timeout
                                    rssiMin:(int32_t)rssiMin
                                    rssiMax:(int32_t)rssiMax;

- (void)removeBleGenerators;

- (void)removeBleGenerator:(nonnull NSString *)id;

- (nonnull NSString *)addWifiGenerator:(nonnull NSString *)mac
                               timeout:(int32_t)timeout
                               rssiMin:(int32_t)rssiMin
                               rssiMax:(int32_t)rssiMax;

- (void)removeWifiGenerator:(nonnull NSString *)id;

- (void)removeWifiGenerators;

- (nonnull NSString *)addWifiRttGenerator:(nonnull NSString *)mac
                                  timeout:(int32_t)timeout
                                  distMin:(int32_t)distMin
                                  distMax:(int32_t)distMax
                                stdDevMin:(int32_t)stdDevMin
                                stdDevMax:(int32_t)stdDevMax
                                  rssiMin:(int32_t)rssiMin
                                  rssiMax:(int32_t)rssiMax;

- (void)removeWifiRttGenerator:(nonnull NSString *)hash;

- (void)removeWifiRttGenerators;

- (nonnull NSString *)addLocationGenerator:(double)latMin
                                    latMax:(double)latMax
                                    lonMin:(double)lonMin
                                    lonMax:(double)lonMax
                                    accMin:(double)accMin
                                    accMax:(double)accMax
                                   timeout:(int32_t)timeout;

- (void)removeLocationGenerator:(nonnull NSString *)id;

- (void)removeLocationGenerators;

@end
