#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCIconMapObject;
@protocol NCClusterMapObjectListener;


/**
 * Runtime snapshot of a visible icon cluster on the location view.
 * Created and updated by ``NCClusterMapObjectController``.
 * Member ``NCIconMapObject`` instances are hidden while grouped; the cluster marker is shown instead.
 * @discussion Note: Position and membership are managed by the controller and cannot be changed through this interface.
 * Use ``NCClusterMapObjectListener`` (`onClusterChanged`) to refresh a custom cluster bitmap when the member count changes.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCClusterMapObject : NCMapObject

/**
 * Method is used to specify the decoded raster for the cluster marker.
 * @param bitmap Image provider: Android com.navigine.image.ImageProvider; iOS UIImage via binding; Flutter navigine_sdk ImageProvider.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * UIImage *clusterImage = [UIImage imageWithContentsOfFile:@"/path/to/cluster.png"];
 * BOOL bitmapSuccess = [cluster setBitmap:clusterImage];
 * NSLog(@"Set cluster bitmap (UIImage): %d", bitmapSuccess);
 * @endcode
 */
- (BOOL)setBitmap:(nullable UIImage *)bitmap;

/**
 * Adds a listener for cluster state updates ``NCClusterMapObjectListener``.
 * @param listener Listener instance.
 *
 * @discussion Example:
 * @code
 * [cluster addListener:_clusterChangeListener];
 * NSLog(@"Added cluster change listener, initial count: %d", [cluster getCount]);
 * @endcode
 */
- (void)addListener:(nullable id<NCClusterMapObjectListener>)listener;

/**
 * Removes a previously added listener.
 * @param listener Listener instance to remove.
 *
 * @discussion Example:
 * @code
 * [_activeCluster removeListener:_clusterChangeListener];
 * NSLog(@"Removed cluster change listener");
 * @endcode
 */
- (void)removeListener:(nullable id<NCClusterMapObjectListener>)listener;

/**
 * Cluster center in metrics coordinates.
 */
@property (nonatomic, nonnull, readonly) NCLocationPoint * position;

/**
 * Number of icon map objects in the cluster (at least 2 while the cluster is visible).
 */
@property (nonatomic, readonly) int32_t count;

/**
 * Icon map objects currently grouped into this cluster.
 */
@property (nonatomic, nonnull, readonly) NSArray<NCIconMapObject *> * iconMapObjects;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
