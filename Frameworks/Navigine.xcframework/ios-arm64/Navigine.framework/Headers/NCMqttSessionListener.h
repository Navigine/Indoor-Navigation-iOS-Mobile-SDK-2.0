#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Class provides callbacks to be invoked when MQTT session connection state changes.
 * Referenced from ``NCMqttSession``.
 * @discussion Note: The callbacks are invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCMqttSessionListener <NSObject>

/**
 * Called when MQTT session has been successfully connected to the server.
 *
 * @discussion Example:
 * @code
 * - (void)onConnected {
 *    NSLog(@"MQTT session connected successfully");
 * }
 * @endcode
 */
- (void)onConnected;

/**
 * Called if MQTT session connection failed or was lost.
 * @param error handled error.
 *
 * @discussion Example:
 * @code
 * - (void)onError:(NSError *)error {
 *    NSLog(@"MQTT session error: %@", error.localizedDescription);
 * }
 * @endcode
 */
- (void)onError:(nullable NSError *)error;

/**
 * Called when a message has been successfully published to MQTT broker.
 * This callback is invoked after a message (either position data or custom message)
 * has been successfully sent to the MQTT broker.
 *
 * @discussion Example:
 * @code
 * - (void)onMessagePublished {
 *    NSLog(@"Message published successfully");
 * }
 * @endcode
 */
- (void)onMessagePublished;

@end
