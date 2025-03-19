#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * @file NCIconMapObject.h
 * @brief @copybrief NCIconMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief represents icon object on location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 * @note IconMapObject keep orientation to screen surface.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCIconMapObject : NCMapObject

/**
 *
 * @brief Method is used to specify center of object.
 * @param point metrics coordinate of center @see LocationPoint "LocationPoint".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 *
 * @brief Method is used to move center of object with specified animation @see LocationPoint "LocationPoint".
 * @param point metrics coordinate of center @see LocationPoint "LocationPoint".
 * @param duration animation duration in seconds.
 * @param type animation type @see AnimationType "AnimationType".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 *
 * @brief Method is used to specify bitmap image to the object.
 * @param bitmap platfrom bitmap object.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setBitmap:(nullable UIImage *)bitmap;

/**
 *
 * @brief Method is used to specify size of object.
 * @param width width of object in pixels.
 * @param height width of object in pixels.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setSize:(float)width
         height:(float)height;

@end
