#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * Class is used for storing location polygonal zones.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZone : NSObject

/**
 * zone's list of points composing the polygonal zone ``NCPolygon``
 *
 * @discussion Example:
 * @code
 * // Get zone polygon
 * NSArray<NCPoint *> *polygon = [zone getPolygon];
 * NSLog(@"Zone polygon points: %lu", (unsigned long)polygon.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPolygon * polygon;

/**
 * zone's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get zone location ID
 * int32_t locationId = [zone getLocationId];
 * NSLog(@"Zone location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * zone's sublocationId identifier.
 *
 * @discussion Example:
 * @code
 * // Get zone sublocation ID
 * int32_t sublocationId = [zone getSublocationId];
 * NSLog(@"Zone sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * zone's identifier.
 *
 * @discussion Example:
 * @code
 * // Get zone ID
 * int32_t zoneId = [zone getId];
 * NSLog(@"Zone ID: %d", zoneId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * Optional stable zone GUID used by live tracking (MQTT zone_guids).
 * Distinct from id; may be missing in older location archives.
 *
 * @discussion Example:
 * @code
 * NSNumber *zoneGuid = [zone getGuid];
 * if (zoneGuid != nil) {
 *    NSLog(@"Zone GUID: %@", zoneGuid);
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * guid;

/**
 * zone's name.
 *
 * @discussion Example:
 * @code
 * // Get zone name
 * NSString *zoneName = [zone getName];
 * NSLog(@"Zone name: %@", zoneName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * zone's color.
 *
 * @discussion Example:
 * @code
 * // Get zone color
 * UIColor *color = [zone getColor];
 * NSLog(@"Zone color: %@", color);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) UIColor * color;

/**
 * zone's alias.
 *
 * @discussion Example:
 * @code
 * // Get zone alias
 * NSString *alias = [zone getAlias];
 * NSLog(@"Zone alias: %@", alias);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
