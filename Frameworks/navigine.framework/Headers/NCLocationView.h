#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NCCircleMapObject;
@class NCLineMapObject;
@class NCTextureMapObject;
@class NCPoint;
@class NCSublocation;

@protocol NCGestureRecognizerDelegate;

@interface NCLocationView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (NCCircleMapObject *) createCircleMapObject;

- (void)addCircleMapObject: (NCCircleMapObject *)mapObject;

- (void)setCircleMapObjects: (NSArray<NCCircleMapObject *> *)mapObjects withVisibility: (bool) visibility;

- (nullable NCCircleMapObject *) getObjectAt: (NCPoint *)point;

- (NCLineMapObject *) createLineMapObject;

- (void)addLineMapObject: (NCLineMapObject *)mapObject;

- (void)setLineMapObjects: (NSArray<NCLineMapObject *> *)mapObjects withVisibility: (bool) visibility;

- (NCTextureMapObject *) createTextureMapObject;

- (void) addTextureMapObject: (NCTextureMapObject *)mapObject;

- (void)setTextureMapObjects: (NSArray<NCTextureMapObject *> *)mapObjects withVisibility: (bool) visibility;

- (NCPoint *) screenToMetricCoordinates: (NCPoint *) point;

- (void) setSublocation: (int) sublocationId;

- (void) setTargetPoint: (NCPoint *) point;

- (void) showBeacons: (bool) visibility;

- (void) showEddystones: (bool) visibility;

- (void) showWifis: (bool) visibility;

- (void) showVenues: (bool) visibility;

- (void) setBackgroundColor: (float) red green: (float) green blue: (float) blue alpha: (float) alpha;

- (void) setMaxScale: (float) scale;

- (void) setMinScale: (float) scale;

- (void) setZoomScale: (float) scale;

- (void) attachToPosition: (bool) status;

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
 Replaces the long press gesture recognizer used by the map view and adds it to the UIView.
 */
@property (strong, nonatomic) UILongPressGestureRecognizer* longPressGestureRecognizer;

@end

NS_ASSUME_NONNULL_END
