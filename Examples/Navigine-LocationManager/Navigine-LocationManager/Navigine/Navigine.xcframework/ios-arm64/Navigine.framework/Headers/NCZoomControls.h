//
//  NCZoomControls.h
//  Zoom controls widget for navigation view
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NCZoomControlsConfig;

/** @brief Callback invoked when zoom-in button is pressed. */
typedef void(^NCZoomInCallback)(void);

/** @brief Callback invoked when zoom-out button is pressed. */
typedef void(^NCZoomOutCallback)(void);

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Compact +/- zoom control stack for navigation view.
 * Forwards tap callbacks to the host.
 *
 * @ref NCZoomControlsConfig "NCZoomControlsConfig" for styling.
 */
@interface NCZoomControls : UIView

/**
 * @brief Initializes zoom controls with callbacks.
 * @param onZoomIn Called on zoom-in button press.
 * @param onZoomOut Called on zoom-out button press.
 */
- (instancetype)initWithOnZoomIn:(NCZoomInCallback)onZoomIn onZoomOut:(NCZoomOutCallback)onZoomOut;

/**
 * @brief Initializes zoom controls with callbacks and optional config.
 * @param onZoomIn Called on zoom-in button press.
 * @param onZoomOut Called on zoom-out button press.
 * @param config Optional config for icons and styles. nil = use defaults.
 */
- (instancetype)initWithOnZoomIn:(NCZoomInCallback)onZoomIn
                       onZoomOut:(NCZoomOutCallback)onZoomOut
                          config:(nullable NCZoomControlsConfig *)config;

/** @brief Applies config at runtime. Call when config has changed. */
- (void)applyConfig:(nullable NCZoomControlsConfig *)config;

@end

NS_ASSUME_NONNULL_END
