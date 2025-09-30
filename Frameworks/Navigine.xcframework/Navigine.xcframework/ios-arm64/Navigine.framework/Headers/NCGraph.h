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
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Graph_getVertices
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Graph_getVertices
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphVertex *> * vertexes;

/**
 * @brief List of edges that connected vertexes @see GraphEdge "GraphEdge"
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Graph_getEdges
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Graph_getEdges
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
