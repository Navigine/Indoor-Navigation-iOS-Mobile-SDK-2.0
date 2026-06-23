#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>


/**
 * Class provides a callback to be invoked when ``NCLocationListManager``
 * class downloads list of available locations from server.
 * Referenced from ``NCLocationListManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListListener <NSObject>

/**
 * Called when new list of available locations has been downloaded from server
 * @param locationInfos dictionary of ``NCLocationInfo``s which represents location id to location general info.
 *
 * @discussion Example:
 * @code
 * - (void)onLocationListLoaded:(NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos {
 *    NSLog(@"Location list loaded");
 *    [self.example demonstrateLocationList:locationInfos];
 * }
 * @endcode
 */
- (void)onLocationListLoaded:(nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos;

/**
 * Called if unable to download list of available locations
 * @param error handled error.
 *
 * @discussion Example:
 * @code
 * - (void)onLocationListFailed:(NSError *)error {
 *    NSLog(@"Location list failed");
 *    [self.example demonstrateErrorHandling:error];
 * }
 * @endcode
 */
- (void)onLocationListFailed:(nullable NSError *)error;

@end
