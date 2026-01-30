#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCMqttSessionListener.h
 * @brief @copybrief NCMqttSessionListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 *
 * @brief Class provides callbacks to be invoked when MQTT session connection state changes.
 *
 * Referenced from @see MqttSession "MqttSession".
 * @note The callbacks are invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCMqttSessionListener <NSObject>

/**
 *
 * @brief Called when MQTT session has been successfully connected to the server.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSessionListener_onConnected
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSessionListener_onConnected
 *
 *
 */
- (void)onConnected;

/**
 *
 * @brief Called if MQTT session connection failed or was lost.
 * @param error handled error.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSessionListener_onError
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSessionListener_onError
 *
 *
 */
- (void)onError:(nullable NSError *)error;

/**
 *
 * @brief Called when a message has been successfully published to MQTT broker.
 * This callback is invoked after a message (either position data or custom message)
 * has been successfully sent to the MQTT broker.
 *
 *
 * Swift code snippet:
 * @snippet MqttSessionExample.swift swift_MqttSessionListener_onMessagePublished
 *
 * Objective C code snippet:
 * @snippet MqttSessionExample.m objc_MqttSessionListener_onMessagePublished
 *
 *
 */
- (void)onMessagePublished;

@end
