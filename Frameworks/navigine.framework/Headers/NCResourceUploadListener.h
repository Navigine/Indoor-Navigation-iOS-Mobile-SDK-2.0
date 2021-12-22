#import "NCExport.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@protocol NCResourceUploadListener <NSObject>

- (void)onUploaded;

- (void)onFailed:(nullable NSError *)error;

@end
