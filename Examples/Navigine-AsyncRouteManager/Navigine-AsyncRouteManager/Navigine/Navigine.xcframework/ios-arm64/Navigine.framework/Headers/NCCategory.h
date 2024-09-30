#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 *
 * Object describing category in CMS
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCategory : NSObject
- (nonnull instancetype)initWithId:(int32_t)id
                              name:(nonnull NSString *)name
                          imageUrl:(nullable NSString *)imageUrl;
+ (nonnull instancetype)categoryWithId:(int32_t)id
                                  name:(nonnull NSString *)name
                              imageUrl:(nullable NSString *)imageUrl;

/** Category unique identifier */
@property (nonatomic, readonly) int32_t id;

/** Category name */
@property (nonatomic, readonly, nonnull) NSString * name;

/** Category image source. If presented. */
@property (nonatomic, readonly, nullable) NSString * imageUrl;

@end
