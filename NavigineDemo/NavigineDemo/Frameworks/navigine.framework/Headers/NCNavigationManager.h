#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCPositionListener;


NAVIGINE_EXPORT
@interface NCNavigationManager : NSObject

- (void)addPositionListener:(nullable id<NCPositionListener>)listener;

- (void)removePositionListener:(nullable id<NCPositionListener>)listener;

- (void)startLogRecording;

- (void)stopLogRecording;

@end
