#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Trapezoid of the current viewport on the ground, in WGS84.
 * With tilt the shape is not a rectangle: near edge is closer to the camera.
 * Corners are ray-cast onto the ground plane, same as
 * ``NCLocationWindow`` `screenPositionToGlobal`.
 * Referenced from ``NCLocationWindow`` `visibleRegion`.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVisibleRegion : NSObject

/** 
 * Default constructor for class NCVisibleRegion 
 */
- (nonnull instancetype)initWithTopLeft:(nonnull NCGlobalPoint *)topLeft
                               topRight:(nonnull NCGlobalPoint *)topRight
                             bottomLeft:(nonnull NCGlobalPoint *)bottomLeft
                            bottomRight:(nonnull NCGlobalPoint *)bottomRight;

/** 
 * Factory method for class NCVisibleRegion 
 */
+ (nonnull instancetype)visibleRegionWithTopLeft:(nonnull NCGlobalPoint *)topLeft
                                        topRight:(nonnull NCGlobalPoint *)topRight
                                      bottomLeft:(nonnull NCGlobalPoint *)bottomLeft
                                     bottomRight:(nonnull NCGlobalPoint *)bottomRight;

/**
 * Top-left screen corner ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * topLeft;

/**
 * Top-right screen corner ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * topRight;

/**
 * Bottom-left screen corner ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * bottomLeft;

/**
 * Bottom-right screen corner ``NCGlobalPoint``.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * bottomRight;

@end
