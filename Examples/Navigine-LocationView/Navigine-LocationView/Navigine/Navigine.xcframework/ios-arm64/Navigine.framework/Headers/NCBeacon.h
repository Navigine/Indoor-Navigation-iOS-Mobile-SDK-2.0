#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing <a href="https://en.wikipedia.org/wiki/IBeacon">iBeacon</a>.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBeacon : NSObject

/**
 * beacon's X and Y coordinates in meters as ``NCPoint`` (within the sublocation).
 *
 * @discussion Example:
 * @code
 * // Get beacon point
 * NCPoint *point = [beacon getPoint];
 * if (point != nil) {
 *    [self demonstratePointUsage:point];
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * beacon's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get beacon location ID
 * int32_t locationId = [beacon getLocationId];
 * NSLog(@"Beacon location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * beacon's sublocation identifier.
 *
 * @discussion Example:
 * @code
 * // Get beacon sublocation ID
 * int32_t sublocationId = [beacon getSublocationId];
 * NSLog(@"Beacon sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * beacon's name.
 *
 * @discussion Example:
 * @code
 * // Get beacon name
 * NSString *beaconName = [beacon getName];
 * NSLog(@"Beacon name: %@", beaconName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * beacon's major. Values [1-65535]
 *
 * @discussion Example:
 * @code
 * // Get beacon major
 * int32_t major = [beacon getMajor];
 * NSLog(@"Beacon major: %d", major);
 * @endcode
 */
@property (nonatomic, readonly) int32_t major;

/**
 * beacon's minor. Values [1-65535]
 *
 * @discussion Example:
 * @code
 * // Get beacon minor
 * int32_t minor = [beacon getMinor];
 * NSLog(@"Beacon minor: %d", minor);
 * @endcode
 */
@property (nonatomic, readonly) int32_t minor;

/**
 * beacon's uuid. Format [XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX]
 *
 * @discussion Example:
 * @code
 * // Get beacon UUID
 * NSString *uuid = [beacon getUuid];
 * NSLog(@"Beacon UUID: %@", uuid);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * uuid;

/**
 * beacon's power.
 *
 * @discussion Example:
 * @code
 * // Get beacon power
 * NSNumber *power = [beacon getPower];
 * if (power != nil) {
 *    NSLog(@"Beacon power: %d", [power intValue]);
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * iBeacon status. ``NCTransmitterStatus``
 *
 * @discussion Example:
 * @code
 * // Get beacon status
 * NCTransmitterStatus status = [beacon getStatus];
 * NSLog(@"Beacon status: %ld", (long)status);
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
