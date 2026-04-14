//
//  NCWidgetStyles.h
//  Common styles and constants for navigation widgets
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// ============================================================================
// Colors
// ============================================================================

/// Base dark color (used for text and borders)
static inline UIColor * kNCBaseBlackColor(void) {
    return [UIColor colorWithRed:21./255 green:45./255 blue:71./255 alpha:1];
}

/// Base blue color (used for highlighted elements)
static inline UIColor * kNCBaseBlueColor(void) {
    return [UIColor colorWithRed:48./255 green:170./255 blue:217./255 alpha:1];
}

/// Button background color (semi-transparent light gray)
static inline UIColor * kNCButtonBackgroundColor(void) {
    return [UIColor colorWithRed:250./255 green:250./255 blue:250./255 alpha:0.8];
}

/// Button background color (more opaque variant)
static inline UIColor * kNCButtonBackgroundColorOpaque(void) {
    return [UIColor colorWithRed:250./255 green:250./255 blue:250./255 alpha:0.95];
}

/// White background color (for active state)
static inline UIColor * kNCWhiteBackgroundColor(void) {
    return [UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.95];
}

/// Border color (for active button state)
static inline UIColor * kNCBorderColor(void) {
    return [UIColor colorWithRed:0.82 green:0.82 blue:0.82 alpha:1];
}

/// Shadow color
static inline UIColor * kNCShadowColor(void) {
    return [UIColor colorWithRed:0.082 green:0.176 blue:0.278 alpha:0.2];
}

// ============================================================================
// Sizes
// ============================================================================

/// Standard button and widget width
static const CGFloat kNCStandardButtonWidth = 48.0;

/// Standard button height
static const CGFloat kNCStandardButtonHeight = 48.0;

/// Zoom controls height
static const CGFloat kNCZoomControlsHeight = 96.0;

/// Floor selector row height
static const CGFloat kNCFloorRowHeight = 42.0;

/// Maximum floor selector height
static const CGFloat kNCFloorSelectorMaxHeight = 250.0;

/// Maximum number of visible floors
static const NSInteger kNCMaxVisibleFloors = 6;

// ============================================================================
// Border Radius
// ============================================================================

/// Standard border radius
static const CGFloat kNCBorderRadius = 4.0;

// ============================================================================
// Padding
// ============================================================================

/// Standard right padding
static const CGFloat kNCStandardRightPadding = 4.0;

/// Standard left padding
static const CGFloat kNCStandardLeftPadding = 16.0;

/// Top padding for floor selector
static const CGFloat kNCFloorSelectorTopPadding = 145.0;

/// Bottom padding for Follow Me button
static const CGFloat kNCFollowMeBottomPadding = 48.0;

// ============================================================================
// Typography
// ============================================================================

/// Font size for zoom buttons and Follow Me button
static const CGFloat kNCButtonFontSize = 22.0;

/// Font size for scroll buttons
static const CGFloat kNCScrollButtonFontSize = 20.0;

/// Font size for floor selector
static const CGFloat kNCFloorSelectorFontSize = 17.0;

// ============================================================================
// Shadows
// ============================================================================

/// Shadow opacity
static const CGFloat kNCShadowOpacity = 1.0;

/// Shadow radius
static const CGFloat kNCShadowRadius = 6.0;

/// Shadow offset
static const CGSize kNCShadowOffset = {0, 4};

// ============================================================================
// Animations
// ============================================================================

/// Standard animation duration
static const NSTimeInterval kNCStandardAnimationDuration = 0.35;

/// Spring animation damping
static const CGFloat kNCSpringAnimationDamping = 0.7;

/// Spring animation initial velocity
static const CGFloat kNCSpringAnimationInitialVelocity = 0.5;

// ============================================================================
// Borders
// ============================================================================

/// Border width for active state
static const CGFloat kNCActiveBorderWidth = 1.5;

NS_ASSUME_NONNULL_END
