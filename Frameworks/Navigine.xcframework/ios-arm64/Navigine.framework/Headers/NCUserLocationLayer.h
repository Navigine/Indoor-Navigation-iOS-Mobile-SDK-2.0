#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * @file NCUserLocationLayer.h
 * @brief @copybrief NCUserLocationLayer
 */
/**
 *
 * @brief Layer that automatically renders current user position (arrow and accuracy circle) on the map.
 *        Provides visibility and anchoring controls.
 * Referenced from @see LocationView "LocationView".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCUserLocationLayer : NSObject

/**
 *
 * @brief Shows or hides user location layer.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationLayer_setVisible
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationLayer_setVisible
 *
 *
 */
- (void)setVisible:(BOOL)visible;

/**
 *
 * @brief Returns true if user location layer is visible.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationLayer_isVisible
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationLayer_isVisible
 *
 *
 */
- (BOOL)isVisible;

/**
 *
 * @brief Sets anchor point for user indicator in screen pixels.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationLayer_setAnchor
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationLayer_setAnchor
 *
 *
 */
- (void)setAnchor:(CGPoint)anchor;

/**
 *
 * @brief Resets anchor to default (center).
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationLayer_resetAnchor
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationLayer_resetAnchor
 *
 *
 */
- (void)resetAnchor;

/**
 *
 * @brief Returns true if custom anchor is enabled.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationLayer_anchorEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationLayer_anchorEnabled
 *
 *
 */
- (BOOL)anchorEnabled;

@end
