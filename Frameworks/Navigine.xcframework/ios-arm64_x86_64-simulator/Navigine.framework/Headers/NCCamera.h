#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCCamera.h
 * @brief @copybrief NCCamera
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class describing position of the camera.
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowCameraExample.swift swift_Camera_constructor
 *
 *Objective C code snippet:
 *@snippet LocationWindowCameraExample.m objc_Camera_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCamera : NSObject

/** 
 * @brief Default constructor for class NCCamera 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                                 zoom:(float)zoom
                             rotation:(float)rotation
                                 tilt:(float)tilt;

/** 
 * @brief Factory method for class NCCamera 
 */
+ (nonnull instancetype)cameraWithPoint:(nonnull NCPoint *)point
                                   zoom:(float)zoom
                               rotation:(float)rotation
                                   tilt:(float)tilt;

/**
 * @brief point the camera is looking at @see Point "Point"
 */
@property (nonatomic, readonly, nonnull) NCPoint * point;

/**
 * @brief zoom level.
 */
@property (nonatomic, readonly) float zoom;

/**
 * @brief Map azimuth in degrees: angle between `Location North` (top of the image) and the direction of interest
 * on the view plane, in the range [0, 360).
 */
@property (nonatomic, readonly) float rotation;

/**
 * @brief Camera tilt in degrees. 0 means vertical downward (map seen from above).
 * Positive values tilt the eye toward the horizon; the renderer clamps tilt to device limits when applying.
 */
@property (nonatomic, readonly) float tilt;

@end
