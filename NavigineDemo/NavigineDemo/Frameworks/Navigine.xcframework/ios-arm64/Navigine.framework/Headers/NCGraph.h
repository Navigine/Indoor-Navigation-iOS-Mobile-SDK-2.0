#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;
@class NCGraphVertex;


/**
 *
 * Object describing graph in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraph : NSObject

/** List of connected vertexes (@see GraphVertex) */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphVertex *> * vertexes;

/** List of edges that connected vertexes (@see GraphEdge) */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
