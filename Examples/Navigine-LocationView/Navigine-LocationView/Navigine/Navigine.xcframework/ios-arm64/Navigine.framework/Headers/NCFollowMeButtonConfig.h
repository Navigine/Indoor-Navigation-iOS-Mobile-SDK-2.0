//
//  NCFollowMeButtonConfig.h
//  Configuration for NCFollowMeButton widget
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Configuration for NCFollowMeButton widget.
 * Allows customization of icons, styles and layout.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_FollowMeButtonConfig
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_FollowMeButtonConfig
 */
@interface NCFollowMeButtonConfig : NSObject

@property (nonatomic, strong, nullable) UIImage *followMeIcon;
@property (nonatomic, strong, nullable) UIImage *followMeIconActive;
@property (nonatomic, strong, nullable) UIColor *buttonBackgroundColor;
@property (nonatomic, strong, nullable) UIColor *accentColor;
@property (nonatomic, strong, nullable) UIColor *textColor;
@property (nonatomic, assign) CGFloat buttonWidth;       /**< 0 = default 48 */
@property (nonatomic, assign) CGFloat buttonHeight;      /**< 0 = default 48 */
@property (nonatomic, assign) UIEdgeInsets insets;       /**< UIEdgeInsetsZero = use defaults */

+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
