#import "NCAnimationType.h"
#import "NCBoundingBox.h"
#import "NCCamera.h"
#import "NCCameraCallback.h"
#import "NCDebugFlag.h"
#import "NCExport.h"
#import "NCMapFilterCondition.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCCircleMapObject;
@class NCClusterMapObjectController;
@class NCDottedPolylineMapObject;
@class NCIconMapObject;
@class NCModelMapObject;
@class NCPolygonMapObject;
@class NCPolylineMapObject;
@protocol NCBuildingListener;
@protocol NCCameraListener;
@protocol NCInputListener;
@protocol NCPickListener;
@protocol NCSublocationChangeListener;


/**
 * Interface for interacting with the location view.
 * Referenced from ``NCLocationView``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationWindow : NSObject

/**
 * Method is used to switch the location view between sublocations (e.g., floors).
 * @param id Sublocation unique identifier ``NCSublocation``.
 *
 * @discussion Example:
 * @code
 * // Set sublocation ID to switch between floors
 * [_locationWindow setSublocationId:1];
 * NSLog(@"Set sublocation ID to 1 (first floor)");
 * @endcode
 */
- (void)setSublocationId:(int32_t)id;

/**
 * Returns current sublocation ID if set, otherwise null.
 *
 * @discussion Example:
 * @code
 * NSNumber *currentId = [_locationWindow getSublocationId];
 * if (currentId != nil) {
 *    NSLog(@"Current sublocation id: %@", currentId);
 * } else {
 *    NSLog(@"Current sublocation id is not set");
 * }
 * @endcode
 */
- (nullable NSNumber *)getSublocationId;

/**
 * Calculates camera that fits provided bounding box.
 * @param boundingBox Metrics bounding box to enclose.
 *
 * @discussion Example:
 * @code
 * NCBoundingBox *boundingBox = [[NCBoundingBox alloc] initWithBottomLeft:[[NCPoint alloc] initWithX:0.0 y:0.0]
 *                                                              topRight:[[NCPoint alloc] initWithX:20.0 y:30.0]];
 * NCCamera *camera = [_locationWindow getEnclosingCamera:boundingBox];
 * NSLog(@"Camera that fits bounding box: %@", camera);
 * @endcode
 */
- (nonnull NCCamera *)getEnclosingCamera:(nonnull NCBoundingBox *)boundingBox;

/**
 * Converts screen coordinates (pixels) to metrics coordinates (meters).
 * @param point (x,y) coordinates in screen pixels.
 * @return (x,y) coordinates in meters ``NCPoint``.
 *
 * @discussion Example:
 * @code
 * // Convert screen position to meters
 * NCPoint *screenPoint = [[NCPoint alloc] initWithX:100.0 y:200.0];
 * NCPoint *metersPoint = [_locationWindow screenPositionToMeters:screenPoint];
 * NSLog(@"Screen position (%.1f, %.1f) converted to meters: (%.1f, %.1f)",
 *      screenPoint.x, screenPoint.y, metersPoint.x, metersPoint.y);
 * @endcode
 */
- (nonnull NCPoint *)screenPositionToMeters:(CGPoint)point;

/**
 * Converts metrics coordinates (meters) to screen coordinates (pixels).
 * @param point (x,y) coordinates in meters ``NCPoint``.
 * @param clipToViewport If true, coordinates outside the viewport are clipped to the viewport edge.
 * @return (x,y) coordinates in screen pixels.
 *
 * @discussion Example:
 * @code
 * // Convert meters to screen position with clipping
 * NCPoint *metersPoint3 = [[NCPoint alloc] initWithX:50.0 y:75.0];
 * NCPoint *screenPoint3 = [_locationWindow metersToScreenPosition:metersPoint3 clipToViewport:YES];
 * NSLog(@"Meters position (%.1f, %.1f) converted to screen with clipping: (%.1f, %.1f)",
 *      metersPoint3.x, metersPoint3.y, screenPoint3.x, screenPoint3.y);
 * @endcode
 */
- (CGPoint)metersToScreenPosition:(nonnull NCPoint *)point
                   clipToViewport:(BOOL)clipToViewport;

