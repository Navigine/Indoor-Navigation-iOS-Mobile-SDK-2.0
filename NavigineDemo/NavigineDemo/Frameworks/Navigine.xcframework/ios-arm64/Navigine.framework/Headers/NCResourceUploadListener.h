#import "NCExport.h"
#import <Foundation/Foundation.h>


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCResourceUploadListener <NSObject>

- (void)onUploaded:(nonnull NSString *)fileName;

- (void)onFailed:(nullable NSError *)error;

@end
