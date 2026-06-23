#import "NCExport.h"
#import "NCPolyline.h"
#import <Foundation/Foundation.h>

/**
 * Class is used for representing certain polyline within the location ``NCPolyline``
 *
 * @discussion Example:
 * @code
 * NSArray<NCPoint *> *linePts = @[
 *    [[NCPoint alloc] initWithX:0.0 y:0.0],
 *    [[NCPoint alloc] initWithX:10.0 y:10.0],
 * ];
 * NCPolyline *metricPolyline = [[NCPolyline alloc] initWithPoints:linePts];
 * NCLocationPolyline *locationPolyline = [[NCLocationPolyline alloc] initWithPolyline:metricPolyline locationId:42 sublocationId:7];
 * NCPolyline *polylineBack = locationPolyline.polyline;
 * NSLog(@"LocationPolyline points %lu", (unsigned long)polylineBack.points.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolyline : NSObject

/** 
 * Default constructor for class NCLocationPolyline 
 */
- (nonnull instancetype)initWithPolyline:(nonnull NCPolyline *)polyline
                              locationId:(int32_t)locationId
                           sublocationId:(int32_t)sublocationId;

/** 
 * Factory method for class NCLocationPolyline 
 */
+ (nonnull instancetype)locationPolylineWithPolyline:(nonnull NCPolyline *)polyline
                                          locationId:(int32_t)locationId
                                       sublocationId:(int32_t)sublocationId;

/**
 * Metrics polyline @see Polyline.
 */
@property (nonatomic, readonly, nonnull) NCPolyline * polyline;

/**
 * location polyline location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * location polyline sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
