#import <UIKit/UIKit.h>
#import "NCExport.h"
#import "NCAnimationType.h"

NS_ASSUME_NONNULL_BEGIN

@class NCCircleMapObject;
@class NCIconMapObject;
@class NCLocationPoint;
@class NCLocationPolyline;
@class NCPolylineMapObject;
@class NCPoint;
@class NCCamera;

@protocol NCGestureRecognizerDelegate;
@protocol NCLocationViewListener;
@protocol NCPickListener;

NAVIGINE_EXPORT
@interface NCLocationView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void) setSublocationId: (int) sublocationId;

- (void) removeAllMapObjects;

- (NCCircleMapObject *) addCircleMapObject;

- (bool) removeCircleMapObject: (NCCircleMapObject *) circleMapObject;

- (NCIconMapObject *) addIconMapObject;

- (bool) removeIconMapObject: (NCIconMapObject *) iconMapObject;

- (NCPolylineMapObject *) addPolylineMapObject;

- (bool) removePolylineMapObject: (NCPolylineMapObject *) polylineMapObject;

- (void) requestRender;

- (NCPoint*) screenPositionToMeters:(CGPoint)screenPosition;

- (CGPoint) metersToScreenPosition:(NCPoint *)meters clipToViewport:(BOOL)clip;

- (void) pickMapObjectAt:(CGPoint)viewPosition;

- (void) pickMapFeatureAt:(CGPoint)viewPosition;

- (void)applyFilter:(NSString *)filer layer:(NSString *)layer;

@property (assign, nonatomic) CGFloat minZoomFactor;

@property (assign, nonatomic) CGFloat maxZoomFactor;

@property (assign, nonatomic) CGFloat zoomFactor;

@property (assign, nonatomic) BOOL stickToBorder;

@property (strong, nonatomic, readonly) CADisplayLink *displayLink;

@property (assign, nonatomic) NSInteger preferredFramesPerSecond;

@property (weak, nonatomic, nullable) id<NCPickListener> pickListener;

@property (weak, nonatomic, nullable) id<NCLocationViewListener> locationViewListener;

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

#pragma mark Change View

@property (copy, nonatomic) NCCamera* camera;

/**
 Set the radius in logical pixels to use when picking features on the map (default is `0.5`).

 The `-pick*` methods will retrieve all `interactive` map objects from a circular area with this radius around the pick
 location. Setting a larger radius can help ensure that desired features are retrieved from an imprecise touch input.

 @param pixels The pick radius in logical pixels.
 */
- (void)setPickRadius:(CGFloat)pixels;

/**
 Move the map camera to a new position with an easing animation.

 @param camera The new camera position
 @param duration The animation duration in seconds
 @param animationType The type of easing animation
 @param completion A callback to execute when the animation completes
 */
- (void)setCamera:(NCCamera *)camera
     withDuration:(NSTimeInterval)duration
    animationType:(NCAnimationType)animationType
       completion:(nullable void (^)(BOOL canceled))completion;

/**
 Move the map camera to a new position with an animation that pans and zooms in a smooth arc.

 The animation duration is calculated based on the distance to the new camera position assuming a speed scaling factor of 1.0

 @param camera The new camera position
 @param callback A callback to execute when the animation completes
 */
- (void)flyToCamera:(NCCamera *)camera
           callback:(nullable void (^)(BOOL canceled))callback;

/**
 Move the map camera to a new position with an animation that pans and zooms in a smooth arc.

 @param camera The new camera position
 @param duration Duration of the animation in seconds
 @param callback A callback to execute when the animation completes
 */
- (void)flyToCamera:(NCCamera *)camera
       withDuration:(NSTimeInterval)duration
           callback:(nullable void (^)(BOOL canceled))callback;

/**
 Move the map camera to a new position with an animation that pans and zooms in a smooth arc.

 The animation duration is calculated based on the distance to the new camera position and the specified speed

 @param camera The new camera position
 @param speed Specified speed scaling factor
 @param callback A callback to execute when the animation completes
 */
- (void)flyToCamera:(NCCamera *)camera
          withSpeed:(CGFloat)speed
          callback:(nullable void (^)(BOOL canceled))callback;

#pragma mark Memory Management

/**
 Reduce memory usage by freeing currently unused resources.
 */
- (void)didReceiveMemoryWarning;

- (bool) mapObjectSetVisible:(int32_t) id visible: (bool) visible;
- (bool) mapObjectSetInteractive:(int32_t) id interactive:(bool) interactive;
- (bool) mapObjectSetStyling:(int32_t) id style: (NSString*) style;
- (bool) mapObjectSetPosition:(int32_t) id position: (NCLocationPoint*) locationPoint;
- (bool) mapObjectSetPositionAnimated:(int32_t) id position: (NCLocationPoint*) locationPoint duration: (float) duration type: (NCAnimationType) type;
- (bool) mapObjectSetBitmap:(int32_t) id;
- (bool) mapObjectSetPolyline:(int32_t) id polyline: (NCLocationPolyline*) polyline;
- (bool) mapObjectSetSize:(int32_t) id width: (float) width height: (float) height;
- (bool) mapObjectSetRadius:(int32_t) id radius: (float) radius;
- (bool) mapObjectSetWidth:(int32_t) id width: (float) width;
- (bool) mapObjectSetColor:(int32_t) id red: (float) red green: (float) green blue: (float) blue alpha: (float) alpha;

@end

NS_ASSUME_NONNULL_END
