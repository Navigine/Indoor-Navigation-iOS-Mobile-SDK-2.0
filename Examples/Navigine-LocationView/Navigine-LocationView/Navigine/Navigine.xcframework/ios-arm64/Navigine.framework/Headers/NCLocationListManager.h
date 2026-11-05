#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListListener;


/**
 * Class is used for downloading locations list from the server and providing it to the user.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationListManager : NSObject

/**
 * Method is used to add ``NCLocationListListener`` element
 * which will notify about newly downloaded list of available locations.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCLocationListListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add location list listener
 * [self.locationListManager addLocationListListener:self.locationListListener];
 * NSLog(@"Added location list listener");
 * @endcode
 */
- (void)addLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 * Method is used for removing previously added ``NCLocationListListener`` class element.
 * @param listener Corresponding ``NCLocationListListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove location list listener
 * [self.locationListManager removeLocationListListener:self.locationListListener];
 * NSLog(@"Removed location list listener");
 * @endcode
 */
- (void)removeLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 * Method is used to force reload location list.
 *
 * @discussion Example:
 * @code
 * // Force reload location list
 * [self.locationListManager updateLocationList];
 * NSLog(@"Requested location list update");
 * @endcode
 */
- (void)updateLocationList;

/**
 * Method is used to get current location list ``NCLocationInfo``.
 * @return dictionary {location_id -> location_info}
 *
 * @discussion Example:
 * @code
 * // Get current location list
 * NSDictionary<NSNumber *, NCLocationInfo *> *currentLocationList = [self.locationListManager getLocationList];
 * NSLog(@"Current location list contains %lu locations", (unsigned long)currentLocationList.count);
 * [self demonstrateLocationList:currentLocationList];
 * @endcode
 */
- (nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)getLocationList;

@end
