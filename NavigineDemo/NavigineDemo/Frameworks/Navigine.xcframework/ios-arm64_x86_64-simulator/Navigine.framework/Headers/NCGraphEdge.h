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
 */
@property (nonatomic, readonly) float weight;

/**
 * @brief Destination vertex id @see GraphVertex "GraphVertex"
 */
@property (nonatomic, readonly) int32_t dst;

/**
 * @brief Source vertex id @see GraphVertex "GraphVertex"
 */
@property (nonatomic, readonly) int32_t src;

/**
 * @brief Edge weight coefficient.
 */
@property (nonatomic, readonly) int32_t weightCoef;

@end
