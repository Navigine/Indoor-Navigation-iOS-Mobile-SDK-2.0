#import "NCExport.h"
#import "NCZoneEventType.h"
#import <Foundation/Foundation.h>

/**
 * Class described user zone event.
 * Referenced from ``NCZoneListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneEvent : NSObject

/** 
 * Default constructor for class NCZoneEvent 
 */
- (nonnull instancetype)initWithType:(NCZoneEventType)type
                          locationId:(int32_t)locationId
                       sublocationId:(int32_t)sublocationId
                                  id:(int32_t)id
                                name:(nonnull NSString *)name
                               alias:(nonnull NSString *)alias;

/** 
 * Factory method for class NCZoneEvent 
 */
+ (nonnull instancetype)zoneEventWithType:(NCZoneEventType)type
                               locationId:(int32_t)locationId
                            sublocationId:(int32_t)sublocationId
                                       id:(int32_t)id
                                     name:(nonnull NSString *)name
                                    alias:(nonnull NSString *)alias;

/**
 * Handled zone event type.
 *
 * @discussion Example:
 * @code
 * // Get event type
 * NCZoneEventType type = zoneEvent.type;
 * NSLog(@"Zone event type: %ld", (long)type);
 * @endcode
 */
@property (nonatomic, readonly) NCZoneEventType type;

/**
 * zone's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get location ID
 * int32_t locationId = zoneEvent.locationId;
 * NSLog(@"Zone location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * zone's sublocationId identifier.
 *
 * @discussion Example:
 * @code
 * // Get sublocation ID
 * int32_t sublocationId = zoneEvent.sublocationId;
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
 * int32_t id = zoneEvent.id;
 * NSLog(@"Zone ID: %d", id);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * zone's name.
 *
 * @discussion Example:
 * @code
 * // Get zone name
 * NSString *name = zoneEvent.name;
 * NSLog(@"Zone name: %@", name);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * zone's alias.
 *
 * @discussion Example:
 * @code
 * // Get zone alias
 * NSString *alias = zoneEvent.alias;
 * NSLog(@"Zone alias: %@", alias);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSString * alias;

@end
