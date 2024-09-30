#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 *
 * A point at the specified WGS84 coordinates.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGlobalPoint : NSObject
- (nonnull instancetype)initWithLatitude:(double)latitude
                               longitude:(double)longitude;
+ (nonnull instancetype)globalPointWithLatitude:(double)latitude
                                      longitude:(double)longitude;

/** Point's latitude. */
@property (nonatomic, readonly) double latitude;

/** Point's g. */
@property (nonatomic, readonly) double longitude;

@end
