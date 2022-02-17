#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>
@class NCMapObjectPickResult;


NAVIGINE_EXPORT
@protocol NCPickListener <NSObject>

- (void)onMapObjectPickComplete:(nullable NCMapObjectPickResult *)mapObjectPickResult
                 screenPosition:(nonnull NCPoint *)screenPosition;

- (void)onMapFeaturePickComplete:(nonnull NSDictionary<NSString *, NSString *> *)mapFeaturePickResult
                  screenPosition:(nonnull NCPoint *)screenPosition;

@end
