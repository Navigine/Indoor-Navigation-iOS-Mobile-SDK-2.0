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
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_InputListener_onViewTap
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_InputListener_onViewTap
 *
 *
 */
- (void)onViewTap:(CGPoint)screenPoint;

/**
 *
 * @brief Called when a double tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_InputListener_onViewDoubleTap
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_InputListener_onViewDoubleTap
 *
 *
 */
- (void)onViewDoubleTap:(CGPoint)screenPoint;

/**
 *
 * @brief Called when a long tap occurred.
 * @param screenPoint point in screen coordinates.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_InputListener_onViewLongTap
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_InputListener_onViewLongTap
 *
 *
 */
- (void)onViewLongTap:(CGPoint)screenPoint;

@end
