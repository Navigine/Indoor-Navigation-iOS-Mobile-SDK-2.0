#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;
@class NCGraphVertex;


/**
 * @file NCGraph.h
 * @brief @copybrief NCGraph
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 *
 * @brief Class is used for storing graph.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraph : NSObject

/**
 * @brief List of connected vertexes @see GraphVertex "GraphVertex"
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphVertex *> * vertexes;

/**
 * @brief List of edges that connected vertexes @see GraphEdge "GraphEdge"
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
