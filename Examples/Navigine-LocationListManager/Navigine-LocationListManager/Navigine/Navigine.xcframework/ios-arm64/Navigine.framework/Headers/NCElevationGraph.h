#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;


/**
 *
 * Сlass describing a graph that connects the sublocations.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCElevationGraph : NSObject

/** list of edges that connect two sublocations (@see GraphEdge). */
@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
