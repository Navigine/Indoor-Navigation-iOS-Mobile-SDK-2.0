#import "NCExport.h"
#import "NCPosition.h"
#import <Foundation/Foundation.h>


/**
 * Class provides a callback to be invoked when ``NCNavigationManager``
 * updates the position of the device.
 * Referenced from ``NCNavigationManager`` ``NCRouteManager``.
 * @discussion Note: The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPositionListener <NSObject>

/**
 * Called when new position has been calculated
 * @param position current user ``NCPosition``.
 *
 * @discussion Example:
 * @code
 * - (void)onPositionUpdated:(NCPosition *)position {
 *    NSLog(@"Position updated successfully");
 *    [self demonstratePositionUsage:position];
 * }
 * @endcode
 */
- (void)onPositionUpdated:(nonnull NCPosition *)position;

/**
 * Called if unable to calculate user's position
 * @param error handled error.
 *
 * @discussion Example:
 * @code
 * - (void)onPositionError:(NSError *)error {
 *    NSLog(@"Position error: %@", error.localizedDescription);
 * }
 * @endcode
 */
- (void)onPositionError:(nullable NSError *)error;

@end
