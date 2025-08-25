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
 */
- (id)initWithFrame:(CGRect)frame;

/**
 * @brief location view's main class.
 *
 * Class is used to interact with the view.
 */
@property (nonatomic, readonly) NCLocationWindow* locationWindow;

@end

NS_ASSUME_NONNULL_END
