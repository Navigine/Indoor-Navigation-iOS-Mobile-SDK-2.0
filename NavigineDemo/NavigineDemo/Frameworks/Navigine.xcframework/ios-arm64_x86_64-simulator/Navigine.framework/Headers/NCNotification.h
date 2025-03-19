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
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief notification's title.
 */
@property (nonatomic, nonnull, readonly) NSString * title;

/**
 * @brief notification's content.
 */
@property (nonatomic, nonnull, readonly) NSString * content;

/**
 * @brief notification's image url if specified.
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
