#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * @file NCWifi.h
 * @brief @copybrief NCWifi
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @ingroup navigine_objc_transmitters
 * @brief Class is used for storing <a href="https://en.wikipedia.org/wiki/Wi-Fi">WiFi</a>.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCWifi : NSObject

/**
 * @brief wifi's X and Y coordinates in meters as @see Point "Point" (within the sublocation).
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief wifi's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getLocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief wifi's sublocation identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief wifi's name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief wifi's mac.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getMac
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getMac
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * mac;

/**
 * @brief wifi's status. @see TransmitterStatus "TransmitterStatus"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Wifi_getStatus
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Wifi_getStatus
 *
 *
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
