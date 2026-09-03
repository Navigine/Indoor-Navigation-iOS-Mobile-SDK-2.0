#import <UIKit/UIKit.h>

#import "NCLocationView.h"

NS_ASSUME_NONNULL_BEGIN

@class NCDefaultNavigineViewConfig;
@class NCFloorSelectorView;
@class NCFloorSelectorViewConfig;
@class NCZoomControls;
@class NCZoomControlsConfig;

/**
 * @file NCDefaultNavigineView.h
 * @brief @copybrief NCDefaultNavigineView
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @ingroup navigine_objc_default_navigine_view
 *
 * @brief Base location view with built-in map chrome:
 * @ref NCZoomControls "zoom controls" and @ref NCFloorSelectorView "floor selector".
 * Automatically wires building/sublocation listeners and keeps widgets in sync.
 * Use @ref NCDefaultNavigineViewConfig "NCDefaultNavigineViewConfig" to customize;
 * config can be updated at runtime via the viewConfig property.
 *
 * Subclassed by @ref NCDefaultNavigationView "NCDefaultNavigationView" (follow-me +
 * user location) and @ref NCDefaultTrackingView "NCDefaultTrackingView" (live objects).
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCDefaultNavigineView : NCLocationView

/**
 * @brief Initializes a location view from Interface Builder / storyboard.
 */
- (id)initWithCoder:(NSCoder *)aDecoder;

/**
 * @brief Creates a location view with the specified frame.
 */
- (id)initWithFrame:(CGRect)frame;

/**
 * @brief Creates a location view with the specified frame and view config (visibility only).
 * @param frame The frame rectangle.
 * @param config Optional view config. nil = use default.
 */
- (id)initWithFrame:(CGRect)frame config:(nullable NCDefaultNavigineViewConfig *)config;

/**
 * @brief Creates a location view with the specified frame and configs.
 * Widget configs are passed directly; nil = use defaults.
 */
- (id)initWithFrame:(CGRect)frame
         viewConfig:(nullable NCDefaultNavigineViewConfig *)viewConfig
         zoomConfig:(nullable NCZoomControlsConfig *)zoomConfig
        floorConfig:(nullable NCFloorSelectorViewConfig *)floorConfig;

/** @brief View config (visibility). Can be changed at runtime. */
@property (nonatomic, strong) NCDefaultNavigineViewConfig *viewConfig;
/** @brief Zoom controls config. Can be changed at runtime. */
@property (nonatomic, strong) NCZoomControlsConfig *zoomControlsConfig;
/** @brief Floor selector config. Can be changed at runtime. */
@property (nonatomic, strong) NCFloorSelectorViewConfig *floorSelectorConfig;

/**
 * @brief Direct access for advanced customization (read-only). May be nil if widget is hidden.
 */
@property (nonatomic, readonly, nullable) NCFloorSelectorView *floorSelectorView;
@property (nonatomic, readonly, nullable) NCZoomControls *zoomControls;

@end

NS_ASSUME_NONNULL_END
