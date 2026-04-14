#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCSublocation;


/**
 * @file NCBuilding.h
 * @brief @copybrief NCBuilding
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Interface for a building with multiple floors (Sublocations).
 * Allows selecting the active floor directly via setActiveSublocationId.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBuilding : NSObject

/**
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_Building_getSublocations
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_Building_getSublocations
 *
 *
 */
- (nonnull NSArray<NCSublocation *> *)getSublocations;

/**
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_Building_getActiveSublocationId
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_Building_getActiveSublocationId
 *
 *
 */
- (int32_t)getActiveSublocationId;

/**
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowBuildingExample.swift swift_Building_setActiveSublocationId
 *
 *Objective C code snippet:
 *@snippet LocationWindowBuildingExample.m objc_Building_setActiveSublocationId
 *
 *
 */
- (void)setActiveSublocationId:(int32_t)activeSublocationId;

@end
