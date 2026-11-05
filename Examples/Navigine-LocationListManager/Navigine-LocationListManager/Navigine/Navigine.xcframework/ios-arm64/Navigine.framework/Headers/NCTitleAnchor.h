#import <Foundation/Foundation.h>

/**
 * Anchor position of a map object title relative to its placement point.
 * Referenced from ``NCTitleStyle``, ``NCMapObject``.
 */
typedef NS_ENUM(NSInteger, NCTitleAnchor)
{
    /**
     * Center of the text.
     */
    NCTitleAnchorCENTER,
    /**
     * Top edge of the text.
     */
    NCTitleAnchorTOP,
    /**
     * Bottom edge of the text.
     */
    NCTitleAnchorBOTTOM,
    /**
     * Left edge of the text.
     */
    NCTitleAnchorLEFT,
    /**
     * Right edge of the text.
     */
    NCTitleAnchorRIGHT,
    /**
     * Top-left corner of the text.
     */
    NCTitleAnchorTOPLEFT,
    /**
     * Top-right corner of the text.
     */
    NCTitleAnchorTOPRIGHT,
    /**
     * Bottom-left corner of the text.
     */
    NCTitleAnchorBOTTOMLEFT,
    /**
     * Bottom-right corner of the text.
     */
    NCTitleAnchorBOTTOMRIGHT,
};
