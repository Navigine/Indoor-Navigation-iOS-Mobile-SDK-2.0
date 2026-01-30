#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCMqttSessionListener;


/**
 * @file NCMqttSession.h
 * @brief @copybrief NCMqttSession
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 *
 * @brief Class is used for managing MQTT session and publishing position data to MQTT broker.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMqttSession : NSObject

/**
 *
 * @brief Method is used to connect to MQTT broker and start publishing position data.
 * @param server MQTT broker server hostname or IP address.
 * @param port MQTT broker server port.
 * @param username MQTT broker username for authentication.
 * @param password MQTT broker password for authentication.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_connect
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_connect
 *
 *
 */
- (void)connect:(nonnull NSString *)server
           port:(int32_t)port
       username:(nonnull NSString *)username
       password:(nonnull NSString *)password;

/**
 *
 * @brief Method is used to set MQTT sub-topic for publishing position data.
 * The final topic will be "navigine/mobile/positions/" + subTopic + "/" + deviceId.
 * @param subTopic MQTT sub-topic for publishing position data. Must match pattern [0-9a-zA-Z_-]+ and cannot be empty.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_setSubTopic
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_setSubTopic
 *
 *
 */
- (void)setSubTopic:(nonnull NSString *)subTopic;

/**
 *
 * @brief Method is used to add @see MqttSessionListener "MqttSessionListener" class element
 * which will notify about MQTT session connection state changes.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see MqttSessionListener "MqttSessionListener" class.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_addListener
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_addListener
 *
 *
 */
- (void)addListener:(nullable id<NCMqttSessionListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see MqttSessionListener "MqttSessionListener" class element.
 * @param listener Сorresponding @see MqttSessionListener "MqttSessionListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_removeListener
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_removeListener
 *
 *
 */
- (void)removeListener:(nullable id<NCMqttSessionListener>)listener;

/**
 *
 * @brief Method is used to disconnect from MQTT broker and stop publishing position data.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_disconnect
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_disconnect
 *
 *
 */
- (void)disconnect;

/**
 *
 * @brief Method is used to publish a custom message to a specified MQTT topic.
 * The message will be sent asynchronously and the result will be notified through
 * @see MqttSessionListener "MqttSessionListener" callbacks (onMessagePublished for success, onError for failure).
 * @note The MQTT session must be connected before calling this method. Use @see MqttSession::connect "connect" method first.
 * @param topic MQTT topic to publish the message to. Can be any valid MQTT topic string.
 * @param message Message content to publish. Can be any string (JSON, plain text, etc.).
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSession_publish
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSession_publish
 *
 *
 */
- (void)publish:(nonnull NSString *)topic
        message:(nonnull NSString *)message;

@end
