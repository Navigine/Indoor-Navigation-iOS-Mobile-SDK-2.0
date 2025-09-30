#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCNotification;


/**
 * @file NCNotificationListener.h
 * @brief @copybrief NCNotificationListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see NotificationManager "NotificationManager"
 * detects local notification events.
 *
 * Referenced from @see NotificationManager "NotificationManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCNotificationListener <NSObject>

/**
 *
 * @brief Called when iBeacon signal mathed all parameters in notification
 * @param notification notification instance created in CMS @see Notification "Notification".
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_NotificationListener_onNotificationLoaded
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_NotificationListener_onNotificationLoaded
 *
 *
 */
- (void)onNotificationLoaded:(nullable NCNotification *)notification;

/**
 *
 * @brief Called if unable to calculate notification or network errors.
 * @param error handled error.
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_NotificationListener_onNotificationFailed
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_NotificationListener_onNotificationFailed
 *
 *
 */
- (void)onNotificationFailed:(nullable NSError *)error;

@end
