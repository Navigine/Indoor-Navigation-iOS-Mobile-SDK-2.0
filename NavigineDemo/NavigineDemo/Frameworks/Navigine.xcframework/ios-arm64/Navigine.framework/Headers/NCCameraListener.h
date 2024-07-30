#import "NCCameraUpdateReason.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>


/** Class is used to listen for camera updates (@see LocationView) */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCCameraListener <NSObject>

/**
 *
 * Triggered when the camera position changed.
 * @param reason - reason of camera update.
 * @param finished - true if the camera finished moving, false otherwise.
 *      If a movement is cancelled then reason represents initiator of cancellation.
 *
 */
- (void)onCameraPositionChanged:(NCCameraUpdateReason)reason
                       finished:(BOOL)finished;

@end
