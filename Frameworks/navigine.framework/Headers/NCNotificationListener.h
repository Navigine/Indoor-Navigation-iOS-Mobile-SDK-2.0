#import <Foundation/Foundation.h>
@class NCNotification;


@protocol NCNotificationListener

- (void)onNotificationLoaded:(nullable NCNotification *)notification;

- (void)onNotificationFailed:(nullable NSError *)error;

@end
