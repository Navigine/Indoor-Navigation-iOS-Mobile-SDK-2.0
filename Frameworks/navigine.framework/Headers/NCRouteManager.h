#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCRoutePath;
@protocol NCRouteListener;


@interface NCRouteManager : NSObject

- (nullable NCRoutePath *)makeRoute:(nonnull NCLocationPoint *)from
                                 to:(nonnull NCLocationPoint *)to;

- (void)setTarget:(nonnull NCLocationPoint *)target;

- (void)addTarget:(nonnull NCLocationPoint *)target;

- (void)cancelTarget;

- (void)clearTargets;

- (void)setGraphTag:(nonnull NSString *)tag;

- (nonnull NSString *)getGraphTag;

- (nonnull NSArray<NSString *> *)getGraphTags;

- (nonnull NSString *)getGraphDescription;

- (void)addRouteListener:(nullable id<NCRouteListener>)listener;

- (void)removeRouteListener:(nullable id<NCRouteListener>)listener;

@end
