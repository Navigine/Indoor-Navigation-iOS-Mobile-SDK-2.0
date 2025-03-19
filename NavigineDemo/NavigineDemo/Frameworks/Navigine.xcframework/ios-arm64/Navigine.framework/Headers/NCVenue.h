#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 * @file NCVenue.h
 * @brief @copybrief NCVenue
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @brief Class is used for storing venue.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVenue : NSObject

/**
 * @brief venue's X and Y coordinates in meters as @see Point "Point" (within the sublocation).
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief venue's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief venue's sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief venue's identifier.
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief venue's name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief venue's phone.
 */
@property (nonatomic, nonnull, readonly) NSString * phone;

/**
 * @brief venue's description.
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * @brief venue's alias.
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

/**
 * @brief venue's category unique identifier @see Category "Category"
 */
@property (nonatomic, readonly) int32_t categoryId;

/**
 * @brief venue's image url if specified.
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
