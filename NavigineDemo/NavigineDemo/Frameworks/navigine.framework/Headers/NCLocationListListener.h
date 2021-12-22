#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@protocol NCLocationListListener <NSObject>

- (void)onLocationListLoaded:(nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos;

- (void)onLocationListFailed:(nullable NSError *)error;

@end
