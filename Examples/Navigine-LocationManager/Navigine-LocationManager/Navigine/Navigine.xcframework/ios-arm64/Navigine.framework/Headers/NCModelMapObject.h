#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCMapObject.h"
#import "NCModelProvider.h"
#import <Foundation/Foundation.h>


/**
 * A 3D model map object (Wavefront OBJ) placed on the location view.
 * Geometry and texture come from ``NCModelProvider``. The mesh is loaded asynchronously in the render pipeline; blocking calls occur only inside provider callbacks.
 * Referenced from ``NCLocationWindow`` (addModelMapObject).
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCModelMapObject : NCMapObject

/**
 * Sets the anchor position of the model in WGS84 coordinates.
 * @param point Center / placement point ``NCGlobalPoint``.
 * @param sublocationId Floor this object is attached to, or null for the outdoor map.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * NCGlobalPoint *modelPoint = [[NCGlobalPoint alloc] initWithLatitude:12.0 longitude:34.0];
 * BOOL posOk = [modelObject setPosition:modelPoint sublocationId:@(7)];
 * NSLog(@"Model setPosition: %@", posOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPosition:(nonnull NCGlobalPoint *)point
      sublocationId:(nullable NSNumber *)sublocationId;

/**
 * Animates the model anchor to a new position.
 * @param point Target WGS84 coordinates ``NCGlobalPoint``.
 * @param sublocationId Floor this object is attached to, or null for the outdoor map.
 * @param duration Animation duration in seconds.
 * @param type Animation easing ``NCAnimationType``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * NCGlobalPoint *animatedModelPoint = [[NCGlobalPoint alloc] initWithLatitude:15.0 longitude:40.0];
 * BOOL posAnimOk = [modelObject setPositionAnimated:animatedModelPoint duration:0.5 animationType:AnimationTypeSine];
 * NSLog(@"Model setPositionAnimated: %@", posAnimOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPositionAnimated:(nonnull NCGlobalPoint *)point
              sublocationId:(nullable NSNumber *)sublocationId
                   duration:(float)duration
                       type:(NCAnimationType)type;

/**
 * Sets the 3D asset (OBJ source + texture ImageProvider).
 * @param model Model provider ``NCModelProvider``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * UIImage *texture = [UIImage imageWithContentsOfFile:@"/path/to/model_texture.png"];
 * if (texture != nil) {
 *    id<NCModelProvider> provider = [NCModelProviderFactory fromFile:@"/path/to/model.obj" texture:texture];
 *    BOOL modelOk = [modelObject setModel:provider];
 *    NSLog(@"Model setModel: %@", modelOk ? @"YES" : @"NO");
 * }
 * @endcode
 */
- (BOOL)setModel:(nullable id<NCModelProvider>)model;

/**
 * Sets the on-screen size of the model in pixels (width and height).
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL sizeOk = [modelObject setSizeWithWidth:64.0 height:64.0];
 * NSLog(@"Model setSize: %@", sizeOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setSize:(float)width
         height:(float)height;

/**
 * Enables or disables collision tests for this object.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL collOk = [modelObject setCollisionEnabled:YES];
 * NSLog(@"Model setCollisionEnabled: %@", collOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setCollisionEnabled:(BOOL)enabled;

/**
 * Sets rotation angle in radians (around the placement axis used by the engine).
 * @param angle Rotation angle in radians. Default: 0.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL angleOk = [modelObject setAngle:(float)(M_PI / 4.0)];
 * NSLog(@"Model setAngle: %@", angleOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAngle:(float)angle;

/**
 * Animates rotation to the given angle in radians.
 * @param angle Rotation angle in radians.
 * @param duration Animation duration in seconds.
 * @param type Animation type ``NCAnimationType``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL angleAnimOk = [modelObject setAngleAnimated:(float)(M_PI / 2.0) duration:0.5 animationType:AnimationTypeQuint];
 * NSLog(@"Model setAngleAnimated: %@", angleAnimOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAngleAnimated:(float)angle
                duration:(float)duration
                    type:(NCAnimationType)type;

/**
 * Extra hit-test padding around the model in pixels.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL bufOk = [modelObject setBufferWithWidth:4.0 height:4.0];
 * NSLog(@"Model setBuffer: %@", bufOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setBuffer:(float)width
           height:(float)height;

/**
 * Render order priority (higher draws above).
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL priOk = [modelObject setPriority:10.0];
 * NSLog(@"Model setPriority: %@", priOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPriority:(float)priority;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
