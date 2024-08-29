#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object represents circle on location view.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCircleMapObject : NCMapObject

/**
 *
 * Method is used to specify center of object.
 * @param point - metrics coordinate of center (@see LocationPoint).
 *
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 *
 * Method is used to move center of object with specified animation (@see LocationPoint).
 * @param point - metrics coordinate of center (@see LocationPoint).
 * @param duration - animation duration in seconds.
 * @param type - animation type (@see AnimationType).
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 *
 * Method is used to specify color of object.
 * @param red - red RGBA component.
 * @param green - green RGBA component.
 * @param blue - blue RGBA component.
 * @param alpha - Opacity multiplicator. Values below 0 will be set to 0. Default: 1.
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * Method is used to specify size of object.
 * @param radius - metrics radius of circle.
 *
 */
- (BOOL)setRadius:(float)radius;

@end
