#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * One sample while walking a polyline.
 * `advance` is meters from the start along the geometry.
 * `heading` is radians, clockwise from north (same sense as user-location course).
 * This is a pedestrian location fix: no accuracy noise, wheel speed, or
 * recorded-session clock.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteSimulatorSample : NSObject

/** 
 * Default constructor for class NCRouteSimulatorSample 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                        sublocationId:(nullable NSNumber *)sublocationId
                              advance:(float)advance
                              heading:(float)heading;

/** 
 * Factory method for class NCRouteSimulatorSample 
 */
+ (nonnull instancetype)routeSimulatorSampleWithPoint:(nonnull NCGlobalPoint *)point
                                        sublocationId:(nullable NSNumber *)sublocationId
                                              advance:(float)advance
                                              heading:(float)heading;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@property (nonatomic, readonly) float advance;

@property (nonatomic, readonly) float heading;

@end
