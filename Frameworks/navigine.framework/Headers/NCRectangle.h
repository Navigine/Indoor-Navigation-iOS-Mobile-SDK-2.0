#import <Foundation/Foundation.h>

@interface NCRectangle : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                            width:(float)width
                           height:(float)height;
+ (nonnull instancetype)rectangleWithX:(float)x
                                     y:(float)y
                                 width:(float)width
                                height:(float)height;

@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;

@property (nonatomic, readonly) float width;

@property (nonatomic, readonly) float height;

@end
