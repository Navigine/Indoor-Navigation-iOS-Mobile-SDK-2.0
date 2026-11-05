#import "NCCameraUpdateReason.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Class is used to listen for camera updates
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCCameraListener <NSObject>

/**
 * Triggered when the camera position changed.
 * If a movement is cancelled then reason represents initiator of cancellation.
 * @param reason reason of camera update.
 * @param finished true if the camera finished moving, false otherwise.
 *
 * @discussion Example:
 * @code
 * - (void)onCameraPositionChangedWithReason:(NCCameraUpdateReason)reason finished:(BOOL)finished {
 *    NSString *reasonString = @"";
 *    switch (reason) {
 *        case NCCameraUpdateReasonUser:
 *            reasonString = @"User";
 *            break;
 *        case NCCameraUpdateReasonAnimation:
 *            reasonString = @"Animation";
 *            break;
 *        case NCCameraUpdateReasonProgrammatic:
 *            reasonString = @"Programmatic";
 *            break;
 *    }
 *    NSLog(@"Camera position changed - Reason: %@, Finished: %@", reasonString, finished ? @"Yes" : @"No");
 * }
 * @endcode
 */
- (void)onCameraPositionChanged:(NCCameraUpdateReason)reason
                       finished:(BOOL)finished;

@end
