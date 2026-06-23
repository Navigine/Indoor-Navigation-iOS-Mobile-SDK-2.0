#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

/**
 * Class describing user's position.
 * Referenced from: ``NCNavigationManager``, ``NCPositionListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPosition : NSObject

/** 
 * Default constructor for class NCPosition 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                             accuracy:(double)accuracy
                              heading:(nullable NSNumber *)heading
                      headingAccuracy:(nullable NSNumber *)headingAccuracy
                        locationPoint:(nullable NCLocationPoint *)locationPoint
                      locationHeading:(nullable NSNumber *)locationHeading;

/** 
 * Factory method for class NCPosition 
 */
+ (nonnull instancetype)positionWithPoint:(nonnull NCGlobalPoint *)point
                                 accuracy:(double)accuracy
                                  heading:(nullable NSNumber *)heading
                          headingAccuracy:(nullable NSNumber *)headingAccuracy
                            locationPoint:(nullable NCLocationPoint *)locationPoint
                          locationHeading:(nullable NSNumber *)locationHeading;

/**
 * position in WGS84 coordinates.
 *
 * @discussion Example:
 * @code
 * // Get global point (WGS84 coordinates)
 * NCGlobalPoint *globalPoint = [position getPoint];
 * if (globalPoint != nil) {
 *    [self demonstrateGlobalPointUsage:globalPoint];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

/**
 * Position accuracy in meters
 *
 * @discussion Example:
 * @code
 * // Get position accuracy
 * double accuracy = [position getAccuracy];
 * NSLog(@"Position accuracy: %f meters", accuracy);
 * @endcode
 */
@property (nonatomic, readonly) double accuracy;

/**
 * Heading, angle of rotation about the -Z axis (in radians).
 * This value represents the angle between the device's Y
 * axis and the magnetic north pole. When facing north, this
 * angle is 0, when facing south, this angle is pi.
 * Likewise, when facing east, this angle is pi/2, and
 * when facing west, this angle is -pi/2. The range of
 * values is [-pi, pi].
 *
 * @discussion Example:
 * @code
 * // Get heading (angle of rotation about the -Z axis in radians)
 * NSNumber *heading = [position getHeading];
 * if (heading != nil) {
 *    NSLog(@"Heading: %f radians", [heading doubleValue]);
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NSNumber * heading;

/**
 * Heading accuracy in radians
 *
 * @discussion Example:
 * @code
 * // Get heading accuracy
 * NSNumber *headingAccuracy = [position getHeadingAccuracy];
 * if (headingAccuracy != nil) {
 *    NSLog(@"Heading accuracy: %f radians", [headingAccuracy doubleValue]);
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NSNumber * headingAccuracy;

/**
 * position in metrics coordinates at calculated location and sublocation @see LocationPoint
 *
 * @discussion Example:
 * @code
 * // Get location point (metrics coordinates)
 * NCLocationPoint *locationPoint = [position getLocationPoint];
 * if (locationPoint != nil) {
 *    [self demonstrateLocationPointUsage:locationPoint];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NCLocationPoint * locationPoint;

/**
 * Similar to `heading` but with respect to `sublocation north` (top of the image)
 *
 * @discussion Example:
 * @code
 * // Get location heading (with respect to sublocation north)
 * NSNumber *locationHeading = [position getLocationHeading];
 * if (locationHeading != nil) {
 *    NSLog(@"Location heading: %f radians", [locationHeading doubleValue]);
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NSNumber * locationHeading;

@end
