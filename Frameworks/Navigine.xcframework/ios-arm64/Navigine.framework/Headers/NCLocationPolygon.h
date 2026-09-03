#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Polygon on the location view in WGS84 coordinates.
 *
 * @discussion Example:
 * @code
 * NSArray<NCGlobalPoint *> *ring = @[
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.617],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.752 longitude:37.618],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.619],
 * ];
 * NCLocationPolygon *locationPolygon = [[NCLocationPolygon alloc] initWithPoints:ring sublocationId:@(7)];
 * NSLog(@"LocationPolygon: sublocation %@, vertices %lu",
 *      locationPolygon.sublocationId, (unsigned long)locationPolygon.points.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolygon : NSObject

/** 
 * Default constructor for class NCLocationPolygon 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                         sublocationId:(nullable NSNumber *)sublocationId;

/** 
 * Factory method for class NCLocationPolygon 
 */
+ (nonnull instancetype)locationPolygonWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                                    sublocationId:(nullable NSNumber *)sublocationId;

/**
 * Ring vertices in WGS84 ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCGlobalPoint *> * points;

/**
 * Floor this polygon is attached to, or null for the outdoor map.
 */
@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@end
