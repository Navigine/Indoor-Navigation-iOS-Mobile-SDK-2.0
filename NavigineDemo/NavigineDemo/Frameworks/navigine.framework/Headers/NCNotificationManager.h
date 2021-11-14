#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


NAVIGINE_EXPORT
@interface NCNotificationManager : NSObject

- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
