#import "NCExport.h"
#import "NCRouteLayerStatus.h"
#import "NCRouteProgress.h"
#import <Foundation/Foundation.h>
@class NCRouteView;


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteLayerListener <NSObject>

- (void)onRouteChanged:(NCRouteLayerStatus)status
                 route:(nullable NCRouteView *)route;

- (void)onRouteAdvanced:(nonnull NCRouteProgress *)progress;

- (void)onRouteTargetReached;

@end
