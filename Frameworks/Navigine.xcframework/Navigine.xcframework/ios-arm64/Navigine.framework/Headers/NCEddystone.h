#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * @file NCEddystone.h
 * @brief @copybrief NCEddystone
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @ingroup navigine_objc_transmitters
 * @brief Class is used for storing <a href="https://en.wikipedia.org/wiki/Eddystone_(Google)">Eddystone</a>.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCEddystone : NSObject

/**
 * @brief eddystone's X and Y coordinates in meters as @see Point "Point" (within the sublocation).
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief eddystone's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getLocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief eddystone's sublocation identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief eddystone's name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief eddystone's namespaceId.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getNamespaceId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getNamespaceId
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * namespaceId;

/**
 * @brief eddystone's instanceId.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getInstanceId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getInstanceId
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * instanceId;

/**
 * @brief eddystone's power.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getPower
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getPower
 *
 *
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * @brief eddystone status. @see TransmitterStatus "TransmitterStatus"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Eddystone_getStatus
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Eddystone_getStatus
 *
 *
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
