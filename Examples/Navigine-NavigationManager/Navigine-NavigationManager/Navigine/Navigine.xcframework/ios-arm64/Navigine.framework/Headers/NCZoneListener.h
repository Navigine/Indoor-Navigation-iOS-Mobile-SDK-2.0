#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCZone;


/**
 * Class is used to handle events coming from ZoneManager (@see ZoneManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCZoneListener <NSObject>

/**
 *
 * @method onEnterZone - called when user enter particular zone
 * @parameter zone - zone instance drawn in CMS (@see Zone).
 *
 */
- (void)onEnterZone:(nullable NCZone *)zone;

/**
 *
 * @method onLeaveZone - called when user leave particular zone
 * @parameter zone - zone instance drawn in CMS (@see Zone).
 *
 */
- (void)onLeaveZone:(nullable NCZone *)zone;

@end
