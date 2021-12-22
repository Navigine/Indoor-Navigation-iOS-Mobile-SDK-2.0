#import "NCExport.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@protocol NCLocationEditListener <NSObject>

- (void)onLocationUploaded;

- (void)onUploadProgress:(int32_t)received
                   total:(int32_t)total;

- (void)onLocationEditError:(nullable NSError *)error;

@end
