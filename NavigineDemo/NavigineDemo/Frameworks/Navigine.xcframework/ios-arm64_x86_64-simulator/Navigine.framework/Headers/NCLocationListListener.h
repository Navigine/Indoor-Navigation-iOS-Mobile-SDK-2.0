#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>


/**
 * @file NCLocationListListener.h
 * @brief @copybrief NCLocationListListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see LocationListManager "LocationListManager"
 * class downloads list of available locations from server.
 *
 * Referenced from @see LocationListManager "LocationListManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListListener <NSObject>

/**
 *
 * @brief Called when new list of available locations has been downloaded from server
 * @param locationInfos dictionary of @see LocationInfo "LocationInfo"s which represents location id to location general info.
 *
 */
- (void)onLocationListLoaded:(nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos;

/**
 *
 * @brief Called if unable to download list of available locations
 * @param error handled error.
 *
 */
- (void)onLocationListFailed:(nullable NSError *)error;

@end
