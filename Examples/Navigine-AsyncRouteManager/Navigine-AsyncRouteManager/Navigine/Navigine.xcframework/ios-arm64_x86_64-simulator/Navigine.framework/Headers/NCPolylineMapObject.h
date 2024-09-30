#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object represents polyline on location view.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolylineMapObject : NCMapObject

/**
 *
 * Method is used to specify source pyline of object.
 * @param polyline - metrics coordinate of pyline (@see LocationPoint).
 *
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

/**
 *
 * Method is used to specify width of a line.
 * @param width - width of a line in pixels.
 *
 */
- (BOOL)setWidth:(float)width;

/**
 *
 * Method is used to specify color of object.
 * @param red - red RGBA component.
 * @param green - green RGBA component.
 * @param blue - blue RGBA component.
 * @param alpha - Opacity multiplicator. Values below 0 will be set to 0. Default: 1.
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
