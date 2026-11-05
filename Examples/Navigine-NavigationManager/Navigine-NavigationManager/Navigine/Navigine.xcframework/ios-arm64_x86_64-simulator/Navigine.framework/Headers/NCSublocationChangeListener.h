#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Class is used to listen for sublocation change events
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCSublocationChangeListener <NSObject>

/**
 * Called when active sublocation changes.
 * @param sublocationId New active sublocation identifier.
 *
 * @discussion Example:
 * @code
 * - (void)onActiveSublocationChanged:(int32_t)sublocationId {
 *    NSLog(@"Active sublocation changed to: %d", sublocationId);
 * }
 * @endcode
 */
- (void)onActiveSublocationChanged:(int32_t)sublocationId;

@end
