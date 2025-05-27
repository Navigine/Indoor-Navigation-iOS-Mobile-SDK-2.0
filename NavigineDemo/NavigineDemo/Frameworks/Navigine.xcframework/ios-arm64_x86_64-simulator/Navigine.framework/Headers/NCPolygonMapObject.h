#import "NCExport.h"
#import "NCLocationPolygon.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCPolygonMapObject.h
 * @brief @copybrief NCPolygonMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief represents polygon object on location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygonMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify source polygon of object.
 * @param polygon metrics coordinate of polygon @see LocationPolygon "LocationPolygon".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setPolygon:(nonnull NCLocationPolygon *)polygon;

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
