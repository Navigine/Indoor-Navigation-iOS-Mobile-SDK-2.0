#import <Foundation/Foundation.h>

/**
 * Enum described supported image types
 * Referenced from ``NCImage``.
 */
typedef NS_ENUM(NSInteger, NCImageType)
{
    /**
     * PNG format
     */
    NCImageTypePNG,
    /**
     * SVG format
     */
    NCImageTypeSVG,
    /**
     * JPG format
     */
    NCImageTypeJPG,
};
