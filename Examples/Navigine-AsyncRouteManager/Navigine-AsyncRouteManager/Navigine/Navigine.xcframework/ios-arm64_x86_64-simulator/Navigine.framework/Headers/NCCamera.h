#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/** Class describing position of the camera. */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCamera : NSObject
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                                 zoom:(float)zoom
                             rotation:(float)rotation;
+ (nonnull instancetype)cameraWithPoint:(nonnull NCPoint *)point
                                   zoom:(float)zoom
                               rotation:(float)rotation;

/** Point the camera is looking at. */
@property (nonatomic, readonly, nonnull) NCPoint * point;

/** Zoom level. */
@property (nonatomic, readonly) float zoom;

/** Angle between `Location North` (top of the image) and the direction of interest on the view plane, in degrees in the range [0, 360). */
@property (nonatomic, readonly) float rotation;

@end
