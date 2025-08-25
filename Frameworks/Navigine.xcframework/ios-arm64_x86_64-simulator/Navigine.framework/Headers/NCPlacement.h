#import <Foundation/Foundation.h>

/**
 * @file NCPlacement.h
 * @brief @copybrief NCPlacement
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Enum defining the placement mode for points along a polyline.
 *
 * Referenced from @see DottedPolylineMapObject "DottedPolylineMapObject".
 *
 */
typedef NS_ENUM(NSInteger, NCPlacement)
{
    /**
     * @brief Places points at each vertex of the polyline.
     */
    NCPlacementVERTEX,
    /**
     * @brief Places points at the midpoint of each polyline segment.
     */
    NCPlacementMIDPOINT,
    /**
     * @brief Places points at regular intervals along the polyline, controlled by spacing parameters.
     */
    NCPlacementSPACED,
};
