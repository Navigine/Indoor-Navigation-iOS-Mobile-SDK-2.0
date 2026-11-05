#import <UIKit/UIKit.h>
#import "NCExport.h"
#import "NCAnimationType.h"
#import "NCLocationWindow.h"

NS_ASSUME_NONNULL_BEGIN

@class NCCircleMapObject;
@class NCIconMapObject;
@class NCLocationPoint;
@class NCLocationPolyline;
@class NCPolylineMapObject;
@class NCDottedPolylineMapObject;
@class NCPoint;
@class NCCamera;

@protocol NCPickListener;

/**
 * @file NCLocationView.h
 * @brief @copybrief NCLocationView
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to display a Navigine location via iOS UIView.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationView : UIView

/**
 * @brief Initializes a location view with the data from an unarchiver.
 */
- (id)initWithCoder:(NSCoder *)aDecoder;

/**
 * @brief Creates a location view with the specified frame.
 * Vulkan (MoltenVK) is preferred; falls back to system OpenGL ES.
 */
- (id)initWithFrame:(CGRect)frame;

/**
 * @brief Creates a location view, preferring Vulkan (MoltenVK) when vulkanPreferred is YES.
 * Falls back to system OpenGL ES if Vulkan cannot be created.
 * On the Apple Silicon simulator OpenGL is forced off (it does not work there).
 */
- (id)initWithFrame:(CGRect)frame vulkanPreferred:(BOOL)vulkanPreferred;

/**
 * @brief Prefer Vulkan (MoltenVK). Default YES.
 * Applied from Interface Builder before the GPU surface is created.
 * Changing it after the view is on screen has no effect — the backend is chosen once.
 */
@property (nonatomic, assign) IBInspectable BOOL vulkanPreferred;

/**
 * @brief location view's main class.
 *
 * Class is used to interact with the view.
 */
@property (nonatomic, readonly) NCLocationWindow* locationWindow;

@end

NS_ASSUME_NONNULL_END
