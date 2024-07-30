#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing notification in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotification : NSObject

/** Notification unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Notification title. */
@property (nonatomic, nonnull, readonly) NSString * title;

/** Notification content. */
@property (nonatomic, nonnull, readonly) NSString * content;

/** Notification image url if specified. */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
