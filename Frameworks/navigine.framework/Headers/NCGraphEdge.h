#import <Foundation/Foundation.h>


@interface NCGraphEdge : NSObject

@property (nonatomic, readonly) float weight;

@property (nonatomic, readonly) int32_t dst;

@property (nonatomic, readonly) int32_t src;

@property (nonatomic, readonly) int32_t weightCoef;

@end
