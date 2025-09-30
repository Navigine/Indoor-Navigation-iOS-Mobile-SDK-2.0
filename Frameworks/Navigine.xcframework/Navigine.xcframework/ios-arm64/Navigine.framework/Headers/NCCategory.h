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
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Category_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Category_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief category name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Category_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Category_getName
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * @brief image source. If presented.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Category_getImageUrl
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Category_getImageUrl
 *
 *
 */
@property (nonatomic, readonly, nullable) NSString * imageUrl;

@end
