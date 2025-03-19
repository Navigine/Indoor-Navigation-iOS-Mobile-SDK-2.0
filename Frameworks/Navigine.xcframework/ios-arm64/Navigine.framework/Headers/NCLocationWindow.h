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


/**
 * @file NCLocationWindow.h
 * @brief @copybrief NCLocationWindow
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to interact with the view.
 *
 * Referenced from: @see LocationView "LocationView",
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationWindow : NSObject

/**
 *
 * @brief Method is used to switch location view between sublocations (floors).
 * @param id sublocation unique identifier @see Sublocation "Sublocation".
 *
 */
- (void)setSublocationId:(int32_t)id;

/**
 *
 * @brief Method is used to convert screen (pixels) coordinates to metrics coordinates.
 * @param point (x,y) point in screen pixels.
 * @return (x,y) point in meters coordinates @see Point "Point".
 *
 */
- (nonnull NCPoint *)screenPositionToMeters:(CGPoint)point;

/**
 *
 * @brief Method is used to convert metrics coordinates to screen (pixels) coordinates.
 * @param point (x,y) point in meters coordinates @see Point "Point".
 * @param clipToViewport if true, results that would be outside the viewport are clipped to a position on the edge of the viewport in the direction of the location.
 * @return (x,y) point in screen pixels.
 *
 */
- (CGPoint)metersToScreenPosition:(nonnull NCPoint *)point
                   clipToViewport:(BOOL)clipToViewport;

/**
 *
 * @brief Method is used to create and add circle map object to the location view.
 * @return CircleMapObject instance @see CircleMapObject "CircleMapObject" if success, null otherwise.
 *
 */
- (nullable NCCircleMapObject *)addCircleMapObject;

/**
 *
 * @brief Method is used to remove circle map object from the location view.
 * @param circleMapObject circle map object instance @see CircleMapObject "CircleMapObject".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeCircleMapObject:(nullable NCCircleMapObject *)circleMapObject;

/**
 *
 * @brief Method is used to create and add icon map object to the location view.
 * @return IconMapObject instance @see IconMapObject "IconMapObject" if success, null otherwise.
 *
 */
- (nullable NCIconMapObject *)addIconMapObject;

/**
 *
 * @brief Method is used to remove icon map object from the location view.
 * @param iconMapObject icon map object instance @see IconMapObject "IconMapObject".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 *
 * @brief Method is used to create and add flat icon map object to the location view.
 * @return FlatIconMapObject instance @see FlatIconMapObject "FlatIconMapObject" if success, null otherwise.
 *
 */
- (nullable NCFlatIconMapObject *)addFlatIconMapObject;

/**
 *
 * @brief Method is used to remove flat icon map object from the location view.
 * @param flatIconMapObject flat icon map object instance @see FlatIconMapObject "FlatIconMapObject".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removeFlatIconMapObject:(nullable NCFlatIconMapObject *)flatIconMapObject;

/**
 *
 * @brief Method is used to create and add polyline map object to the location view.
 * @return PolylineMapObject instance @see PolylineMapObject "PolylineMapObject" if success, null otherwise.
 *
 */
- (nullable NCPolylineMapObject *)addPolylineMapObject;

/**
 *
 * @brief Method is used to remove polyline map object from the location view.
 * @param polylineMapObject polyline map object instance @see PolylineMapObject "PolylineMapObject".
 * @return true if success, false otherwise.
 *
 */
- (BOOL)removePolylineMapObject:(nullable NCPolylineMapObject *)polylineMapObject;

/**
 *
 * @brief Method is used to remove all object from the location view.
 *
 */
- (void)removeAllMapObjects;

/**
 *
 * @brief Method is used to select a visible map object marked as `interactive` @see MapObject "MapObject".
 * The result will be delivered to the `PickListener` by `onMapObjectPickComplete` @see PickListener "PickListener".
 * @param point position in the view to pick from, in pixels.
 *
 */
- (void)pickMapObjectAt:(CGPoint)point;

