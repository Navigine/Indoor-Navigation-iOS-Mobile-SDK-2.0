#import <Foundation/Foundation.h>
@class NCGraphEdge;


@interface NCElevationGraph : NSObject

@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
