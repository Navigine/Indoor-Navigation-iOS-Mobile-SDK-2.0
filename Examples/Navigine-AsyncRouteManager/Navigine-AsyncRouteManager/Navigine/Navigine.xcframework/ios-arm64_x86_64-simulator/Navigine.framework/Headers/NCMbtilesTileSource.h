#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Local MBTiles pack of outdoor vector tiles (`format=pbf` or `mvt`).
 * Tiles are read only from this file — no network. Default row numbering is
 * TMS; metadata `scheme=xyz` disables the Y flip.
 * Referenced from ``NCTileProvider``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMbtilesTileSource : NSObject

/** 
 * Default constructor for class NCMbtilesTileSource 
 */
- (nonnull instancetype)initWithPath:(nonnull NSString *)path;

/** 
 * Factory method for class NCMbtilesTileSource 
 */
+ (nonnull instancetype)mbtilesTileSourceWithPath:(nonnull NSString *)path;

/**
 *
 * @discussion Example:
 * @code
 * NCMbtilesTileSource *offline = [[NCMbtilesTileSource alloc]
 *    initWithPath:@"/path/to/map.mbtiles"];
 * @endcode
 * Absolute path to the `.mbtiles` file.
 */
@property (nonatomic, readonly, nonnull) NSString * path;

@end
