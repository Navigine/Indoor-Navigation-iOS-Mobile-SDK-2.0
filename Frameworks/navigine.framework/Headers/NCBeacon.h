#import "NCPoint.h"
#import <Foundation/Foundation.h>


@interface NCBeacon : NSObject

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, readonly) int32_t major;

@property (nonatomic, readonly) int32_t minor;

@property (nonatomic, nonnull, readonly) NSString * uuid;

@property (nonatomic, readonly) int32_t power;

@end