#import "NCMapObjectType.h"
#import <Foundation/Foundation.h>

@interface NCMapObjectData : NSObject
- (nonnull instancetype)initWithId:(nonnull NSString *)id
                     sublocationId:(int32_t)sublocationId
                              type:(NCMapObjectType)type
                       extraValues:(nonnull NSDictionary<NSString *, NSString *> *)extraValues;
+ (nonnull instancetype)mapObjectDataWithId:(nonnull NSString *)id
                              sublocationId:(int32_t)sublocationId
                                       type:(NCMapObjectType)type
                                extraValues:(nonnull NSDictionary<NSString *, NSString *> *)extraValues;

@property (nonatomic, readonly, nonnull) NSString * id;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, readonly) NCMapObjectType type;

@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> * extraValues;

@end
