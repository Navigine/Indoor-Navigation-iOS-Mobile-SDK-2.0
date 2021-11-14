#import "NCExport.h"
#import <Foundation/Foundation.h>

NAVIGINE_EXPORT
@interface NCLocationInfo : NSObject
- (nonnull instancetype)initWithId:(int32_t)id
                           version:(int32_t)version
                              name:(nonnull NSString *)name;
+ (nonnull instancetype)locationInfoWithId:(int32_t)id
                                   version:(int32_t)version
                                      name:(nonnull NSString *)name;

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, readonly) int32_t version;

@property (nonatomic, readonly, nonnull) NSString * name;

@end
