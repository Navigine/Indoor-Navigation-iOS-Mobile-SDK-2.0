#import <Foundation/Foundation.h>

/**
 * Debug visualization flags for the map view ``NCLocationWindow``.
 *
 * @discussion Example:
 * @code
 * NSArray<NSNumber *> *allFlags = @[
 *    @(NCDebugFlagNone),
 *    @(NCDebugFlagInfos),
 *    @(NCDebugFlagStats),
 *    @(NCDebugFlagLabels),
 *    @(NCDebugFlagDrawAllLabels),
 *    @(NCDebugFlagSelectionBuffer)
 * ];
 * NSLog(@"Debug flag enum values: %lu", (unsigned long)allFlags.count);
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCDebugFlag)
{
    NCDebugFlagNone,
    NCDebugFlagInfos,
    NCDebugFlagStats,
    NCDebugFlagLabels,
    NCDebugFlagDrawAllLabels,
    NCDebugFlagSelectionBuffer,
};
