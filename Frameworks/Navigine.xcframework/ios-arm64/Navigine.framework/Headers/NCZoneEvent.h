#import "NCExport.h"
#import "NCZoneEventType.h"
#import <Foundation/Foundation.h>

/**
 * @file NCZoneEvent.h
 * @brief @copybrief NCZoneEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class described user zone event.
 *
 * Referenced from @see ZoneListener "ZoneListener".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneEvent : NSObject

/** 
 * @brief Default constructor for class NCZoneEvent 
 */
- (nonnull instancetype)initWithType:(NCZoneEventType)type
                          locationId:(int32_t)locationId
                       sublocationId:(int32_t)sublocationId
                                  id:(int32_t)id
                                name:(nonnull NSString *)name
                               alias:(nonnull NSString *)alias;

/** 
 * @brief Factory method for class NCZoneEvent 
 */
+ (nonnull instancetype)zoneEventWithType:(NCZoneEventType)type
                               locationId:(int32_t)locationId
                            sublocationId:(int32_t)sublocationId
                                       id:(int32_t)id
                                     name:(nonnull NSString *)name
                                    alias:(nonnull NSString *)alias;

/**
 * @brief Handled zone event type.
 */
@property (nonatomic, readonly) NCZoneEventType type;

/**
 * @brief zone's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief zone's sublocationId identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief zone's identifier.
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief zone's name.
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * @brief zone's alias.
 */
@property (nonatomic, readonly, nonnull) NSString * alias;

@end
