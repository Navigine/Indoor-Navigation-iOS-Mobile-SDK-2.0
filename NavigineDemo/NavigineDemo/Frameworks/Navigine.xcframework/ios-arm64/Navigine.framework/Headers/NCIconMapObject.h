#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 *
 * Object represents icon object on location view.
 * IconMapObject keep orientation to screen surface.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCIconMapObject : NCMapObject

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
 * Method is used to specify bitmap image to the object.
 * @param bitmap - platfrom bitmap object.
 *
 */
- (BOOL)setBitmap:(nullable UIImage *)bitmap;

/**
 *
 * Method is used to specify size of object.
 * @param width - width of object in pixels.
 * @param height - width of object in pixels.
 *
 */
- (BOOL)setSize:(float)width
         height:(float)height;

@end
