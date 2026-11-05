#import <Foundation/Foundation.h>

/**
 * Enum defining the placement mode for points along a polyline.
 * Referenced from ``NCDottedPolylineMapObject``.
 */
typedef NS_ENUM(NSInteger, NCPlacement)
{
    /**
     * Places points at each vertex of the polyline.
     */
    NCPlacementVERTEX,
    /**
     * Places points at the midpoint of each polyline segment.
     */
    NCPlacementMIDPOINT,
    /**
     * Places points at regular intervals along the polyline, controlled by spacing parameters.
     */
    NCPlacementSPACED,
};
