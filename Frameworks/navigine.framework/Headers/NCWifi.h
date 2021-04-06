#import "NCPoint.h"
#import <Foundation/Foundation.h>


@interface NCWifi : NSObject

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, nonnull, readonly) NSString * mac;

@end
