#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * @file NCBeacon.h
 * @brief @copybrief NCBeacon
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @ingroup navigine_objc_transmitters
 * @brief Class is used for storing <a href="https://en.wikipedia.org/wiki/IBeacon">iBeacon</a>.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBeacon : NSObject

/**
 * @brief beacon's X and Y coordinates in meters as @see Point "Point" (within the sublocation).
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief beacon's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getLocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief beacon's sublocation identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief beacon's name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief beacon's major. Values [1-65535]
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getMajor
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getMajor
 *
 *
 */
@property (nonatomic, readonly) int32_t major;

/**
 * @brief beacon's minor. Values [1-65535]
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getMinor
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getMinor
 *
 *
 */
@property (nonatomic, readonly) int32_t minor;

/**
 * @brief beacon's uuid. Format [XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX]
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getUuid
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getUuid
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * uuid;

/**
 * @brief beacon's power.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getPower
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getPower
 *
 *
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * @brief iBeacon status. @see TransmitterStatus "TransmitterStatus"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Beacon_getStatus
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Beacon_getStatus
 *
 *
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
