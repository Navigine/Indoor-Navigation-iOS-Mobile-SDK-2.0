#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 *
 * A rectangle with specified origin and size.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRectangle : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                            width:(float)width
                           height:(float)height;
+ (nonnull instancetype)rectangleWithX:(float)x
                                     y:(float)y
                                 width:(float)width
                                height:(float)height;

/**
 *
 * Rectangle's origin `x` coordinate.
 *
 */
@property (nonatomic, readonly) float x;

/**
 *
 * Rectangle's origin `y` coordinate.
 *
 */
@property (nonatomic, readonly) float y;

/**
 *
 * Rectangle's width.
 *
 */
@property (nonatomic, readonly) float width;

/**
 *
 * Rectangle's height.
 *
 */
@property (nonatomic, readonly) float height;

@end
