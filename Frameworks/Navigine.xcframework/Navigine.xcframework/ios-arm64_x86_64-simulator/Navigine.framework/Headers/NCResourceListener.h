#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCImage;


/**
 * @file NCResourceListener.h
 * @brief @copybrief NCResourceListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCResourceListener <NSObject>

- (void)onLoaded:(nonnull NSString *)imageUrl
           image:(nullable NCImage *)image;

- (void)onFailed:(nonnull NSString *)imageUrl
           error:(nullable NSError *)error;

@end