/**
 *
 * @brief Method is used to select a visible map features, such as venues etc.
 * The result will be delivered to the `PickListener` by `onMapFeaturePickComplete` @see PickListener "PickListener".
 * @param point position in the view to pick from, in pixels.
 *
 */
- (void)pickMapFeatureAt:(CGPoint)point;

/**
 *
 * @brief Method is used to add @see PickListener "PickListener" class element which will notify
 * all picking results events.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see PickListener "PickListener" listener class.
 *
 */
- (void)addPickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see PickListener "PickListener" class element.
 * @param listener Сorresponding @see PickListener "PickListener" class to remove.
 *
 */
- (void)removePickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * @brief Method is used to add @see InputListener "InputListener" class element which will notify
 * input events.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see InputListener "InputListener" listener class.
 *
 */
- (void)addInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see InputListener "InputListener" class element.
 * @param listener Сorresponding @see InputListener "InputListener" class to remove.
 *
 */
- (void)removeInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * @brief Method is used to add @see CameraListener "CameraListener" class element which will notify
 * camera movements events.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see CameraListener "CameraListener" listener class.
 *
 */
- (void)addCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see CameraListener "CameraListener" class element.
 * @param listener Сorresponding @see CameraListener "CameraListener" class to remove.
 *
 */
- (void)removeCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * @brief Move the map camera to a new position with an easing animation.
 *
 * @param camera The new camera position
 * @param duration The animation duration in milliseconds
 * @param callback completion callback to execute when the animation completes
 *
 */
- (void)flyTo:(nonnull NCCamera *)camera
     duration:(int32_t)duration
     callback:(nullable NCCameraCallback)callback;

/**
 * @cond
 */
- (void)applyFilter:(nonnull NSString *)filter
              layer:(nonnull NSString *)layer;

- (void)setIcons:(nonnull NSDictionary<NSString *, UIImage *> *)icons;

+ (void)setDebugFlag:(NCDebugFlag)flag
                  on:(BOOL)on;

+ (BOOL)getDebugFlag:(NCDebugFlag)flag;

/**
 * @endcond
 *
 * @brief Move the map camera to a new position with an animation that pans and zooms in a smooth arc.
 *
 * @note The animation duration is calculated based on the distance to the new camera position and the specified speed
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
 * @brief Parameter is used to change location view zoom.
 * Value indicates count of pixels in 1 meter (default: approx 100m in screen width).
 *
 */
@property (nonatomic) float zoomFactor;

/**
 *
 * @brief Minimum zoomFactor value (ZoomFactor parameter).
 *
 */
@property (nonatomic) float minZoomFactor;

/**
 *
 * @brief Maximum zoomFactor value (ZoomFactor parameter).
 *
 */
@property (nonatomic) float maxZoomFactor;

/**
 *
 * @brief Parameter is used to enable/disable sublocation content sticking to screen borders.
 * If true image sticking to screen bounds, if false sticking to center of screen (Default: true).
 *
 */
@property (nonatomic) BOOL stickToBorder;

/**
 *
 * @brief Current camera position in meters.
 *
 */
@property (nonatomic, nonnull) NCCamera * camera;

/**
 *
 * @brief Parameter is used to enable/disable rotation gestures, such as rotation with two fingers.
 *
 */
@property (nonatomic) BOOL rotateGestureEnabled;

/**
 *
 * @brief Parameter is used to enable/disable tilt gestures, such as parallel pan with two fingers.
 *
 */
@property (nonatomic) BOOL tiltGesturesEnabled;

/**
 *
 * @brief Parameter is used to enable/disable scroll gestures, such as the pan gesture.
 *
 */
@property (nonatomic) BOOL scrollGesturesEnabled;

/**
 *
 * @brief Parameter is used to enable/disable zoom gestures, such as the pinch with two fingers.
 *
 */
@property (nonatomic) BOOL zoomGesturesEnabled;

/**
 *
 * @brief Radius to use when picking features on the map. The default radius is 0.5 dp (density-independent pixels).
 *
 */
@property (nonatomic) float pickRadius;

@end
