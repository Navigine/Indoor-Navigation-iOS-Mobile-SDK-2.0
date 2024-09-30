#import "NCLifecycleListener.h"

@protocol NCLifecycleProvider

- (void)setListener:(__weak id<NCLifecycleListener>)listener;
- (void)reset;
- (bool)isActive;

@end
