#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCImage;


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCResourceListener <NSObject>

- (void)onLoaded:(nonnull NSString *)imageUrl
           image:(nullable NCImage *)image;

- (void)onFailed:(nonnull NSString *)imageUrl
           error:(nullable NSError *)error;

@end
