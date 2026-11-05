#import <Foundation/Foundation.h>

/**
 * Vertical placement of the OSM attribution overlay.
 * Used with ``NCAttributionAlignment``.
 */
typedef NS_ENUM(NSInteger, NCAttributionVerticalAlignment)
{
    /**
     * Align to the top edge of the map.
     */
    NCAttributionVerticalAlignmentTOP,
    /**
     * Align to the bottom edge of the map.
     */
    NCAttributionVerticalAlignmentBOTTOM,
};
