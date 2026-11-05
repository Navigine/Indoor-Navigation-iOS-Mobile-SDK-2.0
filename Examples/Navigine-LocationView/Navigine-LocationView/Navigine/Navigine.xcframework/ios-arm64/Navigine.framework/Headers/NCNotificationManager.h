#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


/**
 * Class is used to manage local ``NCNotification``s
 * Notification should be created in CMS. Notification handle iBeacon signals,
 * detect proximity and notify user about event.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotificationManager : NSObject

/**
 * Method is used to add ``NCNotificationListener`` class element which will notify
 * all incoming local notification events.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCNotificationListener`` listener class.
 *
 * @discussion Example:
 * @code
 * // Add notification listener
 * [self.notificationManager addNotificationListener:self.notificationListener];
 * NSLog(@"Added notification listener");
 * @endcode
 */
- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

/**
 * Method is used for removing previously added ``NCNotificationListener`` class element.
 * @param listener Corresponding ``NCNotificationListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove notification listener
 * [self.notificationManager removeNotificationListener:self.notificationListener];
 * NSLog(@"Removed notification listener");
 * @endcode
 */
- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
