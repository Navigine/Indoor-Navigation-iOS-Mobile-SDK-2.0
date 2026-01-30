#import "NCAnimationType.h"
#import "NCBoundingBox.h"
#import "NCCamera.h"
#import "NCCameraCallback.h"
#import "NCDebugFlag.h"
#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCCircleMapObject;
@class NCDottedPolylineMapObject;
@class NCIconMapObject;
@class NCPolygonMapObject;
@class NCPolylineMapObject;
@protocol NCCameraListener;
@protocol NCInputListener;
@protocol NCPickListener;
@protocol NCSublocationChangeListener;


/**
 * @file NCLocationWindow.h
 * @brief @copybrief NCLocationWindow
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Interface for interacting with the location view.
 *
 * Referenced from @see LocationView "LocationView".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationWindow : NSObject

/**
 *
 * @brief Method is used to switch the location view between sublocations (e.g., floors).
 * @param id Sublocation unique identifier @see Sublocation "Sublocation".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_setSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_setSublocationId
 *
 *
 */
- (void)setSublocationId:(int32_t)id;

/**
 *
 * @brief Returns current sublocation ID if set, otherwise null.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_getSublocationId
 *
 *
 */
- (nullable NSNumber *)getSublocationId;

/**
 *
 * @brief Calculates camera that fits provided bounding box.
 * @param boundingBox Metrics bounding box to enclose.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_getEnclosingCamera
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_getEnclosingCamera
 *
 *
 */
- (nonnull NCCamera *)getEnclosingCamera:(nonnull NCBoundingBox *)boundingBox;

/**
 *
 * @brief Converts screen coordinates (pixels) to metrics coordinates (meters).
 * @param point (x,y) coordinates in screen pixels.
 * @return (x,y) coordinates in meters @see Point "Point".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_screenPositionToMeters
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_screenPositionToMeters
 *
 *
 */
- (nonnull NCPoint *)screenPositionToMeters:(CGPoint)point;

/**
 *
 * @brief Converts metrics coordinates (meters) to screen coordinates (pixels).
 * @param point (x,y) coordinates in meters @see Point "Point".
 * @param clipToViewport If true, coordinates outside the viewport are clipped to the viewport edge.
 * @return (x,y) coordinates in screen pixels.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_metersToScreenPosition
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_metersToScreenPosition
 *
 *
 */
- (CGPoint)metersToScreenPosition:(nonnull NCPoint *)point
                   clipToViewport:(BOOL)clipToViewport;

/**
 *
 * @brief Creates and adds a circle map object to the location view.
 * @return A CircleMapObject instance @see CircleMapObject "CircleMapObject" if successful, null otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_addCircleMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_addCircleMapObject
 *
 *
 */
- (nullable NCCircleMapObject *)addCircleMapObject;

/**
 *
 * @brief Removes a circle map object from the location view.
 * @param circleMapObject The circle map object instance @see CircleMapObject "CircleMapObject".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removeCircleMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removeCircleMapObject
 *
 *
 */
- (BOOL)removeCircleMapObject:(nullable NCCircleMapObject *)circleMapObject;

/**
 *
 * @brief Creates and adds an icon map object to the location view.
 * @return An IconMapObject instance @see IconMapObject "IconMapObject" if successful, null otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_addIconMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_addIconMapObject
 *
 *
 */
- (nullable NCIconMapObject *)addIconMapObject;

/**
 *
 * @brief Removes an icon map object from the location view.
 * @param iconMapObject The icon map object instance @see IconMapObject "IconMapObject".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removeIconMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removeIconMapObject
 *
 *
 */
- (BOOL)removeIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 *
 * @brief Creates and adds a polygon map object to the location view.
 * @return A PolygonMapObject instance @see PolygonMapObject "PolygonMapObject" if successful, null otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_addPolygonMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_addPolygonMapObject
 *
 *
 */
- (nullable NCPolygonMapObject *)addPolygonMapObject;

/**
 *
 * @brief Removes a polygon map object from the location view.
 * @param polygonMapObject The polygon map object instance @see PolygonMapObject "PolygonMapObject".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removePolygonMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removePolygonMapObject
 *
 *
 */
- (BOOL)removePolygonMapObject:(nullable NCPolygonMapObject *)polygonMapObject;

/**
 *
 * @brief Creates and adds a polyline map object to the location view.
 * @return A PolylineMapObject instance @see PolylineMapObject "PolylineMapObject" if successful, null otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_addPolylineMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_addPolylineMapObject
 *
 *
 */
- (nullable NCPolylineMapObject *)addPolylineMapObject;

/**
 *
 * @brief Removes a polyline map object from the location view.
 * @param polylineMapObject The polyline map object instance @see PolylineMapObject "PolylineMapObject".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removePolylineMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removePolylineMapObject
 *
 *
 */
- (BOOL)removePolylineMapObject:(nullable NCPolylineMapObject *)polylineMapObject;

