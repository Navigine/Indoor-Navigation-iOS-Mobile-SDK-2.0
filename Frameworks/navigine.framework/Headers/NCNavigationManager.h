#import <Foundation/Foundation.h>
@protocol NCPositionListener;


@interface NCNavigationManager : NSObject

- (void)addPositionListener:(nullable id<NCPositionListener>)listener;

- (void)removePositionListener:(nullable id<NCPositionListener>)listener;

- (void)startLogRecording;

- (void)stopLogRecording;

@end
