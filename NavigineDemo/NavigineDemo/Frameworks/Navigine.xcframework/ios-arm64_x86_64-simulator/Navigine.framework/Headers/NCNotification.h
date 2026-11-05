#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for working with the notifications and storing its data.
 * Referenced from: ``NCNotificationListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotification : NSObject

/**
 * notification's unique identifier.
 *
 * @discussion Example:
 * @code
 * // Get notification ID
 * int32_t id = notification.id;
 * NSLog(@"Notification ID: %d", id);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * notification's title.
 *
 * @discussion Example:
 * @code
 * // Get notification title
 * NSString *title = notification.title;
 * NSLog(@"Notification title: %@", title);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * title;

/**
 * notification's content.
 *
 * @discussion Example:
 * @code
 * // Get notification content
 * NSString *content = notification.content;
 * NSLog(@"Notification content: %@", content);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * content;

/**
 * notification's image url if specified.
 *
 * @discussion Example:
 * @code
 * // Get notification image URL
 * NSString *imageUrl = notification.imageUrl;
 * if (imageUrl != nil && imageUrl.length > 0) {
 *    NSLog(@"Notification image URL: %@", imageUrl);
 * } else {
 *    NSLog(@"Notification has no image URL");
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
