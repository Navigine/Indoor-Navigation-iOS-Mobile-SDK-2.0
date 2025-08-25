#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCGraphEdge.h
 * @brief @copybrief NCGraphEdge
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 *
 * @brief Class is used for storing graph edge.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphEdge : NSObject

/**
 * @brief Edge weight.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphEdge_getWeight
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphEdge_getWeight
 *
 *
 */
@property (nonatomic, readonly) float weight;

/**
 * @brief Destination vertex id @see GraphVertex "GraphVertex"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphEdge_getDst
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphEdge_getDst
 *
 *
 */
@property (nonatomic, readonly) int32_t dst;

/**
 * @brief Source vertex id @see GraphVertex "GraphVertex"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphEdge_getSrc
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphEdge_getSrc
 *
 *
 */
@property (nonatomic, readonly) int32_t src;

/**
 * @brief Edge weight coefficient.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphEdge_getWeightCoef
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphEdge_getWeightCoef
 *
 *
 */
@property (nonatomic, readonly) int32_t weightCoef;

@end
