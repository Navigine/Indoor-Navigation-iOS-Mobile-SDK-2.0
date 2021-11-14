#import "NCExport.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCGraphEdge : NSObject

@property (nonatomic, readonly) float weight;

@property (nonatomic, readonly) int32_t dst;

@property (nonatomic, readonly) int32_t src;

@property (nonatomic, readonly) int32_t weightCoef;

@end
