#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCIconMapObject.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object represents icon object on location view.
 * FlatIconMapObject keep orientation to location view surface.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCFlatIconMapObject : NCIconMapObject

/**
 *
 * Method is used to specify rotation of object.
 * @param angle - angle of rotation in degrees.
 *
 */
- (BOOL)setAngle:(double)angle;

/**
 *
 * Method is used to rotate object with specified animation.
 * @param angle - angle of rotation in degrees.
 * @param duration - animation duration in seconds.
 * @param type - animation type (@see AnimationType).
 *
 */
- (BOOL)setAngleAnimated:(double)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

@end
