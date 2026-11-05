#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCPolygonMapObject;
@class NCPolylineMapObject;


/**
 * Polygons and polylines created from one GeoJSON document.
 * Points are not imported. The host styles and removes these objects itself.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGeoJsonImport : NSObject

/**
 * Polygons from Polygon and MultiPolygon geometries.
 */
- (nonnull NSArray<NCPolygonMapObject *> *)polygons;

/**
 * Polylines from LineString and MultiLineString geometries.
 */
- (nonnull NSArray<NCPolylineMapObject *> *)polylines;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
