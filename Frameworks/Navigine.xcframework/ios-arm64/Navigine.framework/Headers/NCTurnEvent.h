#import "NCExport.h"
#import "NCTurnType.h"
#import <Foundation/Foundation.h>

/**
 * @file NCTurnEvent.h
 * @brief @copybrief NCTurnEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class describing turn guidance event.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTurnEvent : NSObject

/** 
 * @brief Default constructor for class NCTurnEvent 
 */
- (nonnull instancetype)initWithType:(NCTurnType)type
                               angle:(int32_t)angle;

/** 
 * @brief Factory method for class NCTurnEvent 
 */
+ (nonnull instancetype)turnEventWithType:(NCTurnType)type
                                    angle:(int32_t)angle;

/**
 * @brief Turn direction/severity type.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TurnEvent_getType
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TurnEvent_getType
 *
 *
 */
@property (nonatomic, readonly) NCTurnType type;

/**
 * @brief Signed turn angle in degrees.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TurnEvent_getAngle
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TurnEvent_getAngle
 *
 *
 */
@property (nonatomic, readonly) int32_t angle;

@end
