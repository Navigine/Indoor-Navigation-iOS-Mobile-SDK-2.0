#import "NCExport.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCNotification : NSObject

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, nonnull, readonly) NSString * title;

@property (nonatomic, nonnull, readonly) NSString * content;

@property (nonatomic, nullable, readonly) NSString * imageId;

@end