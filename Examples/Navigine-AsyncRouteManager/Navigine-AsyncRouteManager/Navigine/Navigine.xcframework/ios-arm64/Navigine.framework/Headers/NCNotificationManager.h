#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


/**
 *
 * Class is used to manage local notifications
 * Notification should be created in CMS. Notification handle iBeacon signals,
 * detect proximity and notify user about event.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotificationManager : NSObject

/**
 *
 * Method is used to add listener to handle new notification events (@see NotificationListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
