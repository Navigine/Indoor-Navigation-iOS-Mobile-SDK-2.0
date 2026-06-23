#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCClusterMapObject;
@class NCIconMapObject;
@protocol NCClusterMapObjectControllerListener;


/**
 * Groups ``NCIconMapObject`` instances into clusters depending on zoom and proximity.
 * Referenced from ``NCLocationWindow``.
 * Register icons with `addIconMapObject`, then optionally customize cluster appearance in
 * ``NCClusterMapObjectControllerListener`` (`onClusterCreated`) and
 * ``NCClusterMapObjectListener`` (`onClusterChanged`).
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCClusterMapObjectController : NSObject

/**
 * Adds an icon map object to the cluster controller.
 * @param iconMapObject Icon to cluster ``NCIconMapObject``. Must be added to the same ``NCLocationWindow`` via `addIconMapObject`.
 * @return true if the icon was added, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL added1 = [controller addIconMapObject:clusterIcon1];
 * BOOL added2 = [controller addIconMapObject:clusterIcon2];
 * NSLog(@"Registered icons for clustering: %d, %d", added1, added2);
 * @endcode
 */
- (BOOL)addIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 * Removes an icon map object from the cluster controller.
 * @param iconMapObject Icon to remove.
 * @return true if the icon was removed, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL removed = [controller removeIconMapObject:clusterIcon1];
 * NSLog(@"Removed icon from cluster controller: %d", removed);
 * @endcode
 */
- (BOOL)removeIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 * Removes all icon map objects from the controller and destroys visible cluster markers.
 *
 * @discussion Example:
 * @code
 * [controller clear];
 * NSLog(@"Cleared cluster controller");
 * @endcode
 */
- (void)clear;

/**
 * Enables or disables clustering. Default: true.
 *
 * @discussion Example:
 * @code
 * [controller setEnabled:YES];
 * NSLog(@"Clustering enabled");
 * @endcode
 */
- (void)setEnabled:(BOOL)enabled;

/**
 * Returns whether clustering is enabled.
 *
 * @discussion Example:
 * @code
 * BOOL clusteringEnabled = [controller isEnabled];
 * NSLog(@"Clustering is enabled: %d", clusteringEnabled);
 * @endcode
 */
- (BOOL)isEnabled;

/**
 * Cluster radius in density-independent pixels. Default: 40.
 *
 * @discussion Example:
 * @code
 * [controller setRadius:40.0f];
 * NSLog(@"Set cluster radius to 40 px");
 * @endcode
 */
- (void)setRadius:(float)radius;

/**
 * Returns cluster radius in density-independent pixels.
 *
 * @discussion Example:
 * @code
 * float clusterRadius = [controller getRadius];
 * NSLog(@"Cluster radius: %f", clusterRadius);
 * @endcode
 */
- (float)getRadius;

/**
 * Specifies whether cluster markers can be picked. Default: true.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL interactiveSuccess = [controller setInteractive:YES];
 * NSLog(@"Set cluster markers interactive: %d", interactiveSuccess);
 * @endcode
 */
- (BOOL)setInteractive:(BOOL)interactive;

/**
 * Specifies the size of the default cluster icon in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL sizeSuccess = [controller setClusterSizeWithWidth:32.0f height:32.0f];
 * NSLog(@"Set default cluster icon size: %d", sizeSuccess);
 * @endcode
 */
- (BOOL)setClusterSize:(float)width
                height:(float)height;

/**
 * Adds a listener for cluster lifecycle events ``NCClusterMapObjectControllerListener``.
 * @param listener Listener instance.
 *
 * @discussion Example:
 * @code
 * [controller addListener:listener];
 * NSLog(@"Added cluster map object controller listener");
 * @endcode
 */
- (void)addListener:(nullable id<NCClusterMapObjectControllerListener>)listener;

/**
 * Removes a previously added listener.
 * @param listener Listener instance to remove.
 *
 * @discussion Example:
 * @code
 * [controller removeListener:listener];
 * NSLog(@"Removed cluster map object controller listener");
 * @endcode
 */
- (void)removeListener:(nullable id<NCClusterMapObjectControllerListener>)listener;

/**
 * Returns a snapshot of currently visible clusters.
 *
 * @discussion Example:
 * @code
 * NSArray<NCClusterMapObject *> *clusters = [controller getClusters];
 * NSLog(@"Visible clusters: %lu", (unsigned long)clusters.count);
 * @endcode
 */
- (nonnull NSArray<NCClusterMapObject *> *)getClusters;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
