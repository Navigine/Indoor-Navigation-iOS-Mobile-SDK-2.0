#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCTargetReachedEvent.h
 * @brief @copybrief NCTargetReachedEvent
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Event indicating the route target has been reached.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTargetReachedEvent : NSObject

/** 
 * @brief Default constructor for class NCTargetReachedEvent 
 */
- (nonnull instancetype)initWithIndex:(int64_t)index
                                point:(nonnull NCLocationPoint *)point;

/** 
 * @brief Factory method for class NCTargetReachedEvent 
 */
+ (nonnull instancetype)targetReachedEventWithIndex:(int64_t)index
                                              point:(nonnull NCLocationPoint *)point;

/**
 * @brief Index of reached target in target list.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TargetReachedEvent_getIndex
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TargetReachedEvent_getIndex
 *
 *
 */
@property (nonatomic, readonly) int64_t index;

/**
 * @brief Location point where target was reached.
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TargetReachedEvent_getPoint
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TargetReachedEvent_getPoint
 *
 *
 */
@property (nonatomic, readonly, nonnull) NCLocationPoint * point;

@end
