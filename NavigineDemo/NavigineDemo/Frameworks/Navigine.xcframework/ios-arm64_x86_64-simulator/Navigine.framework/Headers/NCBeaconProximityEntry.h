#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCBeaconProximityEntry.h
 * @brief @copybrief NCBeaconProximityEntry
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBeaconProximityEntry : NSObject

/** 
 * @brief Default constructor for class NCBeaconProximityEntry 
 */
- (nonnull instancetype)initWithMajor:(int32_t)major
                                minor:(int32_t)minor
                                 uuid:(nonnull NSString *)uuid
                                 rssi:(float)rssi
                            frequency:(float)frequency
                              quality:(float)quality
                             distance:(nullable NSNumber *)distance;

/** 
 * @brief Factory method for class NCBeaconProximityEntry 
 */
+ (nonnull instancetype)beaconProximityEntryWithMajor:(int32_t)major
                                                minor:(int32_t)minor
                                                 uuid:(nonnull NSString *)uuid
                                                 rssi:(float)rssi
                                            frequency:(float)frequency
                                              quality:(float)quality
                                             distance:(nullable NSNumber *)distance;

@property (nonatomic, readonly) int32_t major;

@property (nonatomic, readonly) int32_t minor;

@property (nonatomic, readonly, nonnull) NSString * uuid;

@property (nonatomic, readonly) float rssi;

@property (nonatomic, readonly) float frequency;

@property (nonatomic, readonly) float quality;

@property (nonatomic, readonly, nullable) NSNumber * distance;

@end
