#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Class is used for describing routing options of ``NCAsyncRouteManager``.
 * Referenced from: ``NCAsyncRouteManager``.
 *
 * @discussion Example:
 * @code
 * // Empty init uses IDL defaults (0 / 5 / 2); full init for custom values.
 * NCRouteOptions *routeOptions = [[NCRouteOptions alloc] initWithSmoothRadius:3.0 maxProjectionDistance:7.0 maxAdvance:2.5];
 * NSLog(@"Created route options with smoothRadius: %f, maxProjectionDistance: %f, maxAdvance: %f",
 *      routeOptions.smoothRadius, routeOptions.maxProjectionDistance, routeOptions.maxAdvance);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteOptions : NSObject

/** 
 * Default constructor for class NCRouteOptions 
 */
- (nonnull instancetype)initWithSmoothRadius:(double)smoothRadius
                       maxProjectionDistance:(double)maxProjectionDistance
                                  maxAdvance:(double)maxAdvance;

/** 
 * Factory method for class NCRouteOptions 
 */
+ (nonnull instancetype)routeOptionsWithSmoothRadius:(double)smoothRadius
                               maxProjectionDistance:(double)maxProjectionDistance
                                          maxAdvance:(double)maxAdvance;

/** 
 * Default constructor for class NCRouteOptions 
 */
- (nonnull instancetype)init;

/** 
 * Factory method for class NCRouteOptions 
 */
+ (nonnull instancetype)routeOptions;

/**
 * This parameter controls if the resulting route should be smoothed for better
 * user experience. It can be considered as the maximum distance (in meters)
 * by which the smoothed route can deviate from the original route. The original
 * route follows exactly the edges of the route graph. If you don't want the route
 * to be smoothed, use value 0.
 */
@property (nonatomic, readonly) double smoothRadius;

/**
 * This parameter controls the router behaviour in case if the position essentially
 * deviates from the proposed route. If the position deviates more than the specified
 * distance (in meters), then the route will be rebuilt. You should not set the
 * maxProjectionDistance value too low. The reasonable interval of values is [3, 10].
 */
@property (nonatomic, readonly) double maxProjectionDistance;

/**
 * This parameter controls the maximum distance (in meters) that a position can advance
 * along the route between the two consecutive navigation solutions separated in time
 * by 1 second. If this constraint is broken, the route will be completely rebuilt.
 * The reasonable interval of values is [1, 3].
 */
@property (nonatomic, readonly) double maxAdvance;

@end
