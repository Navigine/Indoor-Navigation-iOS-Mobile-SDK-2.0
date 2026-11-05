#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Callback specified after the camera movement is stopped
 * Referenced from: ``NCLocationWindow``.
 */

/**
 * Called when the move if finished.
 * @param completed determine whether the movement is finished or cancelled
 *
 * @discussion Example:
 * @code
 * - (void)onMoveFinishedWithCompleted:(BOOL)completed {
 *    NSLog(@"Camera move animation %@", completed ? @"completed" : @"cancelled");
 * }
 * @endcode
 */
typedef void (^NCCameraCallback)(BOOL completed);

