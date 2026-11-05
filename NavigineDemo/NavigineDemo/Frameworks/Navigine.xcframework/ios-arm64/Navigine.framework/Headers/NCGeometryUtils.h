#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCPoint.h"
#import "NCPolygon.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>


/**
 * A set of functions for working with geometries.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGeometryUtils : NSObject

/**
 * Get distance between GPS points
 * @param from start point of calculation ``NCGlobalPoint``
 * @param to end point of calculation ``NCGlobalPoint``
 * @return distance in meters
 *
 * @discussion Example:
 * @code
 * // Calculate distance between global points
 * double globalDistance = [NCGeometryUtils distanceBetweenGlobalPointsWithFrom:globalPoint1 to:globalPoint2];
 * NSLog(@"Distance between Moscow and St. Petersburg: %.2f meters", globalDistance);
 * @endcode
 */
+ (float)distanceBetweenGlobalPoints:(nonnull NCGlobalPoint *)from
                                  to:(nonnull NCGlobalPoint *)to;

/**
 * Get distance between points
 * @param from start point of calculation ``NCPoint``
 * @param to end point of calculation ``NCPoint``
 * @return distance in meters
 *
 * @discussion Example:
 * @code
 * // Calculate distance between points
 * double distance = [NCGeometryUtils distanceBetweenPointsWithFrom:point1 to:point2];
 * NSLog(@"Distance between P1 and P2: %.2f meters", distance);
 * @endcode
 */
+ (float)distanceBetweenPoints:(nonnull NCPoint *)from
                            to:(nonnull NCPoint *)to;

/**
 * Get length of segment
 * @param segment segment object for calculation ``NCSegment``
 * @return length in meters
 *
 * @discussion Example:
 * @code
 * // Calculate segment length
 * double length1 = [NCGeometryUtils segmentLengthWithSegment:segment1];
 * double length2 = [NCGeometryUtils segmentLengthWithSegment:segment2];
 * NSLog(@"Segment1 length: %.2f meters", length1);
 * NSLog(@"Segment2 length: %.2f meters", length2);
 * @endcode
 */
+ (float)segmentLength:(nonnull NCSegment *)segment;

/**
 * Get polygon area
 * @param polygon polygon object for calculation ``NCPolygon``
 * @return area in meters
 *
 * @discussion Example:
 * @code
 * // Calculate polygon area
 * double area = [NCGeometryUtils polygonAreaWithPolygon:polygon];
 * NSLog(@"Polygon area: %.2f square meters", area);
 * @endcode
 */
+ (float)polygonArea:(nonnull NCPolygon *)polygon;

/**
 * Get polygon geometric center
 * @param polygon polygon object for calculation ``NCPolygon``
 * @return center point ``NCPoint``
 *
 * @discussion Example:
 * @code
 * // Calculate polygon center
 * NCPoint *center = [NCGeometryUtils polygonCenterWithPolygon:polygon];
 * NSLog(@"Polygon center: (%.2f, %.2f)", center.x, center.y);
 * @endcode
 */
+ (nonnull NCPoint *)polygonCenter:(nonnull NCPolygon *)polygon;

/**
 * Checks that polygon contains point
 * @param polygon polygon object in which looking for contents ``NCPolygon``
 * @param point checking point object ``NCPoint``
 * @return contains or not
 *
 * @discussion Example:
 * @code
 * // Check if polygon contains point
 * NCPoint *insidePoint = [[NCPoint alloc] initWithX:5.0 y:5.0];
 * NCPoint *outsidePoint = [[NCPoint alloc] initWithX:15.0 y:15.0];
 * BOOL containsInside = [NCGeometryUtils polygonContainsPointWithPolygon:polygon point:insidePoint];
 * BOOL containsOutside = [NCGeometryUtils polygonContainsPointWithPolygon:polygon point:outsidePoint];
 * NSLog(@"Polygon contains inside point: %@", containsInside ? @"YES" : @"NO");
 * NSLog(@"Polygon contains outside point: %@", containsOutside ? @"YES" : @"NO");
 * @endcode
 */
