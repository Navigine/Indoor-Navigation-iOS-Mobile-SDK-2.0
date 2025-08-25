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
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief venue's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getLocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief venue's sublocation identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief venue's identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief venue's name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief venue's phone.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getPhone
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getPhone
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * phone;

/**
 * @brief venue's description.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getDescript
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getDescript
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * @brief venue's alias.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getAlias
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getAlias
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

/**
 * @brief venue's category unique identifier @see Category "Category"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getCategoryId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getCategoryId
 *
 *
 */
@property (nonatomic, readonly) int32_t categoryId;

/**
 * @brief venue's image url if specified.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Venue_getImageUrl
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Venue_getImageUrl
 *
 *
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
