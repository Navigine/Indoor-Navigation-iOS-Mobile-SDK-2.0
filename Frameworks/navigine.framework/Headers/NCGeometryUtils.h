#import "NCGlobalPoint.h"
#import "NCPoint.h"
#import "NCPolygon.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>


@interface NCGeometryUtils : NSObject

/** Get distance between GPS points */
+ (float)distanceBetweenGlobalPoints:(nonnull NCGlobalPoint *)from
                                  to:(nonnull NCGlobalPoint *)to;

/** Get distance between points */
+ (float)distanceBetweenPoints:(nonnull NCPoint *)from
                            to:(nonnull NCPoint *)to;

/** Get length of segment */
+ (float)segmentLength:(nonnull NCSegment *)segment;

/** Get polygon area */
+ (float)polygonArea:(nonnull NCPolygon *)polygon;

/** Get polygon geometric centre */
+ (nonnull NCPoint *)polygonCenter:(nonnull NCPolygon *)polygon;

/** Checks that polygon contains point */
+ (BOOL)polygonContainsPoint:(nonnull NCPolygon *)polygon
                       point:(nonnull NCPoint *)point;

/** Get distance from segment to point */
+ (float)segmentPointDistance:(nonnull NCSegment *)segment
                        point:(nonnull NCPoint *)point;

/** Checks the intersection of two segments */
+ (BOOL)segmentIntersectsSegment:(nonnull NCSegment *)segment1
                        segment2:(nonnull NCSegment *)segment2;

/** Calculate the intersection point of two segments */
+ (nonnull NCPoint *)segmentIntersectionSegment:(nonnull NCSegment *)segment1
                                       segment2:(nonnull NCSegment *)segment2;

/** Calculate the division ratio of a segment by a given segment(if intersects) */
+ (float)divisionRatioBySegment:(nonnull NCSegment *)segment1
                       segment2:(nonnull NCSegment *)segment2;

/** Calculate projection point on a segment */
+ (nonnull NCPoint *)projectionPoint:(nonnull NCSegment *)segment
                               point:(nonnull NCPoint *)point;

/** Calculate the division ratio of a segment by a given point */
+ (float)divisionRatioByPoint:(nonnull NCSegment *)segment
                        point:(nonnull NCPoint *)point;

@end
