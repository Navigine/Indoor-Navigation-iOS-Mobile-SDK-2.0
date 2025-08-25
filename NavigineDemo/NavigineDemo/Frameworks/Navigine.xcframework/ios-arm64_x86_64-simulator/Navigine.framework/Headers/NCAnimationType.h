#import <Foundation/Foundation.h>

/**
 * @file NCAnimationType.h
 * @brief @copybrief NCAnimationType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @brief Enum described animation functions.
 *
 * Referenced from @see CircleMapObject "CircleMapObject", @see IconMapObject "IconMapObject", @see LocationWindow "LocationWindow".
 *
 */
typedef NS_ENUM(NSInteger, NCAnimationType)
{
    /**
     * @brief disable animation
     */
    NCAnimationTypeNone,
    /**
     * @brief animation according to formula `f(t) = t`.
     */
    NCAnimationTypeLinear,
    /**
     * @brief animation according to formula `f(t) = (-2 * t + 3) * t * t`.
     */
    NCAnimationTypeCubic,
    /**
     * @brief animation according to formula `f(t) = (6 * t * t - 15 * t + 10) * t * t * t`.
     */
    NCAnimationTypeQuint,
    /**
     * @brief animation according to formula `f(t) = 0.5 - 0.5 * cos(PI * t)`.
     */
    NCAnimationTypeSine,
};
