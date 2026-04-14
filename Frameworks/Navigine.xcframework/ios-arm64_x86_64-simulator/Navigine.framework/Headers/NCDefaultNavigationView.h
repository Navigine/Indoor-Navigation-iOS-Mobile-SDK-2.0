#import <UIKit/UIKit.h>

#import "NCLocationView.h"

NS_ASSUME_NONNULL_BEGIN

@class NCDefaultNavigationViewConfig;
@class NCFloorSelectorView;
@class NCFloorSelectorViewConfig;
@class NCFollowMeButton;
@class NCFollowMeButtonConfig;
@class NCZoomControls;
@class NCZoomControlsConfig;

/**
 * @file NCDefaultNavigationView.h
 * @brief @copybrief NCDefaultNavigationView
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Ready-to-use navigation view with built-in UI:
 * “follow me” toggle and user location layer.
 * @ref NCZoomControls "zoom controls", @ref NCFloorSelectorView "floor selector",
 * @ref NCFollowMeButton "follow me" toggle and user location layer.
 * Automatically wires SDK listeners (location, sublocation, camera) and keeps widgets in sync.
 * Use @ref NCDefaultNavigationViewConfig "NCDefaultNavigationViewConfig" to customize;
 * config can be updated at runtime via the config property.
 *
 * Basic usage with default config:
 *
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_constructor
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_constructor
 *
 *
 * Custom config at init (visibility, colors, icons) via @ref NCDefaultNavigationViewConfig "NCDefaultNavigationViewConfig":
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_constructor_config
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_constructor_config
 *
 *
 * Runtime config update:
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_runtimeConfig
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_runtimeConfig
 *
 *
 * Direct widget access for advanced customization:
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_widgetAccess
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_widgetAccess
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
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_constructor
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_constructor
 *
 */
- (id)initWithFrame:(CGRect)frame;

/**
 * @brief Creates a location view with the specified frame and view config (visibility only).
 * @param frame The frame rectangle.
 * @param config Optional view config. nil = use default.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_constructor_config
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_constructor_config
 *
 */
- (id)initWithFrame:(CGRect)frame config:(nullable NCDefaultNavigationViewConfig *)config;

/**
 * @brief Creates a location view with the specified frame and configs.
 * Widget configs are passed directly; nil = use defaults.
 */
- (id)initWithFrame:(CGRect)frame
         viewConfig:(nullable NCDefaultNavigationViewConfig *)viewConfig
        zoomConfig:(nullable NCZoomControlsConfig *)zoomConfig
    followMeConfig:(nullable NCFollowMeButtonConfig *)followMeConfig
     floorConfig:(nullable NCFloorSelectorViewConfig *)floorConfig;

/** @brief View config (visibility). Can be changed at runtime. */
@property (nonatomic, strong) NCDefaultNavigationViewConfig *viewConfig;
/** @brief Zoom controls config. Can be changed at runtime. */
@property (nonatomic, strong) NCZoomControlsConfig *zoomControlsConfig;
/** @brief Follow me button config. Can be changed at runtime. */
@property (nonatomic, strong) NCFollowMeButtonConfig *followMeButtonConfig;
/** @brief Floor selector config. Can be changed at runtime. */
@property (nonatomic, strong) NCFloorSelectorViewConfig *floorSelectorConfig;

/**
 * @brief Direct access for advanced customization (read-only). May be nil if widget is hidden.
 *
 * Swift code snippet:
 * @snippet DefaultNavigationView/swift/DefaultNavigationViewExample.swift swift_DefaultNavigationView_widgetAccess
 *
 * Objective C code snippet:
 * @snippet DefaultNavigationView/objc/DefaultNavigationViewExample.m objc_DefaultNavigationView_widgetAccess
 *
 */
@property (nonatomic, readonly, nullable) NCFloorSelectorView *floorSelectorView;
@property (nonatomic, readonly, nullable) NCZoomControls *zoomControls;
@property (nonatomic, readonly, nullable) NCFollowMeButton *followMeButton;

@end

NS_ASSUME_NONNULL_END
