#import <Foundation/Foundation.h>

/**
 * How the user-location layer moves the camera.
 * Reduced to pedestrian follow: none, position, compass heading, course over
 * ground.
 * A map gesture returns the mode to NONE.
 * Referenced from ``NCUserLocationLayer``.
 */
typedef NS_ENUM(NSInteger, NCUserLocationFollowMode)
{
    /**
     * Camera stays where the user left it. The arrow still rotates to heading.
     */
    NCUserLocationFollowModeNONE,
    /**
     * Camera follows the position and keeps its current rotation.
     */
    NCUserLocationFollowModePOSITION,
    /**
     * Camera follows and rotates to the compass heading.
     */
    NCUserLocationFollowModeHEADING,
    /**
     * Camera follows and rotates to the direction of travel.
     * Falls back to compass heading until the user has moved.
     */
    NCUserLocationFollowModeCOURSE,
};
