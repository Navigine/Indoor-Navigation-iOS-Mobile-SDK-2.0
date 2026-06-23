#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>

/**
 * Class is used for representing certain polygon within the location ``NCPolygon``
 *
 * @discussion Example:
 * @code
 * NSArray<NCPoint *> *ring = @[
 *    [[NCPoint alloc] initWithX:1.0 y:2.0],
 *    [[NCPoint alloc] initWithX:3.0 y:4.0],
 *    [[NCPoint alloc] initWithX:5.0 y:2.0],
 * ];
 * NCPolygon *metricPolygon = [[NCPolygon alloc] initWithPoints:ring];
 * NCLocationPolygon *locationPolygon = [[NCLocationPolygon alloc] initWithPolygon:metricPolygon locationId:42 sublocationId:7];
 * NCPolygon *polygonBack = locationPolygon.polygon;
 * NSLog(@"LocationPolygon location %d sublocation %d vertices %lu",
 *      (int)locationPolygon.locationId, (int)locationPolygon.sublocationId, (unsigned long)polygonBack.points.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolygon : NSObject

/** 
 * Default constructor for class NCLocationPolygon 
 */
- (nonnull instancetype)initWithPolygon:(nonnull NCPolygon *)polygon
                             locationId:(int32_t)locationId
                          sublocationId:(int32_t)sublocationId;

/** 
 * Factory method for class NCLocationPolygon 
 */
+ (nonnull instancetype)locationPolygonWithPolygon:(nonnull NCPolygon *)polygon
                                        locationId:(int32_t)locationId
                                     sublocationId:(int32_t)sublocationId;

/**
 * Metrics polygon ``NCPolygon``.
 */
@property (nonatomic, readonly, nonnull) NCPolygon * polygon;

/**
 * location polygon location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * location polygon sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
