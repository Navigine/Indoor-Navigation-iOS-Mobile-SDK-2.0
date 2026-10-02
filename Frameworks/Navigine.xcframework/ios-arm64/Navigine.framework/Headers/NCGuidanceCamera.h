#import "NCExport.h"
#import "NCGuidanceCameraMode.h"
#import "NCRouteInstruction.h"
#import <Foundation/Foundation.h>
@protocol NCGuidanceListener;


/**
 * Drives the map camera from a ``NCRouteLayer`` and exposes
 * the next instruction. Does not draw the route.
 * Overview uses the window focus rect, so set `LocationWindow.focusRect` for
 * chrome (floor selector, banner) before switching to `OVERVIEW`.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGuidanceCamera : NSObject

/**
 * Sets Free / Following / Overview.
 *
 * @discussion Example:
 * @code
 * [self.guidanceCamera setMode:NCGuidanceCameraModeFOLLOWING];
 * @endcode
 */
- (void)setMode:(NCGuidanceCameraMode)mode;

/**
 * Current mode.
 *
 * @discussion Example:
 * @code
 * NSLog(@"Guidance mode: %ld", (long)[self.guidanceCamera mode]);
 * @endcode
 */
- (NCGuidanceCameraMode)mode;

/**
 * Forces a top-down camera (tilt 0) in Following and Overview.
 * When false, Following uses a fixed forward tilt.
 *
 * @discussion Example:
 * @code
 * [self.guidanceCamera set2DMode:NO];
 * @endcode
 */
- (void)set2DMode:(BOOL)enabled;

/**
 * Returns true when top-down guidance is enabled.
 */
- (BOOL)is2DMode;

/**
 * When false, the camera is not moved. Instructions still update.
 */
- (void)setActive:(BOOL)active;

/**
 * Returns true when this controller may move the camera.
 */
- (BOOL)isActive;

/**
 * Latest next instruction, or null.
 *
 * @discussion Example:
 * @code
 * NCRouteInstruction *next = [self.guidanceCamera instruction];
 * if (next) {
 *    NSLog(@"Next instruction: %@ %.0f m", next.title, next.distance);
 * }
 * @endcode
 */
- (nullable NCRouteInstruction *)instruction;

/**
 * Adds a listener for mode and instruction changes.
 * Swift and Objective-C apps implement `NCGuidanceListener` and pass `self`
 * to `addListener:`, the same way `NCRouteLayerListener` is attached.
 */
- (void)addListener:(nullable id<NCGuidanceListener>)listener;

/**
 * Removes a previously added listener.
 */
- (void)removeListener:(nullable id<NCGuidanceListener>)listener;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
