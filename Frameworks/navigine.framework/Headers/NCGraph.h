#import <Foundation/Foundation.h>
@class NCGraphEdge;
@class NCGraphVertex;


@interface NCGraph : NSObject

@property (nonatomic, nonnull, readonly) NSArray<NCGraphVertex *> * vertexes;

@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
