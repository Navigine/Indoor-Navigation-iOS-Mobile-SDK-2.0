#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCMeasurementListener;


/**
 * @file NCMeasurementManager.h
 * @brief @copybrief NCMeasurementManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for managing measurement generators and notifying about sensor and signal measurements.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMeasurementManager : NSObject

/**
 *
 * @brief Method is used to add @see MeasurementListener "MeasurementListener" class element
 * which will notify about new sensor or signal measurements.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding @see MeasurementListener "MeasurementListener" class.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addMeasurementListener
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addMeasurementListener
 *
 *
 */
- (void)addMeasurementListener:(nullable id<NCMeasurementListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see MeasurementListener "MeasurementListener" class element.
 * @param listener Corresponding @see MeasurementListener "MeasurementListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeMeasurementListener
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeMeasurementListener
 *
 *
 */
- (void)removeMeasurementListener:(nullable id<NCMeasurementListener>)listener;

/**
 *
 * @brief Method adds a beacon generator for simulating BLE beacon signals.
 * @param uuid UUID of the beacon.
 * @param major Major value of the beacon.
 * @param minor Minor value of the beacon.
 * @param power Transmission power of the beacon (dBm).
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created beacon generator.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addBeaconGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addBeaconGenerator
 *
 *
 */
- (nonnull NSString *)addBeaconGenerator:(nonnull NSString *)uuid
                                   major:(int32_t)major
                                   minor:(int32_t)minor
                                   power:(int32_t)power
                                 timeout:(int32_t)timeout
                                 rssiMin:(int32_t)rssiMin
                                 rssiMax:(int32_t)rssiMax;

/**
 *
 * @brief Method adds an Eddystone generator for simulating Eddystone beacon signals.
 * @param namespaceId Namespace ID of the Eddystone beacon.
 * @param instanceId Instance ID of the Eddystone beacon.
 * @param power Transmission power of the beacon (dBm).
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created Eddystone generator.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addEddystoneGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addEddystoneGenerator
 *
 *
 */
- (nonnull NSString *)addEddystoneGenerator:(nonnull NSString *)namespaceId
                                 instanceId:(nonnull NSString *)instanceId
                                      power:(int32_t)power
                                    timeout:(int32_t)timeout
                                    rssiMin:(int32_t)rssiMin
                                    rssiMax:(int32_t)rssiMax;

/**
 *
 * @brief Method removes all BLE beacon generators.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeBleGenerators
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeBleGenerators
 *
 *
 */
- (void)removeBleGenerators;

/**
 *
 * @brief Method removes a specific BLE beacon generator by its identifier.
 * @param id Unique identifier of the BLE generator to remove.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeBleGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeBleGenerator
 *
 *
 */
- (void)removeBleGenerator:(nonnull NSString *)id;

/**
 *
 * @brief Method adds a Wi-Fi generator for simulating Wi-Fi signals.
 * @param mac MAC address of the Wi-Fi access point.
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created Wi-Fi generator.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addWifiGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addWifiGenerator
 *
 *
 */
- (nonnull NSString *)addWifiGenerator:(nonnull NSString *)mac
                               timeout:(int32_t)timeout
                               rssiMin:(int32_t)rssiMin
                               rssiMax:(int32_t)rssiMax;

/**
 *
 * @brief Method removes a specific Wi-Fi generator by its identifier.
 * @param id Unique identifier of the Wi-Fi generator to remove.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeWifiGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeWifiGenerator
 *
 *
 */
- (void)removeWifiGenerator:(nonnull NSString *)id;

/**
 *
 * @brief Method removes all Wi-Fi generators.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeWifiGenerators
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeWifiGenerators
 *
 *
 */
- (void)removeWifiGenerators;

/**
 *
 * @brief Method adds a Wi-Fi RTT generator for simulating Wi-Fi Round-Trip Time signals.
 * @param mac MAC address of the Wi-Fi access point.
 * @param timeout Duration of the generator in milliseconds.
 * @param distMin Minimum distance for the simulated signal (in meters).
 * @param distMax Maximum distance for the simulated signal (in meters).
 * @param stdDevMin Minimum standard deviation for the simulated signal.
 * @param stdDevMax Maximum standard deviation for the simulated signal.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created Wi-Fi RTT generator.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addWifiRttGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addWifiRttGenerator
 *
 *
 */
- (nonnull NSString *)addWifiRttGenerator:(nonnull NSString *)mac
                                  timeout:(int32_t)timeout
                                  distMin:(int32_t)distMin
                                  distMax:(int32_t)distMax
                                stdDevMin:(int32_t)stdDevMin
                                stdDevMax:(int32_t)stdDevMax
                                  rssiMin:(int32_t)rssiMin
                                  rssiMax:(int32_t)rssiMax;

/**
 *
 * @brief Method removes a specific Wi-Fi RTT generator by its identifier.
 * @param hash Unique identifier of the Wi-Fi RTT generator to remove.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeWifiRttGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeWifiRttGenerator
 *
 *
 */
- (void)removeWifiRttGenerator:(nonnull NSString *)hash;

/**
 *
 * @brief Method removes all Wi-Fi RTT generators.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeWifiRttGenerators
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeWifiRttGenerators
 *
 *
 */
- (void)removeWifiRttGenerators;

/**
 *
 * @brief Method adds a location generator for simulating location measurements.
 * @param latMin Minimum latitude for the simulated location.
 * @param latMax Maximum latitude for the simulated location.
 * @param lonMin Minimum longitude for the simulated location.
 * @param lonMax Maximum longitude for the simulated location.
 * @param accMin Minimum accuracy for the simulated location (in meters).
 * @param accMax Maximum accuracy for the simulated location (in meters).
 * @param timeout Duration of the generator in milliseconds.
 * @return Unique identifier of the created location generator.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_addLocationGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_addLocationGenerator
 *
 *
 */
- (nonnull NSString *)addLocationGenerator:(double)latMin
                                    latMax:(double)latMax
                                    lonMin:(double)lonMin
                                    lonMax:(double)lonMax
                                    accMin:(float)accMin
                                    accMax:(float)accMax
                                   timeout:(int32_t)timeout;

/**
 *
 * @brief Method removes a specific location generator by its identifier.
 * @param id Unique identifier of the location generator to remove.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeLocationGenerator
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeLocationGenerator
 *
 *
 */
- (void)removeLocationGenerator:(nonnull NSString *)id;

/**
 *
 * @brief Method removes all location generators.
 *
 *
 * Swift code snippet:
 * @snippet MeasurementManagerExample.swift swift_MeasurementManager_removeLocationGenerators
 *
 * Objective C code snippet:
 * @snippet MeasurementManagerExample.m objc_MeasurementManager_removeLocationGenerators
 *
 *
 */
- (void)removeLocationGenerators;

@end
