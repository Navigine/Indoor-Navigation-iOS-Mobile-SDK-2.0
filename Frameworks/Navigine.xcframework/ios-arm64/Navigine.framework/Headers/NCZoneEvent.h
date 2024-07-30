#import "NCExport.h"
#import "NCZoneEventType.h"
#import <Foundation/Foundation.h>

/**
 *
 * Object describing user zone_event.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneEvent : NSObject
- (nonnull instancetype)initWithType:(NCZoneEventType)type
                          locationId:(int32_t)locationId
                       sublocationId:(int32_t)sublocationId
                                  id:(int32_t)id
                                name:(nonnull NSString *)name
                               alias:(nonnull NSString *)alias;
+ (nonnull instancetype)zoneEventWithType:(NCZoneEventType)type
                               locationId:(int32_t)locationId
                            sublocationId:(int32_t)sublocationId
                                       id:(int32_t)id
                                     name:(nonnull NSString *)name
                                    alias:(nonnull NSString *)alias;

/** Handled zone event type. */
@property (nonatomic, readonly) NCZoneEventType type;

/** Unique location identifier of Zone position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of Zone position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** Zone unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Zone name. */
@property (nonatomic, readonly, nonnull) NSString * name;

/** Zone alias. */
@property (nonatomic, readonly, nonnull) NSString * alias;

@end
