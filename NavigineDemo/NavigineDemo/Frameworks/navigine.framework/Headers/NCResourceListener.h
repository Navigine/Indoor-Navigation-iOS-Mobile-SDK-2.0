#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCImage;


NAVIGINE_EXPORT
@protocol NCResourceListener <NSObject>

- (void)onLoaded:(nonnull NSString *)imageId
           image:(nullable NCImage *)image;

- (void)onFailed:(nonnull NSString *)imageId
           error:(nullable NSError *)error;

@end
