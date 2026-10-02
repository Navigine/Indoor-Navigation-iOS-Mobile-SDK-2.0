#import "NCExport.h"
#import "NCGuidanceCameraMode.h"
#import "NCRouteInstruction.h"
#import <Foundation/Foundation.h>


/**
 * Guidance camera and next-instruction updates.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCGuidanceListener <NSObject>

/**
 * Mode changed, including an automatic drop to `FREE` after a gesture.
 */
- (void)onCameraModeChanged:(NCGuidanceCameraMode)mode;

/**
 * Next instruction changed, or null when the route is gone / finished.
 */
- (void)onInstructionChanged:(nullable NCRouteInstruction *)instruction;

@end
