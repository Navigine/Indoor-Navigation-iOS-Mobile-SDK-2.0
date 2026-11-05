#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCMqttSessionListener;


/**
 * Class is used for managing MQTT session and publishing position data to MQTT broker.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMqttSession : NSObject

/**
 * Method is used to connect to MQTT broker and start publishing position data.
 * @param server MQTT broker server hostname or IP address.
 * @param port MQTT broker server port.
 * @param username MQTT broker username for authentication.
 * @param password MQTT broker password for authentication.
 *
 * @discussion Example:
 * @code
 * // Connect to MQTT broker
 * // Server: MQTT broker hostname or IP address
 * // Port: MQTT broker port (typically 1883 for non-SSL, 8883 for SSL)
 * // Username: MQTT broker username for authentication
 * // Password: MQTT broker password for authentication
 * [self.mqttSession connect:@"mqtt.example.com" port:1883 username:@"username" password:@"password"];
 * @endcode
 */
- (void)connect:(nonnull NSString *)server
           port:(int32_t)port
       username:(nonnull NSString *)username
       password:(nonnull NSString *)password;

/**
 * Method is used to set MQTT sub-topic for publishing position data.
 * The final topic will be "navigine/mobile/positions/" + subTopic + "/" + deviceId.
 * @param subTopic MQTT sub-topic for publishing position data. Must match pattern [0-9a-zA-Z_-]+ and cannot be empty.
 *
 * @discussion Example:
 * @code
 * // Set MQTT sub-topic for publishing position data
 * // Final topic will be "navigine/mobile/positions/" + subTopic + "/" + deviceId
 * [self.mqttSession setSubTopic:@"location1"];
 * @endcode
 */
- (void)setSubTopic:(nonnull NSString *)subTopic;

/**
 * Method is used to add ``NCMqttSessionListener`` class element
 * which will notify about MQTT session connection state changes.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCMqttSessionListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add MQTT session listener
 * [self.mqttSession addListener:self];
 * @endcode
 */
- (void)addListener:(nullable id<NCMqttSessionListener>)listener;

/**
 * Method is used for removing previously added ``NCMqttSessionListener`` class element.
 * @param listener Corresponding ``NCMqttSessionListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove first listener
 * [self.mqttSession removeListener:listener1];
 * @endcode
 */
- (void)removeListener:(nullable id<NCMqttSessionListener>)listener;

/**
 * Method is used to disconnect from MQTT broker and stop publishing position data.
 *
 * @discussion Example:
 * @code
 * // Disconnect from MQTT broker
 * [self.mqttSession disconnect];
 * @endcode
 */
- (void)disconnect;

/**
 * Method is used to publish a custom message to a specified MQTT topic.
 * The message will be sent asynchronously and the result will be notified through
 * ``NCMqttSessionListener`` callbacks (onMessagePublished for success, onError for failure).
 * @discussion Note: The MQTT session must be connected before calling this method. Use ``NCMqttSession/connect`` method first.
 * @param topic MQTT topic to publish the message to. Can be any valid MQTT topic string.
 * @param message Message content to publish. Can be any string (JSON, plain text, etc.).
 *
 * @discussion Example:
 * @code
 * // Publish a custom message to a specific MQTT topic
 * // The message will be sent asynchronously and the result will be notified through listener callbacks
 * NSString *customTopic = @"custom/device/status";
 * NSString *customMessage = [NSString stringWithFormat:@"{\"status\": \"online\", \"timestamp\": %lld}", (long long)([[NSDate date] timeIntervalSince1970] * 1000)];
 * [self.mqttSession publish:customTopic message:customMessage];
 * @endcode
 */
- (void)publish:(nonnull NSString *)topic
        message:(nonnull NSString *)message;

@end
