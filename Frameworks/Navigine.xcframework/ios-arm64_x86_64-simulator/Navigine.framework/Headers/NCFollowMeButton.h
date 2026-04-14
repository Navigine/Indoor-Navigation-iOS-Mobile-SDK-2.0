//
//  NCFollowMeButton.h
//  Follow Me button widget for navigation view
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NCFollowMeButtonConfig;

/**
 * @brief Callback invoked when follow me is toggled.
 * @param isFollowing State after the tap (true = following).
 */
typedef void(^NCFollowMeButtonCallback)(BOOL isFollowing);

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Floating “follow me” button for navigation view.
 * Toggles following mode and updates its appearance.
 *
 * @ref NCFollowMeButtonConfig "NCFollowMeButtonConfig" for styling.
 */
@interface NCFollowMeButton : UIButton

/**
 * @brief Initializes follow me button with a callback.
 * @param onPressed Callback block called when button is pressed.
 */
- (instancetype)initWithOnPressed:(NCFollowMeButtonCallback)onPressed;

/**
 * @brief Initializes follow me button with a callback and optional config.
 * @param onPressed Callback block called when button is pressed.
 * @param config Optional config for icons and styles. nil = use defaults.
 */
- (instancetype)initWithOnPressed:(NCFollowMeButtonCallback)onPressed
                          config:(nullable NCFollowMeButtonConfig *)config;

/** @brief Updates button appearance based on following state. */
- (void)updateAppearanceForFollowingState:(BOOL)isFollowing;

/** @brief Applies config at runtime. Call when config has changed. */
- (void)applyConfig:(nullable NCFollowMeButtonConfig *)config;

/** @brief Returns current following state. */
@property (nonatomic, readonly, getter=isFollowing) BOOL following;

@end

NS_ASSUME_NONNULL_END
