#import <Foundation/Foundation.h>

/**
 * Camera behavior while a route is shown.
 * `FREE` leaves the camera alone (also entered when the user pans or pinches).
 * `FOLLOWING` looks along the route at the current progress.
 * `OVERVIEW` fits the whole route into `LocationWindow.focusRect` (or the full
 * view when focus rect is null).
 * Modes: Free / Following / Overview. A user gesture drops tracking.
 */
typedef NS_ENUM(NSInteger, NCGuidanceCameraMode)
{
    NCGuidanceCameraModeFREE,
    NCGuidanceCameraModeFOLLOWING,
    NCGuidanceCameraModeOVERVIEW,
};