+ (BOOL)polygonContainsPoint:(nonnull NCPolygon *)polygon
                       point:(nonnull NCPoint *)point;

/**
 * Get distance from segment to point
 * @param segment start segment of calculation ``NCSegment``
 * @param point end point of calculation ``NCPoint``
 * @return distance in meters
 *
 * @discussion Example:
 * @code
 * // Calculate distance from segment to point
 * double distanceToPoint = [NCGeometryUtils segmentPointDistanceWithSegment:segment1 point:testPoint];
 * NSLog(@"Distance from segment1 to test point: %.2f meters", distanceToPoint);
 * @endcode
 */
+ (float)segmentPointDistance:(nonnull NCSegment *)segment
                        point:(nonnull NCPoint *)point;

/**
 * Checks the intersection of two segments
 * @param segment1 first segment of calculation ``NCSegment``
 * @param segment2 second segment of calculation ``NCSegment``
 * @return intersects or not
 *
 * @discussion Example:
 * @code
 * // Check if segments intersect
 * BOOL intersects = [NCGeometryUtils segmentIntersectsSegmentWithSegment1:segment1 segment2:segment2];
 * NSLog(@"Segments intersect: %@", intersects ? @"YES" : @"NO");
 * @endcode
 */
+ (BOOL)segmentIntersectsSegment:(nonnull NCSegment *)segment1
                        segment2:(nonnull NCSegment *)segment2;

/**
 * Calculate the intersection point of two segments
 * @param segment1 first segment of calculation ``NCSegment``
 * @param segment2 second segment of calculation ``NCSegment``
 * @return intersection point ``NCPoint``
 *
 * @discussion Example:
 * @code
 * // Calculate intersection point
 * NCPoint *intersection = [NCGeometryUtils segmentIntersectionSegmentWithSegment1:segment1 segment2:segment2];
 * NSLog(@"Intersection point: (%.2f, %.2f)", intersection.x, intersection.y);
 * @endcode
 */
+ (nonnull NCPoint *)segmentIntersectionSegment:(nonnull NCSegment *)segment1
                                       segment2:(nonnull NCSegment *)segment2;

/**
 * Calculate the division ratio of a segment by a given segment(if intersects)
 * @param segment1 first segment of calculation ``NCSegment``
 * @param segment2 second segment of calculation ``NCSegment``
 * @return division ratio
 *
 * @discussion Example:
 * @code
 * // Calculate division ratio
 * double divisionRatio = [NCGeometryUtils divisionRatioBySegmentWithSegment1:segment1 segment2:segment2];
 * NSLog(@"Division ratio: %.2f", divisionRatio);
 * @endcode
 */
+ (float)divisionRatioBySegment:(nonnull NCSegment *)segment1
                       segment2:(nonnull NCSegment *)segment2;

/**
 * Calculate projection point on a segment
 * @param segment segment of calculation ``NCSegment``
 * @param r division ratio
 * @return ratio point ``NCPoint``
 *
 * @discussion Example:
 * @code
 * // Get point at specific ratio
 * double ratio = 0.5;
 * NCPoint *ratioPoint = [NCGeometryUtils getRatioPointWithSegment:segment1 r:ratio];
 * NSLog(@"Point at ratio %.1f: (%.2f, %.2f)", ratio, ratioPoint.x, ratioPoint.y);
 * @endcode
 */
+ (nonnull NCPoint *)getRatioPoint:(nonnull NCSegment *)segment
                                 r:(double)r;

/**
 * Calculate the division ratio of a segment by a given point
 * Calculate projection point on a segment
 * @param segment segment of calculation ``NCSegment``
 * @param point point of calculation ``NCPoint``
 * @return division ratio
 *
 * @discussion Example:
 * @code
 * // Calculate projection ratio
 * double projectionRatio = [NCGeometryUtils getProjectionRatioWithSegment:segment1 point:testPoint];
 * NSLog(@"Projection ratio: %.2f", projectionRatio);
 * @endcode
 */
+ (double)getProjectionRatio:(nonnull NCSegment *)segment
                       point:(nonnull NCPoint *)point;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
