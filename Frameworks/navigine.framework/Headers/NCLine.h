#import "NCSegment.h"
#import <Foundation/Foundation.h>

@interface NCLine : NSObject
- (nonnull instancetype)initWithSegments:(nonnull NSArray<NCSegment *> *)segments;
+ (nonnull instancetype)lineWithSegments:(nonnull NSArray<NCSegment *> *)segments;

@property (nonatomic, readonly, nonnull) NSArray<NCSegment *> * segments;

@end
