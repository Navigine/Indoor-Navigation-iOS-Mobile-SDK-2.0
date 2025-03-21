#import "NCExport.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCVector3d : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                                z:(float)z;
+ (nonnull instancetype)vector3dWithX:(float)x
                                    y:(float)y
                                    z:(float)z;

@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;

@property (nonatomic, readonly) float z;

- (NSComparisonResult)compare:(nonnull NCVector3d *)other;

@end
