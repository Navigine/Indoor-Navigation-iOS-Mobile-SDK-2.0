#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;


/**
 * Class describing a graph that connects the sublocations.
 * Referenced from ``NCLocation``
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCElevationGraph : NSObject

/**
 * List of edges that connect two sublocations ``NCGraphEdge``.
 *
 * @discussion Example:
 * @code
 * // Get elevation graph edges
 * NSArray<NCGraphEdge *> *edges = [elevationGraph getEdges];
 * NSLog(@"Number of elevation graph edges: %lu", (unsigned long)edges.count);
 * // Demonstrate each edge
 * for (int i = 0; i < edges.count; i++) {
 *    NCGraphEdge *edge = edges[i];
 *    NSLog(@"Elevation graph edge %d:", i + 1);
 *    [self demonstrateGraphEdgeUsage:edge];
 * }
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
