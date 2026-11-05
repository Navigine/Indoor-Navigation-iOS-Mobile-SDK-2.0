//
//  NCFloorSelectorViewConfig.h
//  Configuration for NCFloorSelectorView widget
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Configuration for NCFloorSelectorView widget.
 * Allows customization of styles and layout.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_FloorSelectorViewConfig
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_FloorSelectorViewConfig
 */
@interface NCFloorSelectorViewConfig : NSObject

@property (nonatomic, strong, nullable) UIColor *accentColor;
@property (nonatomic, strong, nullable) UIColor *textColor;
@property (nonatomic, strong, nullable) UIColor *buttonBackgroundColor;
@property (nonatomic, assign) UIEdgeInsets insets;       /**< UIEdgeInsetsZero = use defaults */

+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
