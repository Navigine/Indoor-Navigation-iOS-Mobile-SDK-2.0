#import "NCExport.h"
#import "NCZoneEvent.h"
#import <Foundation/Foundation.h>


/**
 * Class provides a callback to be invoked when ``NCZoneManager``
 * detects entering/leaving zone events.
 * Referenced from ``NCZoneManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCZoneListener <NSObject>

/**
 * Called when user handle particular zone event
 * @param zoneEvent handled ``NCZoneEvent``.
 *
 * @discussion Example:
 * @code
 * - (void)onZoneEvent:(NCZoneEvent *)zoneEvent {
 *    NSLog(@"Zone event detected");
 *    [self.example demonstrateZoneEventUsage:zoneEvent];
 * }
 * @endcode
 */
- (void)onZoneEvent:(nonnull NCZoneEvent *)zoneEvent;

@end
