#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * General information about location
 * Referenced from: ``NCLocationListListener``, ``NCLocationListListener``
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationInfo : NSObject

/** 
 * Default constructor for class NCLocationInfo 
 */
- (nonnull instancetype)initWithId:(int32_t)id
                           version:(int32_t)version
                              name:(nonnull NSString *)name;

/** 
 * Factory method for class NCLocationInfo 
 */
+ (nonnull instancetype)locationInfoWithId:(int32_t)id
                                   version:(int32_t)version
                                      name:(nonnull NSString *)name;

/**
 * Unique location identifier.
 *
 * @discussion Example:
 * @code
 * // Get location ID
 * int32_t id = locationInfo.id;
 * NSLog(@"Location ID: %d", id);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * Current location version.
 *
 * @discussion Example:
 * @code
 * // Get location version
 * int32_t version = locationInfo.version;
 * NSLog(@"Location version: %d", version);
 * @endcode
 */
@property (nonatomic, readonly) int32_t version;

/**
 * location name.
 *
 * @discussion Example:
 * @code
 * // Get location name
 * NSString *name = locationInfo.name;
 * NSLog(@"Location name: %@", name);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSString * name;

@end