/**
 * Creates and adds a circle map object to the location view.
 * @return A CircleMapObject instance ``NCCircleMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * // Add circle map object
 * [_locationWindow addCircleMapObject:circleObject];
 * [_mapObjects addObject:circleObject];
 * NSLog(@"Added circle map object");
 * @endcode
 */
- (nullable NCCircleMapObject *)addCircleMapObject;

/**
 * Removes a circle map object from the location view.
 * @param circleMapObject The circle map object instance ``NCCircleMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Remove circle map object
 * [_locationWindow removeCircleMapObject:circleObject];
 * [_mapObjects removeObject:circleObject];
 * NSLog(@"Removed circle map object");
 * @endcode
 */
- (BOOL)removeCircleMapObject:(nullable NCCircleMapObject *)circleMapObject;

/**
 * Creates and adds an icon map object to the location view.
 * @return An IconMapObject instance ``NCIconMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * // Add icon map object
 * [_locationWindow addIconMapObject:iconObject];
 * [_mapObjects addObject:iconObject];
 * NSLog(@"Added icon map object");
 * @endcode
 */
- (nullable NCIconMapObject *)addIconMapObject;

/**
 * Removes an icon map object from the location view.
 * @param iconMapObject The icon map object instance ``NCIconMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Remove icon map object
 * [_locationWindow removeIconMapObject:iconObject];
 * [_mapObjects removeObject:iconObject];
 * NSLog(@"Removed icon map object");
 * @endcode
 */
- (BOOL)removeIconMapObject:(nullable NCIconMapObject *)iconMapObject;

/**
 * Creates an icon map object controller for the location view.
 * @return Cluster controller instance ``NCClusterMapObjectController``.
 *
 * @discussion Example:
 * @code
 * NCClusterMapObjectController *controller =
 *    [_locationWindow addClusterMapObjectController];
 * NSLog(@"Added cluster map object controller");
 * @endcode
 */
- (nullable NCClusterMapObjectController *)addClusterMapObjectController;

/**
 * Removes an icon map object controller from the location view.
 * @param controller The controller instance to remove.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL controllerRemoved =
 *    [_locationWindow removeClusterMapObjectController:controller];
 * NSLog(@"Removed cluster map object controller: %d", controllerRemoved);
 * @endcode
 */
- (BOOL)removeClusterMapObjectController:(nullable NCClusterMapObjectController *)controller;

/**
 * Creates and adds a polygon map object to the location view.
 * @return A PolygonMapObject instance ``NCPolygonMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * // Add polygon map object
 * NCPolygonMapObject *polygonObject = [_locationWindow addPolygonMapObject];
 * NSLog(@"Added polygon map object");
 * @endcode
 */
- (nullable NCPolygonMapObject *)addPolygonMapObject;

/**
 * Removes a polygon map object from the location view.
 * @param polygonMapObject The polygon map object instance ``NCPolygonMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Remove polygon map object
 * if (polygonObject != nil) {
 *    BOOL removed = [_locationWindow removePolygonMapObject:polygonObject];
 *    NSLog(@"Removed polygon map object: %@", removed ? @"YES" : @"NO");
 * }
 * @endcode
 */
- (BOOL)removePolygonMapObject:(nullable NCPolygonMapObject *)polygonMapObject;

/**
 * Creates and adds a polyline map object to the location view.
 * @return A PolylineMapObject instance ``NCPolylineMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * // Add polyline map object
 * [_locationWindow addPolylineMapObject:polylineObject];
 * [_mapObjects addObject:polylineObject];
 * NSLog(@"Added polyline map object");
 * @endcode
 */
- (nullable NCPolylineMapObject *)addPolylineMapObject;

/**
 * Removes a polyline map object from the location view.
 * @param polylineMapObject The polyline map object instance ``NCPolylineMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Remove polyline map object
 * [_locationWindow removePolylineMapObject:polylineObject];
 * [_mapObjects removeObject:polylineObject];
 * NSLog(@"Removed polyline map object");
 * @endcode
 */
- (BOOL)removePolylineMapObject:(nullable NCPolylineMapObject *)polylineMapObject;

/**
 * Creates and adds a polyline points map object to the location view.
 * @return A DottedPolylineMapObject instance ``NCDottedPolylineMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * // Add dotted polyline map object
 * [_locationWindow addDottedPolylineMapObject:dottedPolylineObject];
 * [_mapObjects addObject:dottedPolylineObject];
 * NSLog(@"Added dotted polyline map object");
 * @endcode
 */
