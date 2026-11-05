#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;
@class NCGraphVertex;


/**
 * Class is used for storing graph.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraph : NSObject

/**
 * List of connected vertexes ``NCGraphVertex``
 *
 * @discussion Example:
 * @code
 * // Get graph vertices
 * NSArray<NCGraphVertex *> *vertices = [graph getVertices];
 * NSLog(@"Number of graph vertices: %lu", (unsigned long)vertices.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphVertex *> * vertexes;

/**
 * List of edges that connected vertexes ``NCGraphEdge``
 *
 * @discussion Example:
 * @code
 * // Get graph edges
 * NSArray<NCGraphEdge *> *edges = [graph getEdges];
 * NSLog(@"Number of graph edges: %lu", (unsigned long)edges.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
