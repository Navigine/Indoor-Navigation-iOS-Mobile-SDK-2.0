#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteProgress : NSObject

/** 
 * Default constructor for class NCRouteProgress 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                        sublocationId:(nullable NSNumber *)sublocationId
                              advance:(float)advance
                    remainingDistance:(float)remainingDistance
                        remainingTime:(float)remainingTime
                             legIndex:(int32_t)legIndex;

/** 
 * Factory method for class NCRouteProgress 
 */
+ (nonnull instancetype)routeProgressWithPoint:(nonnull NCGlobalPoint *)point
                                 sublocationId:(nullable NSNumber *)sublocationId
                                       advance:(float)advance
                             remainingDistance:(float)remainingDistance
                                 remainingTime:(float)remainingTime
                                      legIndex:(int32_t)legIndex;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@property (nonatomic, readonly) float advance;

@property (nonatomic, readonly) float remainingDistance;

/**
 * Pedestrian ETA in seconds for the part of the route still ahead.
 * Outdoor legs use the OSRM duration scaled by the remaining fraction.
 * Indoor legs use a fixed walking speed (1.4 m/s). Not a traffic ETA.
 */
@property (nonatomic, readonly) float remainingTime;

@property (nonatomic, readonly) int32_t legIndex;

@end
