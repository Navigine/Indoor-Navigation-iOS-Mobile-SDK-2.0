#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
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
 * Sets the anchor position of the model in metric coordinates.
 * @param point Center / placement point ``NCLocationPoint``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *modelPoint = [[NCLocationPoint alloc] initWithX:12.0 y:34.0];
 * BOOL posOk = [modelObject setPosition:modelPoint];
 * NSLog(@"Model setPosition: %@", posOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

/**
 * Animates the model anchor to a new position.
 * @param point Target metrics coordinates ``NCLocationPoint``.
 * @param duration Animation duration in seconds.
 * @param type Animation easing ``NCAnimationType``.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *animatedModelPoint = [[NCLocationPoint alloc] initWithX:15.0 y:40.0];
 * BOOL posAnimOk = [modelObject setPositionAnimated:animatedModelPoint duration:0.5 animationType:AnimationTypeSine];
 * NSLog(@"Model setPositionAnimated: %@", posAnimOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
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
 * Sets rotation angle in degrees (around the placement axis used by the engine).
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL angleOk = [modelObject setAngle:45.0];
 * NSLog(@"Model setAngle: %@", angleOk ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAngle:(float)angle;

/**
 * Animates rotation to the given angle.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * BOOL angleAnimOk = [modelObject setAngleAnimated:90.0 duration:0.5 animationType:AnimationTypeQuint];
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
