#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing graph vertex in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphVertex : NSObject

/** Vertex unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Vertex position in meters (@see Point). */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/** Vertex name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Parameter indicates that a vertex can be used to communicate with external graphs. */
@property (nonatomic, readonly) BOOL isExternal;

/** Parameter indicates that a vertex used in elevation graph (@see ElevationGraph). */
@property (nonatomic, readonly) BOOL isElevation;

@end
