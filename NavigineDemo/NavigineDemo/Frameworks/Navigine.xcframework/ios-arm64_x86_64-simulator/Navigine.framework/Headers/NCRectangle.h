#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * A rectangle with specified origin and size.
 *
 * @discussion Example:
 * @code
 * // Create rectangle with x, y, width, height
 * NCRectangle *rect1 = [[NCRectangle alloc] initWithX:10 y:20 width:100 height:150];
 * NSLog(@"Created rectangle: x=%d, y=%d, width=%d, height=%d", rect1.x, rect1.y, rect1.width, rect1.height);
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRectangle : NSObject

/** 
 * Default constructor for class NCRectangle 
 */
- (nonnull instancetype)initWithX:(int32_t)x
                                y:(int32_t)y
                            width:(int32_t)width
                           height:(int32_t)height;

/** 
 * Factory method for class NCRectangle 
 */
+ (nonnull instancetype)rectangleWithX:(int32_t)x
                                     y:(int32_t)y
                                 width:(int32_t)width
                                height:(int32_t)height;

/**
 * rectangle's origin `x` coordinate.
 */
@property (nonatomic, readonly) int32_t x;

/**
 * rectangle's origin `y` coordinate.
 */
@property (nonatomic, readonly) int32_t y;

/**
 * rectangle's width.
 */
@property (nonatomic, readonly) int32_t width;

/**
 * rectangle's height.
 */
@property (nonatomic, readonly) int32_t height;

@end
