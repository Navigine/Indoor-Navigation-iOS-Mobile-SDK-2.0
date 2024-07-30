#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCNotification;


/**
 * Class is used to handle events coming from NotificationManager (@see NotificationManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCNotificationListener <NSObject>

/**
 *
 * @method onNotificationLoaded - called when iBeacon signal mathed all parameters in notification
 * @parameter notification - notification instance created in CMS (@see Notification).
 *
 */
- (void)onNotificationLoaded:(nullable NCNotification *)notification;

/**
 *
 * @method onNotificationFailed - called if unable to calculate notification or network errors.
 * @parameter error - handled error.
 *
 */
- (void)onNotificationFailed:(nullable NSError *)error;

@end
