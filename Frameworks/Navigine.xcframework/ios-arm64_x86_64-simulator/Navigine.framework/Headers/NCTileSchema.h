#import <Foundation/Foundation.h>

/**
 * Vector tile schema of the outdoor basemap.
 * The renderer stylesheet is built for these schemas only. The MVT layers
 * and properties must match the chosen schema.
 */
typedef NS_ENUM(NSInteger, NCTileSchema)
{
    /**
     *
     * @discussion Example:
     * @code
     * NSArray<NSNumber *> *schemas = @[@(NCTileSchemaShortbread), @(NCTileSchemaOpenMapTiles), @(NCTileSchemaMapboxStreets)];
     * NSLog(@"Tile schemas: %lu", (unsigned long)schemas.count);
     * @endcode
     * OSM Shortbread (versatiles / vector.openstreetmap.org).
     */
    NCTileSchemaShortbread,
    /**
     * OpenMapTiles (MapTiler / Planetiler self-host).
     */
    NCTileSchemaOpenMapTiles,
    /**
     * Mapbox Streets v8 (`mapbox.mapbox-streets-v8`).
     */
    NCTileSchemaMapboxStreets,
};
