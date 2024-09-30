#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 *
 * A point at the specified metrics coordinates.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPoint : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y;
+ (nonnull instancetype)pointWithX:(float)x
                                 y:(float)y;

/** Point's `x` coordinate in meters. */
@property (nonatomic, readonly) float x;

/** Point's `y` coordinate in meters. */
@property (nonatomic, readonly) float y;

@end
