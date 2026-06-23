#import <Foundation/Foundation.h>

/**
 * Enum defining the type of cap for polyline ends.
 * Referenced from ``NCPolylineMapObject``.
 */
typedef NS_ENUM(NSInteger, NCCapType)
{
    /**
     * No points added to the end of the line.
     */
    NCCapTypeBUTT,
    /**
     * Two points added to make a square extension.
     */
    NCCapTypeSQUARE,
    /**
     * Six points added in a fan to make a round cap.
     */
    NCCapTypeROUND,
};
