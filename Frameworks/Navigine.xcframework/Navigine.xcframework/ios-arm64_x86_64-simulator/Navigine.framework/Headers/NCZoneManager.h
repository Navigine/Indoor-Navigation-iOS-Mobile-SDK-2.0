#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCZoneListener;


/**
 * @file NCZoneManager.h
 * @brief @copybrief NCZoneManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for notifying about entering or leaving @see Zone "Zone"s.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneManager : NSObject

/**
 *
 * @brief Method is used to add @see ZoneListener "ZoneListener" class element
 * which will notify entering or leaving @see Zone "Zone"s.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see ZoneListener "ZoneListener" class.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneManager_addZoneListener
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneManager_addZoneListener
 *
 *
 */
- (void)addZoneListener:(nullable id<NCZoneListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see ZoneListener "ZoneListener" class element.
 * @param listener Сorresponding @see ZoneListener "ZoneListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet ZoneManagerExample.swift swift_ZoneManager_removeZoneListener
 *
 * Objective C code snippet:
 * @snippet ZoneManagerExample.m objc_ZoneManager_removeZoneListener
 *
 *
 */
- (void)removeZoneListener:(nullable id<NCZoneListener>)listener;

@end
