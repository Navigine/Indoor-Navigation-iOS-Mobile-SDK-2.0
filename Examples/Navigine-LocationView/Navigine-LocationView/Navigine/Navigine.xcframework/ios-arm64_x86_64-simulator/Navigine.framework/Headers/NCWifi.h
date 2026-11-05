#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing <a href="https://en.wikipedia.org/wiki/Wi-Fi">WiFi</a>.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCWifi : NSObject

/**
 * wifi's X and Y coordinates in meters as ``NCPoint`` (within the sublocation).
 *
 * @discussion Example:
 * @code
 * // Get WiFi point
 * NCPoint *point = [wifi getPoint];
 * if (point != nil) {
 *    [self demonstratePointUsage:point];
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * wifi's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get WiFi location ID
 * int32_t locationId = [wifi getLocationId];
 * NSLog(@"WiFi location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * wifi's sublocation identifier.
 *
 * @discussion Example:
 * @code
 * // Get WiFi sublocation ID
 * int32_t sublocationId = [wifi getSublocationId];
 * NSLog(@"WiFi sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * wifi's name.
 *
 * @discussion Example:
 * @code
 * // Get WiFi name
 * NSString *wifiName = [wifi getName];
 * NSLog(@"WiFi name: %@", wifiName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * wifi's mac.
 *
 * @discussion Example:
 * @code
 * // Get WiFi MAC address
 * NSString *mac = [wifi getMac];
 * NSLog(@"WiFi MAC: %@", mac);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * mac;

/**
 * wifi's status. ``NCTransmitterStatus``
 *
 * @discussion Example:
 * @code
 * // Get WiFi status
 * NCTransmitterStatus status = [wifi getStatus];
 * NSLog(@"WiFi status: %ld", (long)status);
 * @endcode
 */
@property (nonatomic, readonly) NCTransmitterStatus status;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
