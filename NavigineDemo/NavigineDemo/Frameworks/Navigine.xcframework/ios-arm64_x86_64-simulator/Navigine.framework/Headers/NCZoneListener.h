#import "NCExport.h"
#import "NCZoneEvent.h"
#import <Foundation/Foundation.h>


/**
 * @file NCZoneListener.h
 * @brief @copybrief NCZoneListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see ZoneManager "ZoneManager"
 * detects entering/leaving zone events.
 *
 * Referenced from @see ZoneManager "ZoneManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCZoneListener <NSObject>

/**
 *
 * @brief Called when user handle particular zone event
 * @param zoneEvent handled @see ZoneEvent "ZoneEvent".
 *
 */
- (void)onZoneEvent:(nonnull NCZoneEvent *)zoneEvent;

@end
