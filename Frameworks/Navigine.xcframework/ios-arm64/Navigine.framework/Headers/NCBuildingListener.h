#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCBuilding;


/**
 * Listener for outdoor scenario when camera focuses on a building or leaves it.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCBuildingListener <NSObject>

/**
 * Called when camera enters a building's bounding box.
 * @param activeBuilding The building that is now focused.
 *
 * @discussion Example:
 * @code
 * - (void)onActiveBuildingFocused:(id<NCBuilding>)activeBuilding {
 *    // [objc_Building_getSublocations]
 *    NSArray<id<NCSublocation>> *floors = [activeBuilding getSublocations];
 *    NSLog(@"Focused building, floor count: %lu", (unsigned long)floors.count);
 *    // [objc_Building_getSublocations]
 *    // [objc_Building_getActiveSublocationId]
 *    int32_t activeFloorId = [activeBuilding getActiveSublocationId];
 *    NSLog(@"Active sublocation id: %d", activeFloorId);
 *    // [objc_Building_getActiveSublocationId]
 *    // [objc_Building_setActiveSublocationId]
 *    [activeBuilding setActiveSublocationId:activeFloorId];
 *    // [objc_Building_setActiveSublocationId]
 * }
 * @endcode
 */
- (void)onActiveBuildingFocused:(nullable NCBuilding *)activeBuilding;

/**
 * Called when camera leaves all buildings (no building bbox contains the camera).
 *
 * @discussion Example:
 * @code
 * - (void)onActiveBuildingLeft {
 *    NSLog(@"Camera left all building areas");
 * }
 * @endcode
 */
- (void)onActiveBuildingLeft;

/**
 * Called when the active sublocation (floor) of the focused building changes.
 * @param activeSublocationId New active sublocation id.
 *
 * @discussion Example:
 * @code
 * - (void)onActiveSublocationChanged:(int32_t)activeSublocationId {
 *    NSLog(@"Active floor changed to sublocation id: %d", activeSublocationId);
 * }
 * @endcode
 */
- (void)onActiveSublocationChanged:(int32_t)activeSublocationId;

@end
