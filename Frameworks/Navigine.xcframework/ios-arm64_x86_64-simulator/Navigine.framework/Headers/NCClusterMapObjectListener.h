#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCClusterMapObject;


/**
 * Listener for updates of a single ``NCClusterMapObject``.
 * `onClusterChanged` is called when the cluster member count changes while it remains a cluster (at least two icons).
 * It is not called when the cluster is created or destroyed.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCClusterMapObjectListener <NSObject>

/**
 * Cluster marker needs an app-side update (bitmap, label, etc.).
 * @param cluster Cluster with at least two member icons. Use `getCount()` for the badge value.
 *
 * @discussion Example:
 * @code
 * - (void)onClusterChanged:(NCClusterMapObject *)cluster {
 *    int32_t memberCount = [cluster getCount];
 *    NSLog(@"Cluster changed, member count: %d", memberCount);
 * }
 * @endcode
 */
- (void)onClusterChanged:(nullable NCClusterMapObject *)cluster;

@end
