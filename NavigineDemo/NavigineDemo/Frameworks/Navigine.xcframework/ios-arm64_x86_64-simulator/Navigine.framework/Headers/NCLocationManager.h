#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListener;


/**
 * @file NCLocationManager.h
 * @brief @copybrief NCLocationManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for downloading and working with @see Location "Location".
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationManager : NSObject

/**
 *
 * @brief Method is used to add @see LocationListener "LocationListener" element
 * which will notify about newly downloaded and set location.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see LocationListener "LocationListener" class.
 *
 */
- (void)addLocationListener:(nullable id<NCLocationListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see LocationListener "LocationListener" class element.
 * @param listener Сorresponding @see LocationListener "LocationListener" class to remove.
 *
 */
- (void)removeLocationListener:(nullable id<NCLocationListener>)listener;

/**
 *
 * @brief Method is used for setting current location, which will be downloaded from server or from storage, if it was downloaded before.
 * Result will be handled by @see LocationListener "LocationListener"
 * @param locationId location id from CMS
 *
 */
- (void)setLocationId:(int32_t)locationId;

/**
 *
 * @brief Method returns current location unique identifier
 * @return current location unique identifier
 *
 */
- (int32_t)getLocationId;

/**
 * @cond
 */
- (void)commitChanges;

- (void)revertChanges;

/**
 * @endcond
 *
 * @brief Method is used to change interval in seconds check for new version from server
 * Default: 300s
 * @param interval update interval in seconds
 *
 */
- (void)setLocationUpdateInterval:(int32_t)interval;

@end
