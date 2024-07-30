#import "NCExport.h"
#import "NCZoneEvent.h"
#import <Foundation/Foundation.h>


/**
 * Class is used to handle events coming from ZoneManager (@see ZoneManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCZoneListener <NSObject>

/**
 *
 * @method onZoneEvent - called when user handle particular zone event
 * @parameter zoneEvent - handled zone event (@see ZoneEvent).
 *
 */
- (void)onZoneEvent:(nonnull NCZoneEvent *)zoneEvent;

@end
