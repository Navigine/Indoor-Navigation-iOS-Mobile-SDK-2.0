#import <UIKit/UIKit.h>
#import "NCExport.h"

NS_ASSUME_NONNULL_BEGIN

@class NCCircleMapObject;
@class NCIconMapObject;
@class NCPolylineMapObject;
@class NCPoint;
@class NCSublocation;

@protocol NCGestureRecognizerDelegate;
@protocol NCLocationViewDelegate;

NAVIGINE_EXPORT
@interface NCLocationView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void) setSublocationId: (int) sublocationId;

- (NCCircleMapObject *) addCircleMapObject;

- (bool) removeCircleMapObject: (NCCircleMapObject *) circleMapObject;

- (NCIconMapObject *) addIconMapObject;

- (bool) removeIconMapObject: (NCIconMapObject *) iconMapObject;

- (NCPolylineMapObject *) addPolylineMapObject;

- (bool) removePolylineMapObject: (NCPolylineMapObject *) polylineMapObject;

- (void) requestRender;

- (void)pickMapObjectAt:(CGPoint)viewPosition;

@property (assign, nonatomic) CGFloat minZoomFactor;

@property (assign, nonatomic) CGFloat maxZoomFactor;

@property (assign, nonatomic) CGFloat zoomFactor;

@property (strong, nonatomic, readonly) CADisplayLink *displayLink;

@property (assign, nonatomic) NSInteger preferredFramesPerSecond;

@property (weak, nonatomic, nullable) id<NCLocationViewDelegate> locationViewDelegate;

#pragma mark Gesture Recognizers

@property (weak, nonatomic, nullable) id<NCGestureRecognizerDelegate> gestureDelegate;

/**
 Replaces the tap gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UITapGestureRecognizer* tapGestureRecognizer;

/**
 Replaces the double tap gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UITapGestureRecognizer* doubleTapGestureRecognizer;

/**
 Replaces the pan gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UIPanGestureRecognizer* panGestureRecognizer;

/**
 Replaces the pinch gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UIPinchGestureRecognizer* pinchGestureRecognizer;

/**
 Replaces the rotation gesture recognizer used by the map view and adds it to the UIView.
 */
// @property (strong, nonatomic) UIRotationGestureRecognizer* rotationGestureRecognizer;

/**
 Replaces the shove gesture recognizer used by the map view and adds it to the UIView.
 */
// @property (strong, nonatomic) UIPanGestureRecognizer* shoveGestureRecognizer;

/**
 Replaces the long press gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UILongPressGestureRecognizer* longPressGestureRecognizer;

#pragma mark Memory Management

/**
 Reduce memory usage by freeing currently unused resources.
 */
- (void)didReceiveMemoryWarning;

@end

NS_ASSUME_NONNULL_END