/**
 *
 * @brief Creates and adds a polyline points map object to the location view.
 * @return A DottedPolylineMapObject instance @see DottedPolylineMapObject "DottedPolylineMapObject" if successful, null otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_addDottedPolylineMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_addDottedPolylineMapObject
 *
 *
 */
- (nullable NCDottedPolylineMapObject *)addDottedPolylineMapObject;

/**
 *
 * @brief Removes a polyline points map object from the location view.
 * @param dottedPolylineMapObject The polyline points map object instance @see DottedPolylineMapObject "DottedPolylineMapObject".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removeDottedPolylineMapObject
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removeDottedPolylineMapObject
 *
 *
 */
- (BOOL)removeDottedPolylineMapObject:(nullable NCDottedPolylineMapObject *)dottedPolylineMapObject;

/**
 *
 * @brief Removes all map objects from the location view.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_LocationWindow_removeAllMapObjects
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_LocationWindow_removeAllMapObjects
 *
 *
 */
- (void)removeAllMapObjects;

/**
 *
 * @brief Selects a visible, interactive map object at the specified screen position.
 * @param point Position in screen pixels to pick from.
 * Results are delivered to the PickListener via onMapObjectPickComplete @see PickListener "PickListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_pickMapObjectAt
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_pickMapObjectAt
 *
 *
 */
- (void)pickMapObjectAt:(CGPoint)point;

/**
 *
 * @brief Selects visible map features (e.g., venues) at the specified screen position.
 * @param point Position in screen pixels to pick from.
 * Results are delivered to the PickListener via onMapFeaturePickComplete @see PickListener "PickListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_pickMapFeatureAt
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_pickMapFeatureAt
 *
 *
 */
- (void)pickMapFeatureAt:(CGPoint)point;

/**
 *
 * @brief Adds a PickListener to receive picking result events.
 * @param listener The PickListener instance @see PickListener "PickListener".
 * @note Remove the listener when no longer needed.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_addPickListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_addPickListener
 *
 *
 */
- (void)addPickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * @brief Removes a previously added PickListener.
 * @param listener The PickListener instance to remove @see PickListener "PickListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_removePickListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_removePickListener
 *
 *
 */
- (void)removePickListener:(nullable id<NCPickListener>)listener;

/**
 *
 * @brief Adds an InputListener to receive input events.
 * @param listener The InputListener instance @see InputListener "InputListener".
 * @note Remove the listener when no longer needed.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_addInputListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_addInputListener
 *
 *
 */
- (void)addInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * @brief Removes a previously added InputListener.
 * @param listener The InputListener instance to remove @see InputListener "InputListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_removeInputListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_removeInputListener
 *
 *
 */
- (void)removeInputListener:(nullable id<NCInputListener>)listener;

/**
 *
 * @brief Adds a CameraListener to receive camera movement events.
 * @param listener The CameraListener instance @see CameraListener "CameraListener".
 * @note Remove the listener when no longer needed.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCameraExample.swift swift_LocationWindow_addCameraListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowCameraExample.m objc_LocationWindow_addCameraListener
 *
 *
 */
- (void)addCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * @brief Removes a previously added CameraListener.
 * @param listener The CameraListener instance to remove @see CameraListener "CameraListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCameraExample.swift swift_LocationWindow_removeCameraListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowCameraExample.m objc_LocationWindow_removeCameraListener
 *
 *
 */
- (void)removeCameraListener:(nullable id<NCCameraListener>)listener;

/**
 *
 * @brief Adds listener for sublocation change events.
 * @param listener Sublocation change listener @see SublocationChangeListener "SublocationChangeListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_addSublocationChangeListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_addSublocationChangeListener
 *
 *
 */
- (void)addSublocationChangeListener:(nullable id<NCSublocationChangeListener>)listener;

/**
 *
 * @brief Removes previously added sublocation change listener.
 * @param listener Listener instance to remove @see SublocationChangeListener "SublocationChangeListener".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_removeSublocationChangeListener
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_removeSublocationChangeListener
 *
 *
 */
- (void)removeSublocationChangeListener:(nullable id<NCSublocationChangeListener>)listener;

/**
 *
 * @brief Moves the map camera to a new position with an easing animation.
 * @param camera The new camera position @see Camera "Camera".
 * @param duration Animation duration in milliseconds.
 * @param callback Callback to execute when the animation completes @see CameraCallback "CameraCallback".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCameraExample.swift swift_LocationWindow_flyTo
 *
 * Objective C code snippet:
 * @snippet LocationWindowCameraExample.m objc_LocationWindow_flyTo
 *
 *
 */
- (void)flyTo:(nonnull NCCamera *)camera
     duration:(int32_t)duration
     callback:(nullable NCCameraCallback)callback;

