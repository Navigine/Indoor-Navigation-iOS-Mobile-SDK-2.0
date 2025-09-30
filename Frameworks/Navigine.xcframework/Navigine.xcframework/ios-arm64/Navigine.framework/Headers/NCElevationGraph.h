#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;


/**
 * @file NCElevationGraph.h
 * @brief @copybrief NCElevationGraph
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 *
 * @brief Сlass describing a graph that connects the sublocations.
 *
 * Referenced from @see Location "Location"
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCElevationGraph : NSObject

/**
 * @brief List of edges that connect two sublocations @see GraphEdge "GraphEdge".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_ElevationGraph_getEdges
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_ElevationGraph_getEdges
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
