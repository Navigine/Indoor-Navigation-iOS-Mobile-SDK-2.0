#import "NCCameraUpdateReason.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCCameraListener.h
 * @brief @copybrief NCCameraListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to listen for camera updates
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCCameraListener <NSObject>

/**
 *
 * @brief Triggered when the camera position changed.
 * @param reason reason of camera update.
 * @param finished true if the camera finished moving, false otherwise.
 *      If a movement is cancelled then reason represents initiator of cancellation.
 *
 */
- (void)onCameraPositionChanged:(NCCameraUpdateReason)reason
                       finished:(BOOL)finished;

@end
