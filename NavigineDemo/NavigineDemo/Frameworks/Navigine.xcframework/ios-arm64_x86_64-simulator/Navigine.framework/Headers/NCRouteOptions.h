#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCRouteOptions.h
 * @brief @copybrief NCRouteOptions
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Class is used for describing routing options of @see AsyncRouteManager "AsyncRouteManager".
 *
 * Referenced from: @see AsyncRouteManager "AsyncRouteManager".
 *
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_RouteOptions_constructor
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_RouteOptions_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteOptions : NSObject

/** 
 * @brief Default constructor for class NCRouteOptions 
 */
- (nonnull instancetype)initWithSmoothRadius:(nullable NSNumber *)smoothRadius
                       maxProjectionDistance:(nullable NSNumber *)maxProjectionDistance
                                  maxAdvance:(nullable NSNumber *)maxAdvance;

/** 
 * @brief Factory method for class NCRouteOptions 
 */
+ (nonnull instancetype)routeOptionsWithSmoothRadius:(nullable NSNumber *)smoothRadius
                               maxProjectionDistance:(nullable NSNumber *)maxProjectionDistance
                                          maxAdvance:(nullable NSNumber *)maxAdvance;

/**
 * @brief This parameter controls if the resulting route should be smoothed for better
 * user experience. It can be considered as the maximum distance (in meters)
 * by which the smoothed route can deviate from the original route. The original
 * route follows exactly the edges of the route graph. If you don't want the route
 * to be smoothed, use value 0. Default value is 0.
 */
@property (nonatomic, readonly, nullable) NSNumber * smoothRadius;

/**
 * @brief This parameter controls the router behaviour in case if the position essentially
 * deviates from the proposed route. If the position deviates more than the specified
 * distance (in meters), then the route will be rebuilt. You should not set the
 * maxProjectionDistance value too low. The reasonable interval of values is [3, 10].
 * Default value is 5.
 */
@property (nonatomic, readonly, nullable) NSNumber * maxProjectionDistance;

/**
 * @brief This parameter controls the maximum distance (in meters) that a position can advance
 * along the route between the two consecutive navigation solutions separated in time
 * by 1 second. If this constraint is broken, the route will be completely rebuilt.
 * The reasonable interval of values is [1, 3]. Default value is 2.
 */
@property (nonatomic, readonly, nullable) NSNumber * maxAdvance;

@end
