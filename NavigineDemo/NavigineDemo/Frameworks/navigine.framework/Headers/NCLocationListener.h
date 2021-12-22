#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


NAVIGINE_EXPORT
@protocol NCLocationListener <NSObject>

- (void)onLocationLoaded:(nullable NCLocation *)location;

- (void)onDownloadProgress:(int32_t)received
                     total:(int32_t)total;

- (void)onLocationFailed:(nullable NSError *)error;

@end
