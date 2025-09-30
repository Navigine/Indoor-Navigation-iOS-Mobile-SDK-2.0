#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCResourceUploadListener.h
 * @brief @copybrief NCResourceUploadListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCResourceUploadListener <NSObject>

- (void)onUploaded:(nonnull NSString *)fileName;

- (void)onFailed:(nullable NSError *)error;

@end
