#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCNotification;


/**
 * Class provides a callback to be invoked when ``NCNotificationManager``
 * detects local notification events.
 * Referenced from ``NCNotificationManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCNotificationListener <NSObject>

/**
 * Called when iBeacon signal matched all parameters in notification
 * @param notification notification instance created in CMS ``NCNotification``.
 *
 * @discussion Example:
 * @code
 * - (void)onNotificationLoaded:(NCNotification *)notification {
 *    NSLog(@"Notification loaded");
 *    [self.example demonstrateNotificationUsage:notification];
 * }
 * @endcode
 */
- (void)onNotificationLoaded:(nullable NCNotification *)notification;

/**
 * Called if unable to calculate notification or network errors.
 * @param error handled error.
 *
 * @discussion Example:
 * @code
 * - (void)onNotificationFailed:(NSError *)error {
 *    NSLog(@"Notification failed");
 *    [self.example demonstrateErrorHandling:error];
 * }
 * @endcode
 */
- (void)onNotificationFailed:(nullable NSError *)error;

@end
