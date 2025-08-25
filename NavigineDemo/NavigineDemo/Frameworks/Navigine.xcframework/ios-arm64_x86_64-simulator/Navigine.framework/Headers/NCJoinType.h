#import <Foundation/Foundation.h>

/**
 * @file NCJoinType.h
 * @brief @copybrief NCJoinType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Enum defining the type of join for polyline segments.
 *
 * Referenced from @see PolylineMapObject "PolylineMapObject".
 *
 */
typedef NS_ENUM(NSInteger, NCJoinType)
{
    /**
     * @brief No points added at the line join.
     */
    NCJoinTypeMITER,
    /**
     * @brief One point added to flatten the corner of a join.
     */
    NCJoinTypeBEVEL,
    /**
     * @brief Five points added in a fan to make a round outer join.
     */
    NCJoinTypeROUND,
};
