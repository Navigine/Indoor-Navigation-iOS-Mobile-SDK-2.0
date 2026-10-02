#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Polygon on the location view in WGS84 coordinates.
 * `points` is the outer ring. `innerRings` are holes (as in GeoJSON: first ring
 * outer, the rest holes). An empty list is a solid polygon.
 *
 * @discussion Example:
 * @code
 * NSArray<NCGlobalPoint *> *ring = @[
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.617],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.752 longitude:37.618],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.619],
 * ];
 * NSArray<NSArray<NCGlobalPoint *> *> *holes = @[
 *    @[
 *        [[NCGlobalPoint alloc] initWithLatitude:55.7512 longitude:37.6174],
 *        [[NCGlobalPoint alloc] initWithLatitude:55.7514 longitude:37.6176],
 *        [[NCGlobalPoint alloc] initWithLatitude:55.7512 longitude:37.6178],
 *    ],
 * ];
 * NCLocationPolygon *locationPolygon = [[NCLocationPolygon alloc] initWithPoints:ring
 *                                                                sublocationId:@(7)
 *                                                                   innerRings:holes];
 * NSLog(@"LocationPolygon: sublocation %@, vertices %lu, holes %lu",
 *      locationPolygon.sublocationId,
 *      (unsigned long)locationPolygon.points.count,
 *      (unsigned long)locationPolygon.innerRings.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolygon : NSObject

/** 
 * Default constructor for class NCLocationPolygon 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                         sublocationId:(nullable NSNumber *)sublocationId
                            innerRings:(nonnull NSArray<NSArray<NCGlobalPoint *> *> *)innerRings;

/** 
 * Factory method for class NCLocationPolygon 
 */
+ (nonnull instancetype)locationPolygonWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                                    sublocationId:(nullable NSNumber *)sublocationId
                                       innerRings:(nonnull NSArray<NSArray<NCGlobalPoint *> *> *)innerRings;

/**
 * Outer ring vertices in WGS84 ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCGlobalPoint *> * points;

/**
 * Floor this polygon is attached to, or null for the outdoor map.
 */
@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

/**
 * Holes. Each ring is WGS84 ``NCGlobalPoint``.
 * Empty means a solid polygon.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSArray<NCGlobalPoint *> *> * innerRings;

@end
