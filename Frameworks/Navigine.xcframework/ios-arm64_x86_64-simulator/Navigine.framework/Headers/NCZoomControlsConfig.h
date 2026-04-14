//
//  NCZoomControlsConfig.h
//  Configuration for NCZoomControls widget
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Configuration for NCZoomControls widget.
 * Allows customization of icons, styles and layout.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_ZoomControlsConfig
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_ZoomControlsConfig
 */
@interface NCZoomControlsConfig : NSObject

@property (nonatomic, strong, nullable) UIImage *zoomInIcon;
@property (nonatomic, strong, nullable) UIImage *zoomOutIcon;
@property (nonatomic, strong, nullable) UIColor *buttonBackgroundColor;
@property (nonatomic, strong, nullable) UIColor *textColor;
@property (nonatomic, assign) CGFloat buttonWidth;       /**< 0 = default 48 */
@property (nonatomic, assign) CGFloat zoomControlsHeight; /**< 0 = default 96 */
@property (nonatomic, assign) UIEdgeInsets insets;       /**< UIEdgeInsetsZero = use defaults */

+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
