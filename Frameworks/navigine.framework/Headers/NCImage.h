#import "NCImageType.h"
#import <Foundation/Foundation.h>


@interface NCImage : NSObject

@property (nonatomic, nonnull, readonly) NSData * data;

@property (nonatomic, readonly) int32_t width;

@property (nonatomic, readonly) int32_t height;

@property (nonatomic, readonly) NCImageType type;

@end
