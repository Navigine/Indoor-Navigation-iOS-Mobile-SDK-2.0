#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCGraphEdge;


NAVIGINE_EXPORT
@interface NCElevationGraph : NSObject

@property (nonatomic, nonnull, readonly) NSArray<NCGraphEdge *> * edges;

@end
