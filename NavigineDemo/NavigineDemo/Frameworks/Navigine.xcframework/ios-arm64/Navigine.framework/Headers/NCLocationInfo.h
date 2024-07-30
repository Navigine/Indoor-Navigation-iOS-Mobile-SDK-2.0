#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 *
 * General information about location
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationInfo : NSObject
- (nonnull instancetype)initWithId:(int32_t)id
                           version:(int32_t)version
                              name:(nonnull NSString *)name;
+ (nonnull instancetype)locationInfoWithId:(int32_t)id
                                   version:(int32_t)version
                                      name:(nonnull NSString *)name;

/** Unique location identifier. */
@property (nonatomic, readonly) int32_t id;

/** Current location version. */
@property (nonatomic, readonly) int32_t version;

/** Location name. */
@property (nonatomic, readonly, nonnull) NSString * name;

@end
