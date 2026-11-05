#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * line between two points.
 *
 * @discussion Example:
 * @code
 * // Create segments
 * NCSegment *segment1 = [[NCSegment alloc] initWithStart:start1 end:end1];
 * NCSegment *segment2 = [[NCSegment alloc] initWithStart:start2 end:end2];
 * NSLog(@"Created segments: S1((%.1f, %.1f) -> (%.1f, %.1f)), S2((%.1f, %.1f) -> (%.1f, %.1f))",
 *      segment1.start.x, segment1.start.y, segment1.end.x, segment1.end.y,
 *      segment2.start.x, segment2.start.y, segment2.end.x, segment2.end.y);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSegment : NSObject

/** 
 * Default constructor for class NCSegment 
 */
- (nonnull instancetype)initWithStart:(nonnull NCPoint *)start
                                  end:(nonnull NCPoint *)end;

/** 
 * Factory method for class NCSegment 
 */
+ (nonnull instancetype)segmentWithStart:(nonnull NCPoint *)start
                                     end:(nonnull NCPoint *)end;

/**
 * Start point of the segment.
 *
 * @discussion Example:
 * @code
 * // Get start point
 * NCPoint *segment1Start = segment1.start;
 * NSLog(@"Segment1 start point: (%.1f, %.1f)", segment1Start.x, segment1Start.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCPoint * start;

/**
 * End point of the segment.
 *
 * @discussion Example:
 * @code
 * // Get end point
 * NCPoint *segment1End = segment1.end;
 * NSLog(@"Segment1 end point: (%.1f, %.1f)", segment1End.x, segment1End.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCPoint * end;

@end
