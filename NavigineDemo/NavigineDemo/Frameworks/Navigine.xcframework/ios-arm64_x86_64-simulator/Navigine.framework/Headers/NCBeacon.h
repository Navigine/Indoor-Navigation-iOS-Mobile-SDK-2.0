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
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief beacon's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief beacon's sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief beacon's name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief beacon's major. Values [1-65535]
 */
@property (nonatomic, readonly) int32_t major;

/**
 * @brief beacon's minor. Values [1-65535]
 */
@property (nonatomic, readonly) int32_t minor;

/**
 * @brief beacon's uuid. Format [XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX]
 */
@property (nonatomic, nonnull, readonly) NSString * uuid;

/**
 * iBeacon power. If exsists.
 * @brief beacon's power.
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * @brief iBeacon status. @see TransmitterStatus "TransmitterStatus"
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
