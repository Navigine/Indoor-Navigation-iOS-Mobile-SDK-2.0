#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCNotification;


NAVIGINE_EXPORT
@protocol NCNotificationListener

- (void)onNotificationLoaded:(nullable NCNotification *)notification;

- (void)onNotificationFailed:(nullable NSError *)error;

@end
