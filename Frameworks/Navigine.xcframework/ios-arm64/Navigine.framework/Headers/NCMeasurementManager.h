#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCMeasurementListener;


/**
 * Class is used for managing measurement generators and notifying about sensor and signal measurements.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMeasurementManager : NSObject

/**
 * Method is used to add ``NCMeasurementListener`` class element
 * which will notify about new sensor or signal measurements.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCMeasurementListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add measurement listener
 * [self.measurementManager addMeasurementListener:self.measurementListener];
 * NSLog(@"Added measurement listener");
 * @endcode
 */
- (void)addMeasurementListener:(nullable id<NCMeasurementListener>)listener;

/**
 * Method is used for removing previously added ``NCMeasurementListener`` class element.
 * @param listener Corresponding ``NCMeasurementListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove measurement listener
 * [self.measurementManager removeMeasurementListener:self.measurementListener];
 * NSLog(@"Removed measurement listener");
 * @endcode
 */
- (void)removeMeasurementListener:(nullable id<NCMeasurementListener>)listener;

/**
 * Sets the interval in milliseconds between measurement batches delivered to ``NCMeasurementListener``. Default is 1000 ms. Values less than or equal to zero are treated as the default.
 * @param intervalMs wait time in milliseconds before the next publish cycle
 *
 * @discussion Example:
 * @code
 * // Optional: interval between measurement batches sent to listeners (ms)
 * [self.measurementManager setPublishIntervalMs:1000];
 * @endcode
 */
- (void)setPublishIntervalMs:(int32_t)intervalMs;

/**
 * Method adds a beacon generator for simulating BLE beacon signals.
 * @param uuid UUID of the beacon.
 * @param major Major value of the beacon.
 * @param minor Minor value of the beacon.
 * @param power Transmission power of the beacon (dBm).
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created beacon generator.
 *
 * @discussion Example:
 * @code
 * // Add beacon generator
 * NSString *beaconId = [self.measurementManager addBeaconGeneratorWithUuid:@"12345678-1234-1234-1234-123456789012"
 *                                                                   major:100
 *                                                                   minor:200
 *                                                                   power:-60
 *                                                                 timeout:5000
 *                                                                rssiMin:-80
 *                                                                rssiMax:-40];
 * NSLog(@"Added beacon generator with ID: %@", beaconId);
 * @endcode
 */
- (nonnull NSString *)addBeaconGenerator:(nonnull NSString *)uuid
                                   major:(int32_t)major
                                   minor:(int32_t)minor
                                   power:(int32_t)power
                                 timeout:(int32_t)timeout
                                 rssiMin:(int32_t)rssiMin
                                 rssiMax:(int32_t)rssiMax;

/**
 * Method adds an Eddystone generator for simulating Eddystone beacon signals.
 * @param namespaceId Namespace ID of the Eddystone beacon.
 * @param instanceId Instance ID of the Eddystone beacon.
 * @param power Transmission power of the beacon (dBm).
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created Eddystone generator.
 *
 * @discussion Example:
 * @code
 * // Add Eddystone generator
 * NSString *eddystoneId = [self.measurementManager addEddystoneGeneratorWithNamespaceId:@"12345678901234567890"
 *                                                                           instanceId:@"1234567890123456"
 *                                                                               power:-65
 *                                                                             timeout:3000
 *                                                                            rssiMin:-85
 *                                                                            rssiMax:-45];
 * NSLog(@"Added Eddystone generator with ID: %@", eddystoneId);
 * @endcode
 */
- (nonnull NSString *)addEddystoneGenerator:(nonnull NSString *)namespaceId
                                 instanceId:(nonnull NSString *)instanceId
                                      power:(int32_t)power
                                    timeout:(int32_t)timeout
                                    rssiMin:(int32_t)rssiMin
                                    rssiMax:(int32_t)rssiMax;

/**
 * Method removes all BLE beacon generators.
 *
 * @discussion Example:
 * @code
 * // Remove all BLE generators
 * [self.measurementManager removeBleGenerators];
 * NSLog(@"Removed all BLE generators");
 * @endcode
 */
- (void)removeBleGenerators;

/**
 * Method removes a specific BLE beacon generator by its identifier.
 * @param id Unique identifier of the BLE generator to remove.
 *
 * @discussion Example:
 * @code
 * // Remove specific BLE generator
 * [self.measurementManager removeBleGeneratorWithId:beaconId];
 * NSLog(@"Removed BLE generator: %@", beaconId);
 * @endcode
 */
- (void)removeBleGenerator:(nonnull NSString *)id;

/**
 * Method adds a Wi-Fi generator for simulating Wi-Fi signals.
 * @param mac MAC address of the Wi-Fi access point.
 * @param timeout Duration of the generator in milliseconds.
 * @param rssiMin Minimum RSSI value for the simulated signal.
 * @param rssiMax Maximum RSSI value for the simulated signal.
 * @return Unique identifier of the created Wi-Fi generator.
 *
 * @discussion Example:
 * @code
 * // Add Wi-Fi generator
 * NSString *wifiId = [self.measurementManager addWifiGeneratorWithMac:@"AA:BB:CC:DD:EE:FF"
 *                                                             timeout:4000
 *                                                            rssiMin:-90
 *                                                            rssiMax:-50];
 * NSLog(@"Added Wi-Fi generator with ID: %@", wifiId);
 * @endcode
 */
