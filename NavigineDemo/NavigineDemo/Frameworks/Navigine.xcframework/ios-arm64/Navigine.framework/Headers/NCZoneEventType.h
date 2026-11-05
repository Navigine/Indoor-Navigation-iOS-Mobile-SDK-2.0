#import <Foundation/Foundation.h>

/**
 * enum described zone event types
 * Referenced from ``NCZoneEvent``.
 *
 * @discussion Example:
 * @code
 * // Get all zone event type values
 * NSLog(@"Available zone event types:");
 * NSLog(@"  - NCZoneEventTypeEnter: %ld", (long)NCZoneEventTypeEnter);
 * NSLog(@"  - NCZoneEventTypeExit: %ld", (long)NCZoneEventTypeExit);
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCZoneEventType)
{
    /**
     * Happens when user enters particular zone;
     */
    NCZoneEventTypeEnter,
    /**
     * Happens when user leaves particular zone, sublocation has been changed or zone has been removed;
     */
    NCZoneEventTypeExit,
};