- (nullable NCDottedPolylineMapObject *)addDottedPolylineMapObject;

/**
 * Removes a polyline points map object from the location view.
 * @param dottedPolylineMapObject The polyline points map object instance ``NCDottedPolylineMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Remove dotted polyline map object
 * [_locationWindow removeDottedPolylineMapObject:dottedPolylineObject];
 * [_mapObjects removeObject:dottedPolylineObject];
 * NSLog(@"Removed dotted polyline map object");
 * @endcode
 */
- (BOOL)removeDottedPolylineMapObject:(nullable NCDottedPolylineMapObject *)dottedPolylineMapObject;

/**
 * Creates and adds a 3D model map object (Wavefront OBJ + texture via ModelProvider).
 * @return A ModelMapObject instance ``NCModelMapObject`` if successful, null otherwise.
 *
 * @discussion Example:
 * @code
 * NCModelMapObject *modelObject = [_locationWindow addModelMapObject];
 * NSLog(@"Added model map object: %@", modelObject != nil ? @"YES" : @"NO");
 * @endcode
 */
- (nullable NCModelMapObject *)addModelMapObject;

/**
 * Removes a model map object from the location view.
 * @param modelMapObject The model instance to remove ``NCModelMapObject``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL removed = [_locationWindow removeModelMapObject:modelObject];
 * NSLog(@"Removed model map object: %@", removed ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)removeModelMapObject:(nullable NCModelMapObject *)modelMapObject;

/**
 * Removes all map objects from the location view.
 *
 * @discussion Example:
 * @code
 * // Remove all map objects
 * [_locationWindow removeAllMapObjects];
 * [_mapObjects removeAllObjects];
 * NSLog(@"Removed all map objects");
 * @endcode
 */
- (void)removeAllMapObjects;

/**
 * Selects a visible, interactive map object at the specified screen position.
 * Results are delivered to the PickListener via onMapObjectPickComplete ``NCPickListener``.
 * @param point Position in screen pixels to pick from.
 *
 * @discussion Example:
 * @code
 * // Pick map object at screen position
 * NCPoint *screenPoint = [[NCPoint alloc] initWithX:100.0 y:200.0];
 * [_locationWindow pickMapObjectAt:screenPoint];
 * NSLog(@"Picked map object at screen position (%.1f, %.1f)", screenPoint.x, screenPoint.y);
 * @endcode
 */
- (void)pickMapObjectAt:(CGPoint)point;

/**
 * Selects visible map features (e.g., venues) at the specified screen position.
 * Results are delivered to the PickListener via onMapFeaturePickComplete ``NCPickListener``.
 * @param point Position in screen pixels to pick from.
 *
 * @discussion Example:
 * @code
 * // Pick map feature at screen position
 * NCPoint *featurePoint = [[NCPoint alloc] initWithX:150.0 y:250.0];
 * [_locationWindow pickMapFeatureAt:featurePoint];
 * NSLog(@"Picked map feature at screen position (%.1f, %.1f)", featurePoint.x, featurePoint.y);
 * @endcode
 */
- (void)pickMapFeatureAt:(CGPoint)point;

/**
 * Adds a PickListener to receive picking result events.
 * @param listener The PickListener instance ``NCPickListener``.
 * @discussion Note: Remove the listener when no longer needed.
 *
 * @discussion Example:
 * @code
 * // Add pick listener
 * _pickListener = [[PickListenerImpl alloc] init];
 * [_locationWindow addPickListener:_pickListener];
 * NSLog(@"Added pick listener");
 * @endcode
 */
- (void)addPickListener:(nullable id<NCPickListener>)listener;

/**
 * Removes a previously added PickListener.
 * @param listener The PickListener instance to remove ``NCPickListener``.
 *
 * @discussion Example:
 * @code
 * [_locationWindow removePickListener:listeners[i]];
 * NSLog(@"Removed pick listener %d", i);
 * @endcode
 */
- (void)removePickListener:(nullable id<NCPickListener>)listener;

