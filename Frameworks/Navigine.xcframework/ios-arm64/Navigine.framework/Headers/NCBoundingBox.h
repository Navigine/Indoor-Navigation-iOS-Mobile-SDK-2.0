#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * Axis-aligned bounding box defined by two corner points.
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
- (nonnull instancetype)initWithBottomLeft:(nonnull NCPoint *)bottomLeft
                                  topRight:(nonnull NCPoint *)topRight;

/** 
 * Factory method for class NCBoundingBox 
 */
+ (nonnull instancetype)boundingBoxWithBottomLeft:(nonnull NCPoint *)bottomLeft
                                         topRight:(nonnull NCPoint *)topRight;

/**
 * Lower-left corner of the bounding box.
 *
 * @discussion Example:
 * @code
 * NCPoint *leftCorner = boundingBox.bottomLeft;
 * NSLog(@"Bottom-left corner: (%.1f, %.1f)", leftCorner.x, leftCorner.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCPoint * bottomLeft;

/**
 * Upper-right corner of the bounding box.
 *
 * @discussion Example:
 * @code
 * NCPoint *rightCorner = boundingBox.topRight;
 * NSLog(@"Top-right corner: (%.1f, %.1f)", rightCorner.x, rightCorner.y);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCPoint * topRight;

@end
