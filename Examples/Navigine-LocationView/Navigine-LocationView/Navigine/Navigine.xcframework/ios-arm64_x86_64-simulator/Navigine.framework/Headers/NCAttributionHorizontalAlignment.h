#import <Foundation/Foundation.h>

/**
 * Horizontal placement of the OSM attribution overlay.
 * Used with ``NCAttributionAlignment``.
 */
typedef NS_ENUM(NSInteger, NCAttributionHorizontalAlignment)
{
    /**
     * Align to the left edge of the map.
     */
    NCAttributionHorizontalAlignmentLEFT,
    /**
     * Center horizontally.
     */
    NCAttributionHorizontalAlignmentCENTER,
    /**
     * Align to the right edge of the map.
     */
    NCAttributionHorizontalAlignmentRIGHT,
};
