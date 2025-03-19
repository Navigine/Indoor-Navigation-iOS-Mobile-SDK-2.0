#import <Foundation/Foundation.h>

/**
 * @file NCZoneEventType.h
 * @brief @copybrief NCZoneEventType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief enum described zone event types
 *
 * Referenced from @see ZoneEvent "ZoneEvent".
 *
 */
typedef NS_ENUM(NSInteger, NCZoneEventType)
{
    /**
     * @brief Happens when user enters paticular zone;
     */
    NCZoneEventTypeEnter,
    /**
     * @brief Happens when user leaves paticular zone, sublocation has been changed or zone has been removed;
     */
    NCZoneEventTypeExit,
};
