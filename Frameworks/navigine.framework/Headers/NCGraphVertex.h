#import "NCPoint.h"
#import <Foundation/Foundation.h>


@interface NCGraphVertex : NSObject

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, readonly) BOOL isExternal;

@property (nonatomic, readonly) BOOL isElevation;

@end
