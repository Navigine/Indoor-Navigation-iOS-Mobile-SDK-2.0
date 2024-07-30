#import "NCExport.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteOptions : NSObject
- (nonnull instancetype)initWithSmoothRadius:(nullable NSNumber *)smoothRadius
                       maxProjectionDistance:(nullable NSNumber *)maxProjectionDistance
                                  maxAdvance:(nullable NSNumber *)maxAdvance;
+ (nonnull instancetype)routeOptionsWithSmoothRadius:(nullable NSNumber *)smoothRadius
                               maxProjectionDistance:(nullable NSNumber *)maxProjectionDistance
                                          maxAdvance:(nullable NSNumber *)maxAdvance;

/**
 * This parameter controls if the resulting route should be smoothed for better
 * user experience. It can be considered as the maximum distance (in meters)
 * by which the smoothed route can deviate from the original route. The original
 * route follows exactly the edges of the route graph. If you don't want the route
 * to be smoothed, use value 0. Default value is 0.
 */
@property (nonatomic, readonly, nullable) NSNumber * smoothRadius;

/**
 * This parameter controls the router behaviour in case if the position essentially
 * deviates from the proposed route. If the position deviates more than the specified
 * distance (in meters), then the route will be rebuilt. You should not set the
 * maxProjectionDistance value too low. The reasonable interval of values is [3, 10].
 * Default value is 5.
 */
@property (nonatomic, readonly, nullable) NSNumber * maxProjectionDistance;

/**
 * This parameter controls the maximum distance (in meters) that a position can advance
 * along the route between the two consecutive navigation solutions separated in time
 * by 1 second. If this constraint is broken, the route will be completely rebuilt.
 * The reasonable interval of values is [1, 3]. Default value is 2.
 */
@property (nonatomic, readonly, nullable) NSNumber * maxAdvance;

@end
