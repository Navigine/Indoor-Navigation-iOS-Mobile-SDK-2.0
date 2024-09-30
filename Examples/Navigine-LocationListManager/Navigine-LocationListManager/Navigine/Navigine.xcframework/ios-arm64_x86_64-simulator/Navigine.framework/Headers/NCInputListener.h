#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/** Class is used to listen for interactions with view (@see LocationView). */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCInputListener <NSObject>

/**
 *
 * Called when a tap occurred.
 * @param screenPoint - point in screen coordinates.
 *
 */
- (void)onViewTap:(CGPoint)screenPoint;

/**
 *
 * Called when a double tap occurred.
 * @param screenPoint - point in screen coordinates.
 *
 */
- (void)onViewDoubleTap:(CGPoint)screenPoint;

/**
 *
 * Called when a long tap occurred.
 * @param screenPoint - point in screen coordinates.
 *
 */
- (void)onViewLongTap:(CGPoint)screenPoint;

@end
