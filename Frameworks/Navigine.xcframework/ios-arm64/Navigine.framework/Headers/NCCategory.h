#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * class is used for storing venue categories.
 * Referenced from ``NCLocation`` ``NCVenue``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCategory : NSObject

/** 
 * Default constructor for class NCCategory 
 */
- (nonnull instancetype)initWithId:(int32_t)id
                              name:(nonnull NSString *)name
                          imageUrl:(nullable NSString *)imageUrl;

/** 
 * Factory method for class NCCategory 
 */
+ (nonnull instancetype)categoryWithId:(int32_t)id
                                  name:(nonnull NSString *)name
                              imageUrl:(nullable NSString *)imageUrl;

/**
 * category identifier.
 *
 * @discussion Example:
 * @code
 * // Get category ID
 * int32_t categoryId = [category getId];
 * NSLog(@"Category ID: %d", categoryId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * category name.
 *
 * @discussion Example:
 * @code
 * // Get category name
 * NSString *categoryName = [category getName];
 * NSLog(@"Category name: %@", categoryName);
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * image source. If presented.
 *
 * @discussion Example:
 * @code
 * // Get category image URL
 * NSString *imageUrl = [category getImageUrl];
 * if (imageUrl != nil) {
 *    NSLog(@"Category image URL: %@", imageUrl);
 * }
 * @endcode
 */
@property (nonatomic, readonly, nullable) NSString * imageUrl;

@end
