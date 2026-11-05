#import <Foundation/Foundation.h>

/**
 * Enum described animation functions.
 * Referenced from ``NCCircleMapObject``, ``NCIconMapObject``, ``NCLocationWindow``.
 *
 * @discussion Example:
 * @code
 * NSArray *animationTypes = @[
 *    @(NCAnimationTypeLinear),
 *    @(NCAnimationTypeCubic),
 *    @(NCAnimationTypeQuint),
 *    @(NCAnimationTypeSine),
 *    @(NCAnimationTypeNone),
 * ];
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCAnimationType)
{
    /**
     * disable animation
     */
    NCAnimationTypeNone,
    /**
     * animation according to formula `f(t) = t`.
     */
    NCAnimationTypeLinear,
    /**
     * animation according to formula `f(t) = (-2 * t + 3) * t * t`.
     */
    NCAnimationTypeCubic,
    /**
     * animation according to formula `f(t) = (6 * t * t - 15 * t + 10) * t * t * t`.
     */
    NCAnimationTypeQuint,
    /**
     * animation according to formula `f(t) = 0.5 - 0.5 * cos(PI * t)`.
     */
    NCAnimationTypeSine,
};
