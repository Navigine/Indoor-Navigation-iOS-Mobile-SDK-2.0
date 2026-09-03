#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Axis-aligned bounding box defined by two WGS84 corners.
 *
 * @discussion Example:
 * @code
 * NCBoundingBox *boundingBox = [[NCBoundingBox alloc] initWithBottomLeft:bottomLeft topRight:topRight];
 * NSLog(@"Created bounding box: bottomLeft(%.1f, %.1f), topRight(%.1f, %.1f)",
 *      boundingBox.bottomLeft.x, boundingBox.bottomLeft.y,
 *      boundingBox.topRight.x, boundingBox.topRight.y);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBoundingBox : NSObject

/** 
 * Default constructor for class NCBoundingBox 
 */
- (nonnull instancetype)initWithBottomLeft:(nonnull NCGlobalPoint *)bottomLeft
                                  topRight:(nonnull NCGlobalPoint *)topRight;

/** 
 * Factory method for class NCBoundingBox 
 */
+ (nonnull instancetype)boundingBoxWithBottomLeft:(nonnull NCGlobalPoint *)bottomLeft
                                         topRight:(nonnull NCGlobalPoint *)topRight;

/**
 * Lower-left corner of the bounding box ``NCGlobalPoint``.
 *
 * @discussion Example:
 * @code
 * NCPoint *leftCorner = boundingBox.bottomLeft;
 * NSLog(@"Bottom-left corner: (%.1f, %.1f)", leftCorner.x, leftCorner.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * bottomLeft;

/**
 * Upper-right corner of the bounding box ``NCGlobalPoint``.
 *
 * @discussion Example:
 * @code
 * NCPoint *rightCorner = boundingBox.topRight;
 * NSLog(@"Top-right corner: (%.1f, %.1f)", rightCorner.x, rightCorner.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * topRight;

@end
