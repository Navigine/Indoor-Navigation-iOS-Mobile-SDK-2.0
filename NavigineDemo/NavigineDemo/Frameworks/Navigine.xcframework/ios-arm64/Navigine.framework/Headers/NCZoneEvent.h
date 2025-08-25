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
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getType
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getType
 *
 *
 */
@property (nonatomic, readonly) NCZoneEventType type;

/**
 * @brief zone's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getLocationId
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief zone's sublocationId identifier.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getSublocationId
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief zone's identifier.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getId
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief zone's name.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getName
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getName
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * @brief zone's alias.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneEvent_getAlias
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneEvent_getAlias
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSString * alias;

@end
