#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


/**
 * @file NCLocationListener.h
 * @brief @copybrief NCLocationListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see LocationManager "LocationManager"
 * class downloads the location from server or load it from the storage.
 *
 * Referenced from @see LocationManager "LocationManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListener <NSObject>

/**
 *
 * @brief Called when new location version has been downloaded from server or load it from the storage
 * @param location @see Location "Location" instance.
 *
 */
- (void)onLocationLoaded:(nullable NCLocation *)location;

/**
 * @cond
 */
- (void)onLocationUploaded:(int32_t)locationId;

/**
 * @endcond
 *
 * @brief Called if unable to download location version from CMS
 * @param locationId location unique identifier in SMC.
 * @param error handled error.
 *
 */
- (void)onLocationFailed:(int32_t)locationId
                   error:(nullable NSError *)error;

@end
