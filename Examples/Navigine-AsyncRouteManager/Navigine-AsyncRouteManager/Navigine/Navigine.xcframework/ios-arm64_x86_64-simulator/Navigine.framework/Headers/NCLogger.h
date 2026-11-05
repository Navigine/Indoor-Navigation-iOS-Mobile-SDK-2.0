#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLogger;
@protocol NCLogListener;


DEFAULT_EXPORT_ATTRIBUTE
@interface NCLogger : NSObject

+ (nullable NCLogger *)getLogger;

- (void)subscribe:(nullable id<NCLogListener>)listener;

- (void)unsubscribe:(nullable id<NCLogListener>)listener;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
