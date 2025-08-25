#import <Foundation/Foundation.h>

/**
 * @file NCMapObjectType.h
 * @brief @copybrief NCMapObjectType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Enum defining the type of map object.
 *
 * Referenced from @see MapObject "MapObject".
 *
 */
typedef NS_ENUM(NSInteger, NCMapObjectType)
{
    /**
     * @brief Icon.
     * @see IconMapObject "IconMapObject"
     */
    NCMapObjectTypeICON,
    /**
     * @brief Polygon.
     * @see PolygonMapObject "PolygonMapObject"
     */
    NCMapObjectTypePOLYGON,
    /**
     * @brief Polyline.
     * @see PolylineMapObject "PolylineMapObject"
     */
    NCMapObjectTypePOLYLINE,
    /**
     * @brief DottedPolyline.
     * @see DottedPolylineMapObject "DottedPolylineMapObject"
     */
    NCMapObjectTypeDOTTEDPOLYLINE,
    /**
     * @brief Circle.
     * @see CircleMapObject "CircleMapObject"
     */
    NCMapObjectTypeCIRCLE,
};
