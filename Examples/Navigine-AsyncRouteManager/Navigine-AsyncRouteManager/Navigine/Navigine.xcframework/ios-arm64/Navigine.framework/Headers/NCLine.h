#import "NCExport.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>

/**
 *
 * A polyline with specified list of segments.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLine : NSObject
- (nonnull instancetype)initWithSegments:(nonnull NSArray<NCSegment *> *)segments;
+ (nonnull instancetype)lineWithSegments:(nonnull NSArray<NCSegment *> *)segments;

/** List of segments to connect. */
@property (nonatomic, readonly, nonnull) NSArray<NCSegment *> * segments;

@end
