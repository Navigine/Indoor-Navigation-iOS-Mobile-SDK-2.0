#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListener;


/**
 * Class is used for downloading and working with ``NCLocation``.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationManager : NSObject

/**
 * Method is used to add ``NCLocationListener`` element
 * which will notify about newly downloaded and set location.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCLocationListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add location listener
 * [self.locationManager addLocationListener:self];
 * @endcode
 */
- (void)addLocationListener:(nullable id<NCLocationListener>)listener;

/**
 * Method is used for removing previously added ``NCLocationListener`` class element.
 * @param listener Corresponding ``NCLocationListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove location listener
 * [self.locationManager removeLocationListener:self];
 * @endcode
 */
- (void)removeLocationListener:(nullable id<NCLocationListener>)listener;

/**
 * Method is used for setting current location, which will be downloaded from server or from storage, if it was downloaded before.
 * Result will be handled by ``NCLocationListener``
 * @param locationId location id from CMS
 *
 * @discussion Example:
 * @code
 * // Set location ID to load
 * [self.locationManager setLocationId:12345];
 * @endcode
 */
- (void)setLocationId:(int32_t)locationId;

/**
 * Method returns current location unique identifier
 * @return current location unique identifier
 *
 * @discussion Example:
 * @code
 * // Get current location ID
 * int32_t currentLocationId = [self.locationManager getLocationId];
 * NSLog(@"Current location ID: %d", currentLocationId);
 * @endcode
 */
- (int32_t)getLocationId;

- (void)commitChanges;

- (void)revertChanges;

/**
 * Method is used to change interval in seconds check for new version from server
 * Default: 300s
 * @param interval update interval in seconds
 *
 * @discussion Example:
 * @code
 * // Set location update interval (in seconds)
 * [self.locationManager setLocationUpdateInterval:600]; // 10 minutes
 * @endcode
 */
- (void)setLocationUpdateInterval:(int32_t)interval;

@end
