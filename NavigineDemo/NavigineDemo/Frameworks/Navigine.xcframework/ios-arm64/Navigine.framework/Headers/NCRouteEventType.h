#import <Foundation/Foundation.h>

/**
 * @file NCRouteEventType.h
 * @brief @copybrief NCRouteEventType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Enum described toute event types.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 */
typedef NS_ENUM(NSInteger, NCRouteEventType)
{
    /**
     * @brief An event showing a left turn.
     */
    NCRouteEventTypeTURNLEFT,
    /**
     * @brief An event showing a right turn.
     */
    NCRouteEventTypeTURNRIGHT,
    /**
     * @brief An event showing a chaning of sublocation (floor).
     */
    NCRouteEventTypeTRANSITION,
};
