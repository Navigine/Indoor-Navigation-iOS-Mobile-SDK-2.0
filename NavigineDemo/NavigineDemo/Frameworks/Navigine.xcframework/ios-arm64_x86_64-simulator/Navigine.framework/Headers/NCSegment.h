#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 *
 * Line between two points.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSegment : NSObject
- (nonnull instancetype)initWithStart:(nonnull NCPoint *)start
                                  end:(nonnull NCPoint *)end;
+ (nonnull instancetype)segmentWithStart:(nonnull NCPoint *)start
                                     end:(nonnull NCPoint *)end;

/** Starting point of the segment. */
@property (nonatomic, readonly, nonnull) NCPoint * start;

/** End point of the segment. */
@property (nonatomic, readonly, nonnull) NCPoint * end;

@end
