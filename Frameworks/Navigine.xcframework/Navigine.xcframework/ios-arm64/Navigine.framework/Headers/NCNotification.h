#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCNotification.h
 * @brief @copybrief NCNotification
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Class is used for working with the notifications and storing its data.
 *
 * Referenced from: @see NotificationListener "NotificationListener".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotification : NSObject

/**
 * @brief notification's unique identifier.
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_Notification_getId
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_Notification_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief notification's title.
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_Notification_getTitle
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_Notification_getTitle
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * title;

/**
 * @brief notification's content.
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_Notification_getContent
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_Notification_getContent
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * content;

/**
 * @brief notification's image url if specified.
 *
 *
 * Swift code snippet:
 * @snippet NotificationManagerExample.swift swift_Notification_getImageUrl
 *
 * Objective C code snippet:
 * @snippet NotificationManagerExample.m objc_Notification_getImageUrl
 *
 *
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
