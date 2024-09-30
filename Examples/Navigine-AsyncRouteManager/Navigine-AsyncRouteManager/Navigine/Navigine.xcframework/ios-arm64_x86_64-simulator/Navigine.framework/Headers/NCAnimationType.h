#import <Foundation/Foundation.h>

/** Describe animation functions */
typedef NS_ENUM(NSInteger, NCAnimationType)
{
    /** Disable animation */
    NCAnimationTypeNone,
    /** Animation according to formula `f(t) = t`. */
    NCAnimationTypeLinear,
    /** Animation according to formula `f(t) = (-2 * t + 3) * t * t`. */
    NCAnimationTypeCubic,
    /** Animation according to formula `f(t) = (6 * t * t - 15 * t + 10) * t * t * t`. */
    NCAnimationTypeQuint,
    /** Animation according to formula `f(t) = 0.5 - 0.5 * cos(PI * t)`. */
    NCAnimationTypeSine,
};
