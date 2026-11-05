#import <Foundation/Foundation.h>

/**
 * Enum describing route event variants.
 * Referenced from ``NCRouteEvent``.
 *
 * @discussion Example:
 * @code
 * // Get all route event type values
 * NSArray<NSNumber *> *types = @[
 *    @(NCRouteEventTypeTurnLeft),
 *    @(NCRouteEventTypeTurnRight),
 *    @(NCRouteEventTypeTransition)
 * ];
 * NSLog(@"Available route event types:");
 * for (NSNumber *type in types) {
 *    NSLog(@"  - %ld", (long)[type integerValue]);
 * }
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCRouteEventType)
{
    NCRouteEventTypeTURNEVENT,
    NCRouteEventTypeTRANSITIONENTRYEVENT,
    NCRouteEventTypeTRANSITIONEXITEVENT,
    NCRouteEventTypeTARGETREACHEDEVENT,
};
