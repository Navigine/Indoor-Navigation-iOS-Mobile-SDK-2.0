#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLogger;
@protocol NCLogListener;


/**
 * @file NCLogger.h
 * @brief @copybrief NCLogger
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLogger : NSObject

+ (nullable NCLogger *)getLogger;

- (void)subscribe:(nullable id<NCLogListener>)listener;

- (void)unsubscribe:(nullable id<NCLogListener>)listener;

@end
