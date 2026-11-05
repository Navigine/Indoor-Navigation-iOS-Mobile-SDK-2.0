#import <Foundation/Foundation.h>

/**
 * Enum describing turn direction/severity for ``NCTurnEvent``.
 * Referenced from ``NCTurnEvent``.
 *
 * @discussion Example:
 * @code
 * NSArray<NSNumber *> *types = @[
 *    @(NCTurnTypeLeftSlight),
 *    @(NCTurnTypeLeftNormal),
 *    @(NCTurnTypeLeftSharp),
 *    @(NCTurnTypeRightSlight),
 *    @(NCTurnTypeRightNormal),
 *    @(NCTurnTypeRightSharp),
 *    @(NCTurnTypeComplete)
 * ];
 * NSLog(@"Available turn types:");
 * for (NSNumber *type in types) {
 *    NSLog(@"  - %ld", (long)[type integerValue]);
 * }
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCTurnType)
{
    /**
     * Minor left adjustment (approx. 10°–40°).
     */
    NCTurnTypeLEFTSLIGHT,
    /**
     * Standard left turn (approx. 40°–100°).
     */
    NCTurnTypeLEFTNORMAL,
    /**
     * Sharp left turn (approx. 100°–160°).
     */
    NCTurnTypeLEFTSHARP,
    /**
     * Minor right adjustment (approx. 10°–40°).
     */
    NCTurnTypeRIGHTSLIGHT,
    /**
     * Standard right turn (approx. 40°–100°).
     */
    NCTurnTypeRIGHTNORMAL,
    /**
     * Sharp right turn (approx. 100°–160°).
     */
    NCTurnTypeRIGHTSHARP,
    /**
     * Near U-turn / reversal (approx. 160°–180°).
     */
    NCTurnTypeCOMPLETE,
};
