#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCIconMapObject.h"
#import <Foundation/Foundation.h>


/**
 * @file NCFlatIconMapObject.h
 * @brief @copybrief NCFlatIconMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief represents icon object on location view.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 * @note FlatIconMapObject keep orientation to location view surface.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCFlatIconMapObject : NCIconMapObject

/**
 *
 * @brief Method is used to specify rotation of object.
 * @param angle angle of rotation in degrees.
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setAngle:(double)angle;

/**
 *
 * @brief Method is used to rotate object with specified animation.
 * @param angle angle of rotation in degrees.
 * @param duration animation duration in seconds.
 * @param type animation type @see AnimationType "AnimationType".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)setAngleAnimated:(double)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

@end
