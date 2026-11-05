#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


/**
 * Class provides a callback to be invoked when ``NCLocationManager``
 * class downloads the location from server or load it from the storage.
 * Referenced from ``NCLocationManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListener <NSObject>

/**
 * Called when new location version has been downloaded from server or load it from the storage
 * @param location ``NCLocation`` instance or nil if server url or `USER_HASH` was changed.
 *
 * @discussion Example:
 * @code
 * - (void)onLocationLoaded:(NCLocation *)location {
 *    NSLog(@"Location loaded successfully");
 *    self.currentLocation = location;
 *    if (location != nil) {
 *        [self demonstrateLocationUsage:location];
 *    }
 * }
 * @endcode
 */
- (void)onLocationLoaded:(nullable NCLocation *)location;

- (void)onLocationUploaded:(int32_t)locationId;

/**
 * Called if unable to download location version from CMS
 * @param locationId location unique identifier in SMC.
 * @param error handled error.
 *
 * @discussion Example:
 * @code
 * - (void)onLocationFailed:(int32_t)locationId error:(NSError *)error {
 *    NSLog(@"Failed to load location %d: %@", locationId, error.localizedDescription);
 * }
 * @endcode
 */
- (void)onLocationFailed:(int32_t)locationId
                   error:(nullable NSError *)error;

@end
