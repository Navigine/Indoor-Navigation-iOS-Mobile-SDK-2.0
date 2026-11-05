//
//  NCDefaultNavigineViewConfig.h
//  Configuration for DefaultNavigineView (visibility only)
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Visibility options for built-in map chrome widgets (zoom + floor).
 */
typedef NS_OPTIONS(NSUInteger, NCNavigineWidgetVisibility) {
    NCNavigineWidgetVisibilityZoomControls = 1 << 0,
    NCNavigineWidgetVisibilityFloorSelector = 1 << 2,
    NCNavigineWidgetVisibilityAll = (1 << 0) | (1 << 2),
};

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigine_view
 *
 * @brief Configuration for NCDefaultNavigineView.
 * Controls visibility of built-in floor selector and zoom controls.
 */
@interface NCDefaultNavigineViewConfig : NSObject

/** @brief Bitmask of visible widgets (default: NCNavigineWidgetVisibilityAll) */
@property (nonatomic, assign) NCNavigineWidgetVisibility visibleWidgets;

+ (instancetype)defaultConfig;

@end

NS_ASSUME_NONNULL_END
