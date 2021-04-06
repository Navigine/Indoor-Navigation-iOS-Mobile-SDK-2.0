#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


@interface NCNotificationManager : NSObject

- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
