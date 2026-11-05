#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCRouteView;


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteViewListener <NSObject>

- (void)onRouteViewsChanged;

- (void)onSelectedRouteChanged:(nullable NCRouteView *)route;

- (void)onRouteViewTap:(nullable NCRouteView *)route;

@end
