#import <Foundation/Foundation.h>

/**
 * @file NCMapObjectType.h
 * @brief @copybrief NCMapObjectType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @brief Enum underlying type of map object
 *
 * Referenced from @see MapObject "MapObject".
 *
 */
typedef NS_ENUM(NSInteger, NCMapObjectType)
{
    /**
     * @brief icon
     *
     * @see IconMapObject "IconMapObject"
     */
    NCMapObjectTypeICON,
    /**
     * @brief flat icon
     *
     * @see FlatIconMapObject "FlatIconMapObject"
     */
    NCMapObjectTypeFLATICON,
    /**
     * @brief polyline
     *
     * @see PolylineMapObject "PolylineMapObject"
     */
    NCMapObjectTypePOLYLINE,
    /**
     * @brief circle
     *
     * @see CircleMapObject "CircleMapObject"
     */
    NCMapObjectTypeCIRCLE,
};
