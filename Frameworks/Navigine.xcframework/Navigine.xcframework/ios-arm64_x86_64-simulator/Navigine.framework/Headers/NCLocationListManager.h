#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListListener;


/**
 * @file NCLocationListManager.h
 * @brief @copybrief NCLocationListManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for downloading locations list from the server and providing it to the user.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationListManager : NSObject

/**
 *
 * @brief Method is used to add @see LocationListListener "LocationListListener" element
 * which will notify about newly downloaded list of available locations.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see LocationListListener "LocationListListener" class.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationListManager_addLocationListListener
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationListManager_addLocationListListener
 *
 *
 */
- (void)addLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see LocationListListener "LocationListListener" class element.
 * @param listener Сorresponding @see LocationListListener "LocationListListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationListManager_removeLocationListListener
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationListManager_removeLocationListListener
 *
 *
 */
- (void)removeLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 *
 * @brief Method is used to force reload location list.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationListManager_updateLocationList
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationListManager_updateLocationList
 *
 *
 */
- (void)updateLocationList;

/**
 *
 * @brief Method is used to get current location list @see LocationInfo "LocationInfo".
 * @return dictionary {location_id -> location_info}
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationListManager_getLocationList
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationListManager_getLocationList
 *
 *
 */
- (nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)getLocationList;

@end
