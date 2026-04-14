//
//  NCDefaultNavigationViewConfig.h
//  Configuration for DefaultNavigationView (visibility only)
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Visibility options for built-in widgets.
 */
typedef NS_OPTIONS(NSUInteger, NCNavigationWidgetVisibility) {
    NCNavigationWidgetVisibilityZoomControls = 1 << 0,
    NCNavigationWidgetVisibilityFollowMeButton = 1 << 1,
    NCNavigationWidgetVisibilityFloorSelector = 1 << 2,
    NCNavigationWidgetVisibilityAll = 0x7,
};

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Configuration for NCDefaultNavigationView.
 * Controls visibility of built-in widgets.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_config
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_config
 *
 */
@interface NCDefaultNavigationViewConfig : NSObject

/** @brief Bitmask of visible widgets (default: NCNavigationWidgetVisibilityAll) */
@property (nonatomic, assign) NCNavigationWidgetVisibility visibleWidgets;

+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