/**
 * Adds an InputListener to receive input events.
 * @param listener The InputListener instance ``NCInputListener``.
 * @discussion Note: Remove the listener when no longer needed.
 *
 * @discussion Example:
 * @code
 * // Add input listener
 * _inputListener = [[InputListenerImpl alloc] init];
 * [_locationWindow addInputListener:_inputListener];
 * NSLog(@"Added input listener");
 * @endcode
 */
- (void)addInputListener:(nullable id<NCInputListener>)listener;

/**
 * Removes a previously added InputListener.
 * @param listener The InputListener instance to remove ``NCInputListener``.
 *
 * @discussion Example:
 * @code
 * // Remove input listener
 * [_locationWindow removeInputListener:_inputListener];
 * _inputListener = nil;
 * NSLog(@"Removed input listener");
 * @endcode
 */
- (void)removeInputListener:(nullable id<NCInputListener>)listener;

/**
 * Adds a CameraListener to receive camera movement events.
 * @param listener The CameraListener instance ``NCCameraListener``.
 * @discussion Note: Remove the listener when no longer needed.
 *
 * @discussion Example:
 * @code
 * // Add camera listener
 * _cameraListener = [[CameraListenerImpl alloc] init];
 * [_locationWindow addCameraListener:_cameraListener];
 * NSLog(@"Added camera listener");
 * @endcode
 */
- (void)addCameraListener:(nullable id<NCCameraListener>)listener;

/**
 * Removes a previously added CameraListener.
 * @param listener The CameraListener instance to remove ``NCCameraListener``.
 *
 * @discussion Example:
 * @code
 * // Remove camera listener
 * [_locationWindow removeCameraListener:_cameraListener];
 * _cameraListener = nil;
 * NSLog(@"Removed camera listener");
 * @endcode
 */
- (void)removeCameraListener:(nullable id<NCCameraListener>)listener;

/**
 * Adds listener for sublocation change events.
 * @param listener Sublocation change listener ``NCSublocationChangeListener``.
 *
 * @discussion Example:
 * @code
 * [_locationWindow addSublocationChangeListener:listener];
 * NSLog(@"Added sublocation change listener");
 * @endcode
 */
- (void)addSublocationChangeListener:(nullable id<NCSublocationChangeListener>)listener;

/**
 * Removes previously added sublocation change listener.
 * @param listener Listener instance to remove ``NCSublocationChangeListener``.
 *
 * @discussion Example:
 * @code
 * [_locationWindow removeSublocationChangeListener:listener];
 * NSLog(@"Removed sublocation change listener");
 * @endcode
 */
- (void)removeSublocationChangeListener:(nullable id<NCSublocationChangeListener>)listener;

/**
 * Adds listener for outdoor scenario: when camera focuses on a building or leaves it.
 * @param listener Indoor building listener ``NCBuildingListener``.
 *
 * @discussion Example:
 * @code
 * [_locationWindow addBuildingListener:_buildingListener];
 * NSLog(@"Added building listener");
 * @endcode
 */
- (void)addBuildingListener:(nullable id<NCBuildingListener>)listener;

/**
 * Removes previously added indoor building listener.
 * @param listener Listener instance to remove ``NCBuildingListener``.
 *
 * @discussion Example:
 * @code
 * [_locationWindow removeBuildingListener:_buildingListener];
 * NSLog(@"Removed building listener");
 * @endcode
 */
- (void)removeBuildingListener:(nullable id<NCBuildingListener>)listener;

/**
 * Moves the map camera to a new position with an easing animation.
 * @param camera The new camera position ``NCCamera``.
 * @param duration Animation duration in milliseconds.
 * @param callback Callback to execute when the animation completes ``NCCameraCallback``.
 *
 * @discussion Example:
 * @code
 * // Fly to position with smooth animation
 * NCPoint *targetPoint = [[NCPoint alloc] initWithX:150.0 y:250.0];
 * NCCamera *targetCamera = [[NCCamera alloc] initWithPoint:targetPoint zoom:75.0 rotation:45.0 tilt:30.0];
 * CameraCallbackImpl *callback = [[CameraCallbackImpl alloc] init];
 * [_locationWindow flyToWithCamera:targetCamera duration:2000 callback:callback];
 * NSLog(@"Started fly to animation to point (%.2f, %.2f)", targetPoint.x, targetPoint.y);
 * @endcode
 */
