// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from notification_manager.djinni

#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCNotificationListener;


DEFAULT_EXPORT_ATTRIBUTE
@interface NCNotificationManager : NSObject

- (void)addNotificationListener:(nullable id<NCNotificationListener>)listener;

- (void)removeNotificationListener:(nullable id<NCNotificationListener>)listener;

@end
