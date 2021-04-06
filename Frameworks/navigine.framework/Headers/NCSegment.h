#import "NCPoint.h"
#import <Foundation/Foundation.h>

@interface NCSegment : NSObject
- (nonnull instancetype)initWithStart:(nonnull NCPoint *)start
                                  end:(nonnull NCPoint *)end;
+ (nonnull instancetype)segmentWithStart:(nonnull NCPoint *)start
                                     end:(nonnull NCPoint *)end;

@property (nonatomic, readonly, nonnull) NCPoint * start;

@property (nonatomic, readonly, nonnull) NCPoint * end;

@end
