#import <Foundation/Foundation.h>

@interface NCGlobalPoint : NSObject
- (nonnull instancetype)initWithLatitude:(float)latitude
                               longitude:(float)longitude;
+ (nonnull instancetype)globalPointWithLatitude:(float)latitude
                                      longitude:(float)longitude;

@property (nonatomic, readonly) float latitude;

@property (nonatomic, readonly) float longitude;

@end