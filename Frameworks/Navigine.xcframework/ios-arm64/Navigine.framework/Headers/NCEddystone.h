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
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief eddystone's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief eddystone's sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief eddystone's name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief eddystone's namespaceId.
 */
@property (nonatomic, nonnull, readonly) NSString * namespaceId;

/**
 * @brief eddystone's instanceId.
 */
@property (nonatomic, nonnull, readonly) NSString * instanceId;

/**
 * @brief eddystone's power.
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * @brief eddystone status. @see TransmitterStatus "TransmitterStatus"
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
