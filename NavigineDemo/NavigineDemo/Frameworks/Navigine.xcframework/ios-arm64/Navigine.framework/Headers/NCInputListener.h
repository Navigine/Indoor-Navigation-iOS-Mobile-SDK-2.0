#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * @file NCInputListener.h
 * @brief @copybrief NCInputListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to listen for interactions with location view
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCInputListener <NSObject>

/**
 *
 * @brief Called when a tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 */
- (void)onViewTap:(CGPoint)screenPoint;

/**
 *
 * @brief Called when a double tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 */
- (void)onViewDoubleTap:(CGPoint)screenPoint;

/**
 *
 * @brief Called when a long tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 */
- (void)onViewLongTap:(CGPoint)screenPoint;

@end
