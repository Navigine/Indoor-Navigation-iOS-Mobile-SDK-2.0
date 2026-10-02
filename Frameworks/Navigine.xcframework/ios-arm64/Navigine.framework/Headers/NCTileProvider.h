#import "NCExport.h"
#import "NCHttpTileSource.h"
#import "NCMbtilesTileSource.h"
#import "NCTileKind.h"
#import "NCTileSchema.h"
#import <Foundation/Foundation.h>

/**
 * Outdoor tile source: vector MVT or raster imagery.
 * Set either `http` or `mbtiles`. When `mbtiles` is set, tiles are read only
 * from that file — no network. `kind` selects the payload. For `vector`,
 * `schema` must match the tiles. For `raster`, `schema` is ignored.
 * Null `LocationWindow.tileProvider` keeps the default OSM Shortbread endpoint.
 * Referenced from ``NCLocationWindow`` `tileProvider`.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTileProvider : NSObject

/** 
 * Default constructor for class NCTileProvider 
 */
- (nonnull instancetype)initWithSchema:(NCTileSchema)schema
                                  http:(nullable NCHttpTileSource *)http
                               mbtiles:(nullable NCMbtilesTileSource *)mbtiles
                               minZoom:(int32_t)minZoom
                               maxZoom:(int32_t)maxZoom
                           attribution:(nullable NSString *)attribution
                                  kind:(NCTileKind)kind;

/** 
 * Factory method for class NCTileProvider 
 */
+ (nonnull instancetype)tileProviderWithSchema:(NCTileSchema)schema
                                          http:(nullable NCHttpTileSource *)http
                                       mbtiles:(nullable NCMbtilesTileSource *)mbtiles
                                       minZoom:(int32_t)minZoom
                                       maxZoom:(int32_t)maxZoom
                                   attribution:(nullable NSString *)attribution
                                          kind:(NCTileKind)kind;

/** 
 * Default constructor for class NCTileProvider 
 */
- (nonnull instancetype)initWithSchema:(NCTileSchema)schema
                                  http:(nullable NCHttpTileSource *)http
                               mbtiles:(nullable NCMbtilesTileSource *)mbtiles
                           attribution:(nullable NSString *)attribution;

/** 
 * Factory method for class NCTileProvider 
 */
+ (nonnull instancetype)tileProviderWithSchema:(NCTileSchema)schema
                                          http:(nullable NCHttpTileSource *)http
                                       mbtiles:(nullable NCMbtilesTileSource *)mbtiles
                                   attribution:(nullable NSString *)attribution;

/**
 *
 * @discussion Example:
 * @code
 * NCTileProvider *osmHttp = [[NCTileProvider alloc]
 *    initWithSchema:NCTileSchemaOpenMapTiles
 *              http:http
 *           mbtiles:nil
 *           minZoom:0
 *           maxZoom:14
 *      attribution:nil
 *              kind:NCTileKindVector];
 * NCTileProvider *mbtiles = [[NCTileProvider alloc]
 *    initWithSchema:NCTileSchemaShortbread
 *              http:nil
 *           mbtiles:offline
 *           minZoom:0
 *           maxZoom:14
 *      attribution:nil
 *              kind:NCTileKindVector];
 * @endcode
 * Tile schema ``NCTileSchema``. Used when `kind` is vector.
 */
@property (nonatomic, readonly) NCTileSchema schema;

/**
 * Remote XYZ source ``NCHttpTileSource``. Ignored when mbtiles is set.
 */
@property (nonatomic, readonly, nullable) NCHttpTileSource * http;

/**
 * Local MBTiles pack ``NCMbtilesTileSource``.
 */
@property (nonatomic, readonly, nullable) NCMbtilesTileSource * mbtiles;

/**
 * Minimum source zoom. Default: 0.
 */
@property (nonatomic, readonly) int32_t minZoom;

/**
 * Maximum source zoom (camera overzooms above this). Default: 14.
 */
@property (nonatomic, readonly) int32_t maxZoom;

/**
 * Attribution overlay text. Null on a vector source: `© OpenStreetMap contributors`.
 */
@property (nonatomic, readonly, nullable) NSString * attribution;

/**
 * Vector MVT or raster imagery ``NCTileKind``. Default: vector.
 */
@property (nonatomic, readonly) NCTileKind kind;

@end
