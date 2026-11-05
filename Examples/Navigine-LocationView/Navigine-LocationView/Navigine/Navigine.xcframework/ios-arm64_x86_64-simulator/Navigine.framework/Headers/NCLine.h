#import "NCExport.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>

/**
 * A polyline with specified list of segments ``NCSegment``
 * Referenced from ``NCPolylineMapObject``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLine : NSObject

/** 
 * Default constructor for class NCLine 
 */
- (nonnull instancetype)initWithSegments:(nonnull NSArray<NCSegment *> *)segments;

/** 
 * Factory method for class NCLine 
 */
+ (nonnull instancetype)lineWithSegments:(nonnull NSArray<NCSegment *> *)segments;

/**
 * List of segments to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCSegment *> * segments;

@end