/**
 *
 * @brief Moves the map camera to a new position with a smooth pan-and-zoom animation.
 * @param camera The new camera position @see Camera "Camera".
 * @param duration Animation duration in milliseconds (-1 for default duration).
 * @param animationType The type of easing animation @see AnimationType "AnimationType".
 * @param callback Callback to execute when the animation completes @see CameraCallback "CameraCallback".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCameraExample.swift swift_LocationWindow_moveTo
 *
 * Objective C code snippet:
 * @snippet LocationWindowCameraExample.m objc_LocationWindow_moveTo
 *
 *
 */
- (void)moveTo:(nonnull NCCamera *)camera
      duration:(int32_t)duration
 animationType:(NCAnimationType)animationType
      callback:(nullable NCCameraCallback)callback;

/**
 *
 * @brief Selects a map feature by its feature ID.
 * @param featureId The feature ID from the mapFeaturePickResult @see PickListener "PickListener".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_selectMapFeature
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_selectMapFeature
 *
 *
 */
- (BOOL)selectMapFeature:(nonnull NSString *)featureId;

/**
 *
 * @brief Deselects a map feature by its feature ID.
 * @param featureId The feature ID from the mapFeaturePickResult @see PickListener "PickListener".
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_deselectMapFeature
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_deselectMapFeature
 *
 *
 */
- (BOOL)deselectMapFeature:(nonnull NSString *)featureId;

/**
 *
 * @brief Deselects all currently selected map features.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_deselectAllMapFeatures
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_deselectAllMapFeatures
 *
 *
 */
- (void)deselectAllMapFeatures;

/**
 *
 * @brief Applies a filter to a specific map layer.
 * @param filter The filter stringю
 * @param layer The map layer to apply the filter to.
 *
 */
- (void)applyFilter:(nonnull NSString *)filter
              layer:(nonnull NSString *)layer;

/**
 *
 * @brief Sets the state of a debug flag.
 * @param flag The debug flag to set @see DebugFlag "DebugFlag".
 * @param on Specifies whether the debug flag is enabled (true) or disabled (false).
 *
 */
+ (void)setDebugFlag:(NCDebugFlag)flag
                  on:(BOOL)on;

/**
 *
 * @brief Gets the state of a debug flag.
 * @param flag The debug flag to query @see DebugFlag "DebugFlag".
 * @return true if the debug flag is enabled, false otherwise.
 *
 */
+ (BOOL)getDebugFlag:(NCDebugFlag)flag;

/**
 *
 * @brief Specifies the zoom level of the location view, in pixels per meter.
 * Default: approximately 100 meters across the screen width.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_setZoomFactor
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_setZoomFactor
 *
 *
 */
@property (nonatomic) float zoomFactor;

/**
 *
 * @brief Minimum zoom level for the location view (pixels per meter).
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_setMinZoomFactor
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_setMinZoomFactor
 *
 *
 */
@property (nonatomic) float minZoomFactor;

/**
 *
 * @brief Maximum zoom level for the location view (pixels per meter).
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_setMaxZoomFactor
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_setMaxZoomFactor
 *
 *
 */
@property (nonatomic) float maxZoomFactor;

/**
 *
 * @brief Specifies whether sublocation content sticks to screen borders.
 * If true, content sticks to screen bounds; if false, content is centered. Default: true.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setStickToBorder
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setStickToBorder
 *
 *
 */
@property (nonatomic) BOOL stickToBorder;

/**
 *
 * @brief Current camera position in meters.
 * @see Camera "Camera".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCameraExample.swift swift_LocationWindow_setCamera
 *
 * Objective C code snippet:
 * @snippet LocationWindowCameraExample.m objc_LocationWindow_setCamera
 *
 *
 */
@property (nonatomic, nonnull) NCCamera * camera;

/**
 *
 * @brief Specifies whether rotation gestures (e.g., two-finger rotation) are enabled.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setRotateGestureEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setRotateGestureEnabled
 *
 *
 */
@property (nonatomic) BOOL rotateGestureEnabled;

/**
 *
 * @brief Specifies whether tilt gestures (e.g., two-finger parallel pan) are enabled.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setTiltGesturesEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setTiltGesturesEnabled
 *
 *
 */
@property (nonatomic) BOOL tiltGesturesEnabled;

/**
 *
 * @brief Specifies whether scroll gestures (e.g., pan gesture) are enabled.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setScrollGesturesEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setScrollGesturesEnabled
 *
 *
 */
@property (nonatomic) BOOL scrollGesturesEnabled;

/**
 *
 * @brief Specifies whether zoom gestures (e.g., two-finger pinch) are enabled.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setZoomGesturesEnabled
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setZoomGesturesEnabled
 *
 *
 */
@property (nonatomic) BOOL zoomGesturesEnabled;

/**
 *
 * @brief Radius for picking features on the map, in density-independent pixels.
 * Default: 0.5 dp.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_LocationWindow_setPickRadius
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_LocationWindow_setPickRadius
 *
 *
 */
@property (nonatomic) float pickRadius;

/**
 *
 * @brief List of currently selected map feature IDs.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_LocationWindow_getSelectedMapFeatures
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_LocationWindow_getSelectedMapFeatures
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NSString *> * selectedMapFeatures;

@end
