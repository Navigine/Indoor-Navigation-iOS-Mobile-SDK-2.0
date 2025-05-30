#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCPosition.h
 * @brief @copybrief NCPosition
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class describing user's position.
 *
 * Referenced from: @see NavigationManager "NavigationManager", @see PositionListener "PositionListener".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPosition : NSObject

/** 
 * @brief Default constructor for class NCPosition 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                             accuracy:(double)accuracy
                              heading:(nullable NSNumber *)heading
                      headingAccuracy:(nullable NSNumber *)headingAccuracy
                        locationPoint:(nullable NCLocationPoint *)locationPoint
                      locationHeading:(nullable NSNumber *)locationHeading;

/** 
 * @brief Factory method for class NCPosition 
 */
+ (nonnull instancetype)positionWithPoint:(nonnull NCGlobalPoint *)point
                                 accuracy:(double)accuracy
                                  heading:(nullable NSNumber *)heading
                          headingAccuracy:(nullable NSNumber *)headingAccuracy
                            locationPoint:(nullable NCLocationPoint *)locationPoint
                          locationHeading:(nullable NSNumber *)locationHeading;

/**
 * @brief position in WGS84 coordinates.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

/**
 * Position accuracy in meters
 */
@property (nonatomic, readonly) double accuracy;

/**
 * @brief Heading, angle of rotation about the -Z axis (in radians).
 * This value represents the angle between the device's Y
 * axis and the magnetic north pole. When facing north, this
 * angle is 0, when facing south, this angle is pi.
 * Likewise, when facing east, this angle is pi/2, and
 * when facing west, this angle is -pi/2. The range of
 * values is [-pi, pi].
 */
@property (nonatomic, readonly, nullable) NSNumber * heading;

/**
 * @brief Heading accuracy in radians
 */
@property (nonatomic, readonly, nullable) NSNumber * headingAccuracy;

/**
 * @brief position in metrics coordinates at calculated location and sublocation @see LocationPoint
 */
@property (nonatomic, readonly, nullable) NCLocationPoint * locationPoint;

/**
 * @brief Similiar to `heading` but with respect to `sublocation north` (top of the image)
 */
@property (nonatomic, readonly, nullable) NSNumber * locationHeading;

@end
