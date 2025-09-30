#import "NCExport.h"
#import "NCLogInfo.h"
#import <Foundation/Foundation.h>
@protocol NCResourceListener;
@protocol NCResourceUploadListener;


/**
 * @file NCResourceManager.h
 * @brief @copybrief NCResourceManager
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCResourceManager : NSObject

- (void)loadImage:(nonnull NSString *)imageUrl
         listener:(nullable id<NCResourceListener>)listener;

/**
 * working with logs
 */
- (nonnull NSArray<NCLogInfo *> *)getLogsList;

- (void)removeLogFile:(nonnull NSString *)fileName;

- (void)uploadLogFile:(nonnull NSString *)fileName
             listener:(nullable id<NCResourceUploadListener>)listener;

@end
