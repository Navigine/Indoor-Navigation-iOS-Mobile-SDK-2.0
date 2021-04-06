#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>


@protocol NCLocationListListener

- (void)onLocationListLoaded:(nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos;

- (void)onLocationListFailed:(nullable NSError *)error;

@end
