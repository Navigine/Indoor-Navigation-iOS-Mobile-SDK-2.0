#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCCategory.h
 * @brief @copybrief NCCategory
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @brief class is used for storing venue categories.
 *
 * Referenced from @see Location "Location" @see Venue "Venue".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCCategory : NSObject

/** 
 * @brief Default constructor for class NCCategory 
 */
- (nonnull instancetype)initWithId:(int32_t)id
                              name:(nonnull NSString *)name
                          imageUrl:(nullable NSString *)imageUrl;

/** 
 * @brief Factory method for class NCCategory 
 */
+ (nonnull instancetype)categoryWithId:(int32_t)id
                                  name:(nonnull NSString *)name
                              imageUrl:(nullable NSString *)imageUrl;

/**
 * @brief category identifier.
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief category name.
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * @brief image source. If presented.
 */
@property (nonatomic, readonly, nullable) NSString * imageUrl;

@end
