#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCCircleMapObject.h
 * @brief @copybrief NCCircleMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief represents circle on location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCircleMapObject : NCMapObject

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
 * Method is used to move center of object with specified animation @see LocationPoint "LocationPoint".
 * @param point metrics coordinate of center @see LocationPoint "LocationPoint".
 * @param duration animation duration in seconds.
 * @param type @see AnimationType "AnimationType".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 *
 * @brief Method is used to specify color of object.
 * @param red red RGBA component.
 * @param green green RGBA component.
 * @param blue blue RGBA component.
 * @param alpha Opacity multiplicator. Values below 0 will be set to 0. Default: 1.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

/**
 *
 * @brief Method is used to specify size of object.
 * @param radius metrics radius of circle.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setRadius:(float)radius;

@end
