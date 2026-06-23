#import <Foundation/Foundation.h>

/**
 * Enum defining the type of map object.
 * Referenced from ``NCMapObject``.
 */
typedef NS_ENUM(NSInteger, NCMapObjectType)
{
    /**
     * Icon.
     * See also: ``NCIconMapObject``.
     */
    NCMapObjectTypeICON,
    /**
     * Polygon.
     * See also: ``NCPolygonMapObject``.
     */
    NCMapObjectTypePOLYGON,
    /**
     * Polyline.
     * See also: ``NCPolylineMapObject``.
     */
    NCMapObjectTypePOLYLINE,
    /**
     * DottedPolyline.
     * See also: ``NCDottedPolylineMapObject``.
     */
    NCMapObjectTypeDOTTEDPOLYLINE,
    /**
     * Circle.
     * See also: ``NCCircleMapObject``.
     */
    NCMapObjectTypeCIRCLE,
    /**
     * Model.
     * See also: ``NCModelMapObject``.
     */
    NCMapObjectTypeMODEL,
    /**
     * Icon cluster.
     * See also: ``NCClusterMapObject``.
     */
    NCMapObjectTypeCLUSTERMAPOBJECT,
};
