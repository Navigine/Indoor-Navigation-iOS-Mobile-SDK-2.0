#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCClusterMapObject;
@class NCClusterMapObjectController;


/**
 * Listener for cluster lifecycle events on ``NCClusterMapObjectController``.
 * Cluster pick is delivered via ``NCPickListener`` (`pickMapObjectAt`).
 * `onClusterCreated` is called when a cluster appears (at least two icons grouped).
 * `onClusterDestroyed` is called when a cluster is removed (fewer than two icons remain or controller is cleared).
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCClusterMapObjectControllerListener <NSObject>

/**
 * A new cluster marker appeared.
 * @param controller Cluster controller that owns the cluster.
 * @param cluster Newly created cluster. Use `getCount()` for the initial badge value.
 *
 * @discussion Example:
 * @code
 * - (void)onClusterCreated:(NCClusterMapObjectController *)controller
 *                 cluster:(NCClusterMapObject *)cluster {
 *    // [objc_ClusterMapObject_addListener]
 *    [cluster addListener:_clusterChangeListener];
 *    NSLog(@"Added cluster change listener, initial count: %d", [cluster getCount]);
 *    // [objc_ClusterMapObject_addListener]
 *    _activeCluster = cluster;
 * }
 * @endcode
 */
- (void)onClusterCreated:(nullable NCClusterMapObjectController *)controller
                 cluster:(nullable NCClusterMapObject *)cluster;

/**
 * A cluster marker was removed.
 * @param controller Cluster controller that owned the cluster.
 * @param clusterId Identifier of the destroyed cluster (same as ``NCClusterMapObject`` `getId()`).
 *
 * @discussion Example:
 * @code
 * - (void)onClusterDestroyed:(NCClusterMapObjectController *)controller
 *                 clusterId:(int32_t)clusterId {
 *    if (_activeCluster != nil && [_activeCluster getId] == clusterId) {
 *        // [objc_ClusterMapObject_removeListener]
 *        [_activeCluster removeListener:_clusterChangeListener];
 *        NSLog(@"Removed cluster change listener");
 *        // [objc_ClusterMapObject_removeListener]
 *        _activeCluster = nil;
 *    }
 *    NSLog(@"Cluster destroyed, id: %d", clusterId);
 * }
 * @endcode
 */
- (void)onClusterDestroyed:(nullable NCClusterMapObjectController *)controller
                 clusterId:(int32_t)clusterId;

@end
