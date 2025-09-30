#import <Foundation/Foundation.h>

/**
 * @file NCCapType.h
 * @brief @copybrief NCCapType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Enum defining the type of cap for polyline ends.
 *
 * Referenced from @see PolylineMapObject "PolylineMapObject".
 *
 */
typedef NS_ENUM(NSInteger, NCCapType)
{
    /**
     * @brief No points added to the end of the line.
     */
    NCCapTypeBUTT,
    /**
     * @brief Two points added to make a square extension.
     */
    NCCapTypeSQUARE,
    /**
     * @brief Six points added in a fan to make a round cap.
     */
    NCCapTypeROUND,
};
