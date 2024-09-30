#import "NCAnimationType.h"
#import "NCCamera.h"
#import "NCCameraCallback.h"
#import "NCDebugFlag.h"
#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCCircleMapObject;
@class NCFlatIconMapObject;
@class NCIconMapObject;
@class NCPolylineMapObject;
@protocol NCCameraListener;
@protocol NCInputListener;
@protocol NCPickListener;


/** Class is used to interact with the view. */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationWindow : NSObject

/**
 *
 * Method is used to switch LocationView between sublocations (floors).
 * @param id - sublocation unique identifier (@see Sublocation class or CMS).
 *
 */
- (void)setSublocationId:(int32_t)id;

/**
 *
 * Method is used to convert screen (pixels) coordinates to metrics coordinates.
 * @param point - (x,y) point in screen pixels.
 * @return (x,y) point in meters coordinates (@see Point class).
 *
 */
- (nonnull NCPoint *)screenPositionToMeters:(CGPoint)point;

/**
 *
 * Method is used to convert metrics coordinates to screen (pixels) coordinates.
 * @param point - (x,y) point in meters coordinates (@see Point class).
 * @param clipToViewport - if true, results that would be outside the viewport are clipped to a position on the edge of the viewport in the direction of the location.
 * @return (x,y) point in screen pixels.
 *
 */
- (CGPoint)metersToScreenPosition:(nonnull NCPoint *)point
                   clipToViewport:(BOOL)clipToViewport;

/**
 *
 * Method is used to create and add circle map object to the LocationView.
 * @return CircleMapObject instance (@see CircleMapObject) if success, null otherwise.
 *
 */
- (nullable NCCircleMapObject *)addCircleMapObject;

/**
 *
 * Method is used to remove circle map object from the LocationView.
 * @param CircleMapObject instance (@see CircleMapObject).
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeCircleMapObject:(nullable NCCircleMapObject *)circleMapObject;

/**
 *
 * Method is used to create and add icon map object to the LocationView.
 * @return IconMapObject instance (@see IconMapObject) if success, null otherwise.
 *
 */
- (nullable NCIconMapObject *)addIconMapObject;

/**
 *
 * Method is used to remove icon map object from the LocationView.
 * @param IconMapObject instance (@see IconMapObject).
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 *
 * Method is used to create and add flat icon map object to the LocationView.
 * @return FlatIconMapObject instance (@see FlatIconMapObject) if success, null otherwise.
 *
 */
- (nullable NCFlatIconMapObject *)addFlatIconMapObject;

/**
 *
 * Method is used to remove flat icon map object from the LocationView.
 * @param FlatIconMapObject instance (@see FlatIconMapObject).
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeFlatIconMapObject:(nullable NCFlatIconMapObject *)iconMapObject;

/**
 *
 * Method is used to create and add polyline map object to the LocationView.
 * @return PolylineMapObject instance (@see PolylineMapObject) if success, null otherwise.
 *
 */
- (nullable NCPolylineMapObject *)addPolylineMapObject;

/**
 *
 * Method is used to remove polyline map object from the LocationView.
 * @param PolylineMapObject instance (@see PolylineMapObject).
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removePolylineMapObject:(nullable NCPolylineMapObject *)polylineMapObject;

/**
 *
 * Method is used to remove all object from the LocationView.
 *
 */
- (void)removeAllMapObjects;

/**
 *
 * Method is used to select a visible map object marked as `interactive` (@see MapObject).
 * The result will be delivered to the `PickListener` by `onMapObjectPickComplete` (@see PickListener).
 * @param point - position in the view to pick from, in pixels.
 *
 */
- (void)pickMapObjectAt:(CGPoint)point;

/**
 *
 * Method is used to select a visible map features, such as venues etc.
 * The result will be delivered to the `PickListener` by `onMapFeaturePickComplete` (@see PickListener).
 * @param point - position in the view to pick from, in pixels.
 *
 */
- (void)pickMapFeatureAt:(CGPoint)point;

/**
 *
 * Method is used to add listener to handle picking results (@see PickListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addPickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removePickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * Method is used to add listener to handle input results (@see InputListener).
 * Such as tap, double tap, long tap
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * Method is used to add listener to handle camera movements (@see CameraListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * Move the map camera to a new position with an easing animation.
 *
 * @param camera The new camera position
 * @param duration The animation duration in milliseconds
 * @param completion A callback to execute when the animation completes
 *
 */
- (void)flyTo:(nonnull NCCamera *)camera
     duration:(int32_t)duration
     callback:(nullable NCCameraCallback)callback;

/**
 *
 * Move the map camera to a new position with an animation that pans and zooms in a smooth arc.
 *
 * The animation duration is calculated based on the distance to the new camera position and the specified speed
 *
 * @param camera The new camera position
 * @param duration Duration of the animation in milliseconds (-1 for default duration)
 * @param animationType The type of easing animation
 * @param callback A callback to execute when the animation completes
 *
 */
- (void)moveTo:(nonnull NCCamera *)camera
      duration:(int32_t)duration
 animationType:(NCAnimationType)animationType
      callback:(nullable NCCameraCallback)callback;

/**
 *
 * @internal
 * Don't use it if you don't know what is it
 *
 */
- (void)applyFilter:(nonnull NSString *)filter
              layer:(nonnull NSString *)layer;

/**
 *
 * @internal
 * Don't use it if you don't know what is it
 *
 */
- (void)setIcons:(nonnull NSDictionary<NSString *, UIImage *> *)icons;

/**
 *
 * @internal
 * Don't use it if you don't know what is it
 *
 */
+ (void)setDebugFlag:(NCDebugFlag)flag
                  on:(BOOL)on;

/**
 *
 * @internal
 * Don't use it if you don't know what is it
 *
 */
+ (BOOL)getDebugFlag:(NCDebugFlag)flag;

/**
 *
 * Parameter is used to change LocationView zoom.
 * @param zoomFactor - value indicates count of pixels in 1 meter (default: approx 100m in screen width).
 *
 */
@property (nonatomic) float zoomFactor;

/**
 *
 * @param minZoomFactor - minimum zoomFactor value (@see zoomFactor parameter).
 *
 */
@property (nonatomic) float minZoomFactor;

/**
 *
 * @param zoomFactor - maximum zoomFactor value (@see zoomFactor parameter).
 *
 */
@property (nonatomic) float maxZoomFactor;

/**
 *
 * Parameter is used to enable/disable sublocation content sticking to screen borders.
 * @param stickToBorder - if true image sticking to screen bounds, if false sticking to center of screen (Default: true).
 *
 */
@property (nonatomic) BOOL stickToBorder;

/**
 *
 * Current camera position in meters.
 *
 */
@property (nonatomic, nonnull) NCCamera * camera;

/**
 *
 * Parameter is used to enable/disable rotation gestures, such as rotation with two fingers.
 *
 */
@property (nonatomic) BOOL rotateGestureEnabled;

/**
 *
 * Parameter is used to enable/disable tilt gestures, such as parallel pan with two fingers.
 *
 */
@property (nonatomic) BOOL tiltGesturesEnabled;

/**
 *
 * Parameter is used to enable/disable scroll gestures, such as the pan gesture.
 *
 */
@property (nonatomic) BOOL scrollGesturesEnabled;

/**
 *
 * Parameter is used to enable/disable zoom gestures, such as the pinch with two fingers.
 *
 */
@property (nonatomic) BOOL zoomGesturesEnabled;

/**
 *
 * Radius to use when picking features on the map. The default radius is 0.5 dp.
 * @param pickRadius - radius in dp (density-independent pixels).
 *
 */
@property (nonatomic) float pickRadius;

@end
