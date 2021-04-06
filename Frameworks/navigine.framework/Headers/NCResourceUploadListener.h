#import <Foundation/Foundation.h>


@protocol NCResourceUploadListener

- (void)onUploaded;

- (void)onFailed:(nullable NSError *)error;

@end