- (void)flyTo:(nonnull NCCamera *)camera
     duration:(int32_t)duration
     callback:(nullable NCCameraCallback)callback;

/**
 * Moves the map camera to a new position with a smooth pan-and-zoom animation.
 * @param camera The new camera position ``NCCamera``.
 * @param duration Animation duration in milliseconds (-1 for default duration).
 * @param animationType The type of easing animation ``NCAnimationType``.
 * @param callback Callback to execute when the animation completes ``NCCameraCallback``.
 *
 * @discussion Example:
 * @code
 * // Move to position with linear animation
 * NCPoint *targetPoint = [[NCPoint alloc] initWithX:200.0 y:300.0];
 * NCCamera *targetCamera = [[NCCamera alloc] initWithPoint:targetPoint zoom:100.0 rotation:90.0 tilt:0.0];
 * CameraCallbackImpl *callback = [[CameraCallbackImpl alloc] init];
 * [_locationWindow moveToWithCamera:targetCamera duration:1500 animationType:NCAnimationTypeLinear callback:callback];
 * NSLog(@"Started move to with linear animation");
 * @endcode
 */
- (void)moveTo:(nonnull NCCamera *)camera
      duration:(int32_t)duration
 animationType:(NCAnimationType)animationType
      callback:(nullable NCCameraCallback)callback;

/**
 * Selects a map feature by its feature ID.
 * @param featureId The feature ID from the mapFeaturePickResult ``NCPickListener``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Select map feature by ID
 * NSString *featureId = "room_101";
 * BOOL selected = [_locationWindow selectMapFeature:featureId];
 * NSLog(@"Selected map feature %@: %@", featureId, selected ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)selectMapFeature:(nonnull NSString *)featureId;

/**
 * Deselects a map feature by its feature ID.
 * @param featureId The feature ID from the mapFeaturePickResult ``NCPickListener``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Deselect specific map feature
 * BOOL deselected = [_locationWindow deselectMapFeature:featureId];
 * NSLog(@"Deselected map feature %@: %@", featureId, deselected ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)deselectMapFeature:(nonnull NSString *)featureId;

/**
 * Deselects all currently selected map features.
 *
 * @discussion Example:
 * @code
 * // Deselect all map features
 * [_locationWindow deselectAllMapFeatures];
 * NSLog(@"Deselected all map features");
 * @endcode
 */
- (void)deselectAllMapFeatures;

/**
 * Applies a typed filter to a specific map layer.
 * @param layer The map layer to apply the filter to.
 * @param conditions List of conditions (property + allowed values). Empty list resets the filter (show all).
 *
 * @discussion Example:
 * @code
 * // Apply filter to venues layer
 * NSArray<NCMapFilterCondition *> *conditions = @[[[NCMapFilterCondition alloc] initWithProperty:@"category" values:@[@"Toilet", @"Cafe"]]];
 * [_locationWindow applyLayerFilterWithLayer:@"venues" conditions:conditions];
 * NSLog(@"Applied layer filter: show venues with category Toilet or Cafe");
 * @endcode
 */
- (void)applyLayerFilter:(nonnull NSString *)layer
              conditions:(nonnull NSArray<NCMapFilterCondition *> *)conditions;

/**
 * Sets the state of a debug flag.
 * @param flag The debug flag to set ``NCDebugFlag``.
 * @param on Specifies whether the debug flag is enabled (true) or disabled (false).
 *
 * @discussion Example:
 * @code
 * [NCLocationWindow setDebugFlag:NCDebugFlagInfos on:YES];
 * [NCLocationWindow setDebugFlag:NCDebugFlagStats on:NO];
 * NSLog(@"Updated debug flags on LocationWindow");
 * @endcode
 */
+ (void)setDebugFlag:(NCDebugFlag)flag
                  on:(BOOL)on;

/**
 * Gets the state of a debug flag.
 * @param flag The debug flag to query ``NCDebugFlag``.
 * @return true if the debug flag is enabled, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL infosOn = [NCLocationWindow getDebugFlag:NCDebugFlagInfos];
 * NSLog(@"Debug flag INFOS enabled: %@", infosOn ? @"YES" : @"NO");
 * @endcode
 */
+ (BOOL)getDebugFlag:(NCDebugFlag)flag;

