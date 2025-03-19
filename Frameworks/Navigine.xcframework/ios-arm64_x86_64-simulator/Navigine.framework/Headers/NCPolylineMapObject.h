#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCPolylineMapObject.h
 * @brief @copybrief NCPolylineMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief represents polyline object on location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolylineMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify source pyline of object.
 * @param polyline metrics coordinate of pyline @see LocationPolyline "LocationPolyline".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

/**
 *
 * @brief Method is used to specify width of a line.
 * @param width width of a line in pixels.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setWidth:(float)width;

/**
 *
 * @brief Method is used to specify color of object.
 * @param red red RGBA component.
 * @param green green RGBA component.
 * @param blue blue RGBA component.
 * @param alpha Opacity multiplicator. Values below 0 will be set to 0. Default: 1.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
