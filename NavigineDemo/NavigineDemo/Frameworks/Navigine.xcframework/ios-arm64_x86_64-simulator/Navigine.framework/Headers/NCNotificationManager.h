#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


/**
 * @file NCNotificationManager.h
 * @brief @copybrief NCNotificationManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 *
 * @brief Class is used to manage local @see Notification "Notification"s
 *
 * Notification should be created in CMS. Notification handle iBeacon signals,
 * detect proximity and notify user about event.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotificationManager : NSObject

/**
 *
 * @brief Method is used to add @see NotificationListener "NotificationListener" class element which will notify
 * all incoming local notification events.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see NotificationListener "NotificationListener" listener class.
 *
 */
- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see NotificationListener "NotificationListener" class element.
 * @param listener Сorresponding @see NotificationListener "NotificationListener" class to remove.
 *
 */
- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