/**
 * Specifies the zoom level of the location view, in pixels per meter.
 * Default: approximately 100 meters across the screen width.
 *
 * @discussion Example:
 * @code
 * // Set zoom factor
 * [_locationWindow setZoomFactor:150.0];
 * NSLog(@"Set zoom factor to 150.0");
 * @endcode
 */
@property (nonatomic) float zoomFactor;

/**
 * Minimum zoom level for the location view (pixels per meter).
 *
 * @discussion Example:
 * @code
 * // Set minimum zoom factor
 * [_locationWindow setMinZoomFactor:50.0];
 * NSLog(@"Set minimum zoom factor to 50.0");
 * @endcode
 */
@property (nonatomic) float minZoomFactor;

/**
 * Maximum zoom level for the location view (pixels per meter).
 *
 * @discussion Example:
 * @code
 * // Set maximum zoom factor
 * [_locationWindow setMaxZoomFactor:300.0];
 * NSLog(@"Set maximum zoom factor to 300.0");
 * @endcode
 */
@property (nonatomic) float maxZoomFactor;

/**
 * Specifies whether sublocation content sticks to screen borders.
 * If true, content sticks to screen bounds; if false, content is centered. Default: true.
 *
 * @discussion Example:
 * @code
 * // Set stick to border property
 * _locationWindow.stickToBorder = YES;
 * NSLog(@"Set stick to border to true");
 * @endcode
 */
@property (nonatomic) BOOL stickToBorder;

/**
 * Current camera position in meters.
 * See also: ``NCCamera``.
 *
 * @discussion Example:
 * @code
 * // Set camera position without animation
 * _locationWindow.camera = newCamera;
 * NSLog(@"Set camera position to (%.2f, %.2f) with zoom 50.0, rotation 0°, tilt 0°", newPoint.x, newPoint.y);
 * @endcode
 */
@property (nonatomic, nonnull) NCCamera * camera;

/**
 * Specifies whether rotation gestures (e.g., two-finger rotation) are enabled.
 *
 * @discussion Example:
 * @code
 * // Set rotate gesture enabled
 * _locationWindow.rotateGestureEnabled = YES;
 * NSLog(@"Set rotate gesture enabled to true");
 * @endcode
 */
@property (nonatomic) BOOL rotateGestureEnabled;

/**
 * Specifies whether tilt gestures (e.g., two-finger parallel pan) are enabled.
 *
 * @discussion Example:
 * @code
 * // Set tilt gestures enabled
 * _locationWindow.tiltGesturesEnabled = YES;
 * NSLog(@"Set tilt gestures enabled to true");
 * @endcode
 */
@property (nonatomic) BOOL tiltGesturesEnabled;

/**
 * Specifies whether scroll gestures (e.g., pan gesture) are enabled.
 *
 * @discussion Example:
 * @code
 * // Set scroll gestures enabled
 * _locationWindow.scrollGesturesEnabled = YES;
 * NSLog(@"Set scroll gestures enabled to true");
 * @endcode
 */
@property (nonatomic) BOOL scrollGesturesEnabled;

/**
 * Specifies whether zoom gestures (e.g., two-finger pinch) are enabled.
 *
 * @discussion Example:
 * @code
 * // Set zoom gestures enabled
 * _locationWindow.zoomGesturesEnabled = YES;
 * NSLog(@"Set zoom gestures enabled to true");
 * @endcode
 */
@property (nonatomic) BOOL zoomGesturesEnabled;

/**
 * Radius for picking features on the map, in density-independent pixels.
 * Default: 0.5 dp.
 *
 * @discussion Example:
 * @code
 * // Set pick radius
 * _locationWindow.pickRadius = 10.0;
 * NSLog(@"Set pick radius to 10.0 pixels");
 * @endcode
 */
@property (nonatomic) float pickRadius;

/**
 * List of currently selected map feature IDs.
 *
 * @discussion Example:
 * @code
 * // Get list of selected map features
 * NSArray<NSString *> *selectedFeatures = [_locationWindow selectedMapFeatures];
 * NSLog(@"Currently selected map features: %lu features", (unsigned long)selectedFeatures.count);
 * for (NSString *feature in selectedFeatures) {
 *    NSLog(@"  - %@", feature);
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NSString *> * selectedMapFeatures;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
