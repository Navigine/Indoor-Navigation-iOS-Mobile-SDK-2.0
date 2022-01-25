#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCResourceListener;
@protocol NCResourceUploadListener;


NAVIGINE_EXPORT
@interface NCResourceManager : NSObject

- (void)loadImage:(nonnull NSString *)imageId
         listener:(nullable id<NCResourceListener>)listener;

- (nonnull NSString *)publishUserEvent:(nonnull NSString *)content;

- (void)uploadUserFile:(nonnull NSString *)filePath
              listener:(nullable id<NCResourceUploadListener>)listener;

/** working with logs */
- (nonnull NSArray<NSString *> *)getLogsList;

- (void)removeLogFile:(nonnull NSString *)fileName;

- (void)uploadLogFile:(nonnull NSString *)fileName
             listener:(nullable id<NCResourceUploadListener>)listener;

@end