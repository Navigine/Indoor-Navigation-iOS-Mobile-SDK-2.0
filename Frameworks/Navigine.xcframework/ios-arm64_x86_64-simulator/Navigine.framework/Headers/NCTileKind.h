#import <Foundation/Foundation.h>

/**
 * Payload of a ``NCTileProvider``.
 * `vector` is MVT and uses `schema`. `raster` is PNG, JPEG, or WebP imagery
 * on `LocationWindow.tileProvider`; `schema` is ignored and outdoor vector
 * geometry and labels are hidden. Indoor floors stay on top.
 */
typedef NS_ENUM(NSInteger, NCTileKind)
{
    /**
     *
     * @discussion Example:
     * @code
     * NSArray<NSNumber *> *kinds = @[@(NCTileKindVector), @(NCTileKindRaster)];
     * NSLog(@"Tile kinds: %lu", (unsigned long)kinds.count);
     * @endcode
     * Vector tiles (MVT). Default.
     */
    NCTileKindVector,
    /**
     * Raster imagery tiles.
     */
    NCTileKindRaster,
};
