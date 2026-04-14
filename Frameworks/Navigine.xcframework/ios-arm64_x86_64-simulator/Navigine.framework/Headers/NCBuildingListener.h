#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCBuilding;


/**
 * @file NCBuildingListener.h
 * @brief @copybrief NCBuildingListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Listener for outdoor scenario when camera focuses on a building or leaves it.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCBuildingListener <NSObject>

/**
 * @brief Called when camera enters a building's bounding box.
 * @param activeBuilding The building that is now focused.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_BuildingListener_onActiveBuildingFocused
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_BuildingListener_onActiveBuildingFocused
 *
 *
 */
- (void)onActiveBuildingFocused:(nullable NCBuilding *)activeBuilding;

/**
 * @brief Called when camera leaves all buildings (no building bbox contains the camera).
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_BuildingListener_onActiveBuildingLeft
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_BuildingListener_onActiveBuildingLeft
 *
 *
 */
- (void)onActiveBuildingLeft;

/**
 * @brief Called when the active sublocation (floor) of the focused building changes.
 * @param activeSublocationId New active sublocation id.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_BuildingListener_onActiveSublocationChanged
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_BuildingListener_onActiveSublocationChanged
 *
 *
 */
- (void)onActiveSublocationChanged:(int32_t)activeSublocationId;

@end
