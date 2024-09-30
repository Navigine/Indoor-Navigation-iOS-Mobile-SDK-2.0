#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCAsyncRouteListener;


/** Class is used to manage route listeners */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteSession : NSObject

/**
 *
 * Method is used to add listener to handle async route events (@see AsyncRouteListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addRouteListener:(nullable id<NCAsyncRouteListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeRouteListener:(nullable id<NCAsyncRouteListener>)listener;

@end
