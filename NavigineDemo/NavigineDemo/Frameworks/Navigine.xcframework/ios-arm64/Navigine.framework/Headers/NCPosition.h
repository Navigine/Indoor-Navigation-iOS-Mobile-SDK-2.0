#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

/**
 *
 * Class describing user's position
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPosition : NSObject
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                             accuracy:(double)accuracy
                              heading:(nullable NSNumber *)heading
                        locationPoint:(nullable NCLocationPoint *)locationPoint
                      locationHeading:(nullable NSNumber *)locationHeading;
+ (nonnull instancetype)positionWithPoint:(nonnull NCGlobalPoint *)point
                                 accuracy:(double)accuracy
                                  heading:(nullable NSNumber *)heading
                            locationPoint:(nullable NCLocationPoint *)locationPoint
                          locationHeading:(nullable NSNumber *)locationHeading;

/** Position in WGS84 coordinates */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

/** Position accuracy in meters */
@property (nonatomic, readonly) double accuracy;

/**
 * Heading, angle of rotation about the -Z axis (in radians).
 * This value represents the angle between the device's Y
 * axis and the magnetic north pole. When facing north, this
 * angle is 0, when facing south, this angle is pi.
 * Likewise, when facing east, this angle is pi/2, and
 * when facing west, this angle is -pi/2. The range of
 * values is [-pi, pi].
 */
@property (nonatomic, readonly, nullable) NSNumber * heading;

/** Position in metrics coordinates at calculated location and sublocation */
@property (nonatomic, readonly, nullable) NCLocationPoint * locationPoint;

/** Similiar to `heading` but with respect to `sublocation north` (top of the image) */
@property (nonatomic, readonly, nullable) NSNumber * locationHeading;

@end
