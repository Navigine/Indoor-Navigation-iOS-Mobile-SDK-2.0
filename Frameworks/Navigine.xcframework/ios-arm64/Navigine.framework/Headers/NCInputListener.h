#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * Class is used to listen for interactions with location view
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCInputListener <NSObject>

/**
 * Called when a tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 * @discussion Example:
 * @code
 * - (void)onViewTapWithScreenPoint:(NCPoint *)screenPoint {
 *    NSLog(@"View tapped at screen position (%.1f, %.1f)", screenPoint.x, screenPoint.y);
 * }
 * @endcode
 */
- (void)onViewTap:(CGPoint)screenPoint;

/**
 * Called when a double tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 * @discussion Example:
 * @code
 * - (void)onViewDoubleTapWithScreenPoint:(NCPoint *)screenPoint {
 *    NSLog(@"View double tapped at screen position (%.1f, %.1f)", screenPoint.x, screenPoint.y);
 * }
 * @endcode
 */
- (void)onViewDoubleTap:(CGPoint)screenPoint;

/**
 * Called when a long tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 * @discussion Example:
 * @code
 * - (void)onViewLongTapWithScreenPoint:(NCPoint *)screenPoint {
 *    NSLog(@"View long tapped at screen position (%.1f, %.1f)", screenPoint.x, screenPoint.y);
 * }
 * @endcode
 */
- (void)onViewLongTap:(CGPoint)screenPoint;

@end
