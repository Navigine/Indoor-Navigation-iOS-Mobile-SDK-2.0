#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * A point at the specified WGS84 coordinates.
 * Referenced from ``NCGeometryUtils``, ``NCNavigationManager``, ``NCPosition``, ``NCSublocation``.
 *
 * @discussion Example:
 * @code
 * // Create global points with latitude, longitude
 * NCGlobalPoint *globalPoint1 = [[NCGlobalPoint alloc] initWithLatitude:55.7558 longitude:37.6176]; // Moscow
 * NCGlobalPoint *globalPoint2 = [[NCGlobalPoint alloc] initWithLatitude:59.9311 longitude:30.3609]; // St. Petersburg
 * NCGlobalPoint *globalPoint3 = [[NCGlobalPoint alloc] initWithLatitude:55.7522 longitude:37.6156]; // Moscow center
 * NSLog(@"Created global points: GP1(%.4f, %.4f), GP2(%.4f, %.4f)",
 *      globalPoint1.latitude, globalPoint1.longitude, globalPoint2.latitude, globalPoint2.longitude);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGlobalPoint : NSObject

/** 
 * Default constructor for class NCGlobalPoint 
 */
- (nonnull instancetype)initWithLatitude:(double)latitude
                               longitude:(double)longitude;

/** 
 * Factory method for class NCGlobalPoint 
 */
+ (nonnull instancetype)globalPointWithLatitude:(double)latitude
                                      longitude:(double)longitude;

/**
 * point's latitude.
 *
 * @discussion Example:
 * @code
 * // Get latitude
 * double lat1 = globalPoint1.latitude;
 * NSLog(@"GlobalPoint1 latitude: %.4f", lat1);
 * @endcode
 */
@property (nonatomic, readonly) double latitude;

/**
 * point's longitude.
 *
 * @discussion Example:
 * @code
 * // Get longitude
 * double lon1 = globalPoint1.longitude;
 * NSLog(@"GlobalPoint1 longitude: %.4f", lon1);
 * @endcode
 */
@property (nonatomic, readonly) double longitude;

@end
