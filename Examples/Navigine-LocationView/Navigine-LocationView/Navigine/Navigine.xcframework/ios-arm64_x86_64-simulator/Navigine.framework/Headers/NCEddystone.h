#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing <a href="https://en.wikipedia.org/wiki/Eddystone_(Google)">Eddystone</a>.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCEddystone : NSObject

/**
 * eddystone's X and Y coordinates in meters as ``NCPoint`` (within the sublocation).
 *
 * @discussion Example:
 * @code
 * // Get Eddystone point
 * NCPoint *point = [eddystone getPoint];
 * if (point != nil) {
 *    [self demonstratePointUsage:point];
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * eddystone's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone location ID
 * int32_t locationId = [eddystone getLocationId];
 * NSLog(@"Eddystone location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * eddystone's sublocation identifier.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone sublocation ID
 * int32_t sublocationId = [eddystone getSublocationId];
 * NSLog(@"Eddystone sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * eddystone's name.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone name
 * NSString *eddystoneName = [eddystone getName];
 * NSLog(@"Eddystone name: %@", eddystoneName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * eddystone's namespaceId.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone namespace ID
 * NSString *namespaceId = [eddystone getNamespaceId];
 * NSLog(@"Eddystone namespace ID: %@", namespaceId);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * namespaceId;

/**
 * eddystone's instanceId.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone instance ID
 * NSString *instanceId = [eddystone getInstanceId];
 * NSLog(@"Eddystone instance ID: %@", instanceId);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * instanceId;

/**
 * eddystone's power.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone power
 * NSNumber *power = [eddystone getPower];
 * if (power != nil) {
 *    NSLog(@"Eddystone power: %d", [power intValue]);
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * power;

/**
 * eddystone status. ``NCTransmitterStatus``
 *
 * @discussion Example:
 * @code
 * // Get Eddystone status
 * NCTransmitterStatus status = [eddystone getStatus];
 * NSLog(@"Eddystone status: %ld", (long)status);
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
