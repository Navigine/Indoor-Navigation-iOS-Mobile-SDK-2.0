#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCAsyncRouteListener;


/**
 * Class is used for managing async route listeners
 * Referenced from ``NCAsyncRouteManager``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteSession : NSObject

/**
 * Method is used to add ``NCAsyncRouteListener`` class element
 * which will notify async route events.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCAsyncRouteListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add route listener to session
 * [session addRouteListener:self];
 * @endcode
 */
- (void)addRouteListener:(nullable id<NCAsyncRouteListener>)listener;

/**
 * Method is used for removing previously added ``NCAsyncRouteListener`` class element.
 * @param listener Corresponding ``NCAsyncRouteListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove route listener
 * [self.currentSession removeRouteListener:self];
 * @endcode
 */
- (void)removeRouteListener:(nullable id<NCAsyncRouteListener>)listener;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
