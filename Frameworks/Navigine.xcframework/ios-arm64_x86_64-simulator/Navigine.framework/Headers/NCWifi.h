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
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief wifi's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief wifi's sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief wifi's name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief wifi's mac.
 */
@property (nonatomic, nonnull, readonly) NSString * mac;

/**
 * @brief wifi's status. @see TransmitterStatus "TransmitterStatus"
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
