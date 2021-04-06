#import <Foundation/Foundation.h>

@interface NCPoint : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y;
+ (nonnull instancetype)pointWithX:(float)x
                                 y:(float)y;

@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;

@end
