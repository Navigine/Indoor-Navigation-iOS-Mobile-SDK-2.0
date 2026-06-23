#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * Class describing position of the camera.
 * Referenced from ``NCLocationWindow``.
 *
 * @discussion Example:
 * @code
 * // Create camera with constructor
 * NCPoint *newPoint = [[NCPoint alloc] initWithX:100.0 y:200.0];
 * NCCamera *newCamera = [[NCCamera alloc] initWithPoint:newPoint zoom:50.0 rotation:0.0 tilt:0.0];
 * NSLog(@"Created camera with point (%.2f, %.2f), zoom 50.0, rotation 0°, tilt 0°", newPoint.x, newPoint.y);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCamera : NSObject

/** 
 * Default constructor for class NCCamera 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                                 zoom:(float)zoom
                             rotation:(float)rotation
                                 tilt:(float)tilt;

/** 
 * Factory method for class NCCamera 
 */
+ (nonnull instancetype)cameraWithPoint:(nonnull NCPoint *)point
                                   zoom:(float)zoom
                               rotation:(float)rotation
                                   tilt:(float)tilt;

/**
 * point the camera is looking at ``NCPoint``
 */
@property (nonatomic, readonly, nonnull) NCPoint * point;

/**
 * zoom level.
 */
@property (nonatomic, readonly) float zoom;

/**
 * Map azimuth in degrees: angle between `Location North` (top of the image) and the direction of interest
 * on the view plane, in the range [0, 360).
 */
@property (nonatomic, readonly) float rotation;

/**
 * Camera tilt in degrees. 0 means vertical downward (map seen from above).
 * Positive values tilt the eye toward the horizon; the renderer clamps tilt to device limits when applying.
 */
@property (nonatomic, readonly) float tilt;

@end
