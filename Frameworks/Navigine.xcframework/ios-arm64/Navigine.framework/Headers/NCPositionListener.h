#import "NCExport.h"
#import "NCPosition.h"
#import <Foundation/Foundation.h>


/**
 * @file NCPositionListener.h
 * @brief @copybrief NCPositionListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_listeners
 * @brief Class provides a callback to be invoked when @see NavigationManager "NavigationManager"
 * updates the position of the device.
 *
 * Referenced from @see NavigationManager "NavigationManager" @see RouteManager "RouteManager".
 * @note The callback is invoked in the UI thread.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPositionListener <NSObject>

/**
 *
 * @brief Called when new position has been calculated
 * @param position current user @see Position "Position".
 *
 *
 * Swift code snippet:
 * @snippet NavigationManagerExample.swift swift_PositionListener_onPositionUpdated
 *
 * Objective C code snippet:
 * @snippet NavigationManagerExample.m objc_PositionListener_onPositionUpdated
 *
 *
 */
- (void)onPositionUpdated:(nonnull NCPosition *)position;

/**
 *
 * @brief Called if unable to calculate user's position
 * @param error handled error.
 *
 *
 * Swift code snippet:
 * @snippet NavigationManagerExample.swift swift_PositionListener_onPositionError
 *
 * Objective C code snippet:
 * @snippet NavigationManagerExample.m objc_PositionListener_onPositionError
 *
 *
 */
- (void)onPositionError:(nullable NSError *)error;

@end
