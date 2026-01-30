#import <UIKit/UIKit.h>

#import "NCLocationView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @file NCDefaultNavigationView.h
 * @brief @copybrief NCDefaultNavigationView
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Ready-to-use navigation view with built-in UI:
 *  zoom controls, floor selector, “follow me” toggle and user location layer.
 *  Hooks SDK listeners (location, sublocation, camera) and keeps widgets in sync.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCDefaultNavigationView : NCLocationView

/**
 * @brief Initializes a location view from Interface Builder / storyboard.
 */
- (id)initWithCoder:(NSCoder *)aDecoder;

/**
 * @brief Creates a location view with the specified frame.
 */
- (id)initWithFrame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
