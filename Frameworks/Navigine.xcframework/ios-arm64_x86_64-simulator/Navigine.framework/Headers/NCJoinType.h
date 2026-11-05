#import <Foundation/Foundation.h>

/**
 * Enum defining the type of join for polyline segments.
 * Referenced from ``NCPolylineMapObject``.
 */
typedef NS_ENUM(NSInteger, NCJoinType)
{
    /**
     * No points added at the line join.
     */
    NCJoinTypeMITER,
    /**
     * One point added to flatten the corner of a join.
     */
    NCJoinTypeBEVEL,
    /**
     * Five points added in a fan to make a round outer join.
     */
    NCJoinTypeROUND,
};
