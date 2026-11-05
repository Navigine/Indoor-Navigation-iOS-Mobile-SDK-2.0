#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Polyline on the location view in WGS84 coordinates.
 *
 * @discussion Example:
 * @code
 * NSArray<NCGlobalPoint *> *linePts = @[
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.617],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.753 longitude:37.620],
 * ];
 * NCLocationPolyline *locationPolyline = [[NCLocationPolyline alloc] initWithPoints:linePts sublocationId:@(7)];
 * NSLog(@"LocationPolyline points %lu", (unsigned long)locationPolyline.points.count);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolyline : NSObject

/** 
 * Default constructor for class NCLocationPolyline 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                         sublocationId:(nullable NSNumber *)sublocationId;

/** 
 * Factory method for class NCLocationPolyline 
 */
+ (nonnull instancetype)locationPolylineWithPoints:(nonnull NSArray<NCGlobalPoint *> *)points
                                     sublocationId:(nullable NSNumber *)sublocationId;

/**
 * Vertices in WGS84 ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCGlobalPoint *> * points;

/**
 * Floor this polyline is attached to, or null for the outdoor map.
 */
@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@end