- (nonnull NSString *)addWifiGenerator:(nonnull NSString *)mac
                               timeout:(int32_t)timeout
                               rssiMin:(int32_t)rssiMin
                               rssiMax:(int32_t)rssiMax;

/**
 * Method removes a specific Wi-Fi generator by its identifier.
 * @param id Unique identifier of the Wi-Fi generator to remove.
 *
 * @discussion Example:
 * @code
 * // Remove specific Wi-Fi generator
 * [self.measurementManager removeWifiGeneratorWithId:wifiId];
 * NSLog(@"Removed Wi-Fi generator: %@", wifiId);
 * @endcode
 */
- (void)removeWifiGenerator:(nonnull NSString *)id;

/**
 * Method removes all Wi-Fi generators.
 *
 * @discussion Example:
 * @code
 * // Remove all Wi-Fi generators
 * [self.measurementManager removeWifiGenerators];
 * NSLog(@"Removed all Wi-Fi generators");
 * @endcode
 */
- (void)removeWifiGenerators;

/**
 * Method adds a Wi-Fi RTT generator for simulating Wi-Fi Round-Trip Time signals.
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
 * @discussion Example:
 * @code
 * // Add Wi-Fi RTT generator
 * NSString *wifiRttId = [self.measurementManager addWifiRttGeneratorWithMac:@"11:22:33:44:55:66"
 *                                                                  timeout:6000
 *                                                                 distMin:1
 *                                                                 distMax:10
 *                                                              stdDevMin:0
 *                                                              stdDevMax:2
 *                                                                rssiMin:-70
 *                                                                rssiMax:-30];
 * NSLog(@"Added Wi-Fi RTT generator with ID: %@", wifiRttId);
 * @endcode
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
 * Method removes a specific Wi-Fi RTT generator by its identifier.
 * @param hash Unique identifier of the Wi-Fi RTT generator to remove.
 *
 * @discussion Example:
 * @code
 * // Remove specific Wi-Fi RTT generator
 * [self.measurementManager removeWifiRttGeneratorWithHash:wifiRttId];
 * NSLog(@"Removed Wi-Fi RTT generator: %@", wifiRttId);
 * @endcode
 */
- (void)removeWifiRttGenerator:(nonnull NSString *)hash;

/**
 * Method removes all Wi-Fi RTT generators.
 *
 * @discussion Example:
 * @code
 * // Remove all Wi-Fi RTT generators
 * [self.measurementManager removeWifiRttGenerators];
 * NSLog(@"Removed all Wi-Fi RTT generators");
 * @endcode
 */
- (void)removeWifiRttGenerators;

/**
 * Method adds a location generator for simulating location measurements.
 * @param latMin Minimum latitude for the simulated location.
 * @param latMax Maximum latitude for the simulated location.
 * @param lonMin Minimum longitude for the simulated location.
 * @param lonMax Maximum longitude for the simulated location.
 * @param accMin Minimum accuracy for the simulated location (in meters).
 * @param accMax Maximum accuracy for the simulated location (in meters).
 * @param timeout Duration of the generator in milliseconds.
 * @return Unique identifier of the created location generator.
 *
 * @discussion Example:
 * @code
 * // Add location generator
 * NSString *locationId = [self.measurementManager addLocationGeneratorWithLatMin:55.7558
 *                                                                       latMax:55.7559
 *                                                                       lonMin:37.6176
 *                                                                       lonMax:37.6177
 *                                                                      accMin:1.0
 *                                                                      accMax:5.0
 *                                                                     timeout:7000];
 * NSLog(@"Added location generator with ID: %@", locationId);
 * @endcode
 */
- (nonnull NSString *)addLocationGenerator:(double)latMin
                                    latMax:(double)latMax
                                    lonMin:(double)lonMin
                                    lonMax:(double)lonMax
                                    accMin:(float)accMin
                                    accMax:(float)accMax
                                   timeout:(int32_t)timeout;

/**
 * Method removes a specific location generator by its identifier.
 * @param id Unique identifier of the location generator to remove.
 *
 * @discussion Example:
 * @code
 * // Remove specific location generator
 * [self.measurementManager removeLocationGeneratorWithId:locationId];
 * NSLog(@"Removed location generator: %@", locationId);
 * @endcode
 */
- (void)removeLocationGenerator:(nonnull NSString *)id;

/**
 * Method removes all location generators.
 *
 * @discussion Example:
 * @code
 * // Remove all location generators
 * [self.measurementManager removeLocationGenerators];
 * NSLog(@"Removed all location generators");
 * @endcode
 */
- (void)removeLocationGenerators;

@end
