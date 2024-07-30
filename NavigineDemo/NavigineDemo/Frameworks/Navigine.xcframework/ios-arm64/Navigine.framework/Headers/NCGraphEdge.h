#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing graph edge in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphEdge : NSObject

/** edge weight. */
@property (nonatomic, readonly) float weight;

/** destination vertex id (@see GraphVertex) */
@property (nonatomic, readonly) int32_t dst;

/** source vertex id (@see GraphVertex) */
@property (nonatomic, readonly) int32_t src;

/** edge weight coefficient. */
@property (nonatomic, readonly) int32_t weightCoef;

@end
