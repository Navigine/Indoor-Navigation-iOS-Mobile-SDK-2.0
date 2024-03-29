// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from async_route_manager.djinni

#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteOptions.h"
#import <Foundation/Foundation.h>
@class NCRouteSession;


DEFAULT_EXPORT_ATTRIBUTE
@interface NCAsyncRouteManager : NSObject

- (nullable NCRouteSession *)createRouteSession:(nonnull NCLocationPoint *)wayPoint
                                   routeOptions:(nonnull NCRouteOptions *)routeOptions;

- (void)cancelRouteSession:(nullable NCRouteSession *)session;

@end
