#import <UIKit/UIKit.h>
#import "NCExport.h"
#import "NCAnimationType.h"
#import "NCLocationWindow.h"

NS_ASSUME_NONNULL_BEGIN

@class NCCircleMapObject;
@class NCFlatIconMapObject;
@class NCIconMapObject;
@class NCLocationPoint;
@class NCLocationPolyline;
@class NCPolylineMapObject;
@class NCPoint;
@class NCCamera;

@protocol NCPickListener;

DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationView : UIView

- (id)initWithCoder:(NSCoder *)aDecoder;

- (id)initWithFrame:(CGRect)frame;

@property (nonatomic, readonly) NCLocationWindow* locationWindow;

@end

NS_ASSUME_NONNULL_END
