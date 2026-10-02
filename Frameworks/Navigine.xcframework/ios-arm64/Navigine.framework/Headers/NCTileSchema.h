#import <Foundation/Foundation.h>

/**
 * Vector tile schema of the outdoor basemap.
 * The built-in stylesheet covers Shortbread fully. OpenMapTiles and Mapbox
 * Streets share the same programmatic rules with schema-aware filters (source
 * layers, site/transit partition, extrude keys, admin levels). Verify new tile
 * sets visually; see TILE_SCHEMA_FOLLOWUP.md.
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
     * OSM Shortbread (versatiles / vector.openstreetmap.org). Default.
     */
    NCTileSchemaShortbread,
    /**
     * OpenMapTiles (MapTiler / Planetiler self-host). Schema-aware filters.
     */
    NCTileSchemaOpenMapTiles,
    /**
     * Mapbox Streets v8 (`mapbox.mapbox-streets-v8`). Schema-aware filters.
     */
    NCTileSchemaMapboxStreets,
};
