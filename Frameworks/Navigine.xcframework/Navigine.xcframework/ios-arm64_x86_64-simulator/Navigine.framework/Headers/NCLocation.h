#import "NCCategory.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCElevationGraph;
@class NCSublocation;


/**
 * @file NCLocation.h
 * @brief @copybrief NCLocation
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @brief Class is used for storing location parameters: identifier, version, name, a list of sublocations, etc.
 *
 * Location instance can be obtained from @see LocationManager "LocationManager" using @see LocationListener "LocationListener" callback,
 * when the location is loaded.
 *
 * Referenced from @see LocationManager "LocationManager" @see LocationListener "LocationListener".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocation : NSObject

/**
 * @brief Method returns location elevation graph @see ElevationGraph "ElevationGraph"
 * for specified tag
 * @param tag Graph tag in CMS
 * @return Elevation graph instance or `null`.
 * @return @see ElevationGraph "ElevationGraph" of the current location with the specified tag, if it exists. If elevation graph with the specified tag doesn't exist, function returns null.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getElevationGraph
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getElevationGraph
 *
 *
 */
- (nullable NCElevationGraph *)getElevationGraph:(nonnull NSString *)tag;

/**
 * @brief Method returns list of available graph tags.
 * @return Array of existing tags
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getGraphTags
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getGraphTags
 *
 *
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 * @brief Method is used for obtaining a sublocation with the specified identifier from the current location.
 * @param id sublocation identifier.
 * @return The @see Sublocation "Sublocation" of the current location with the specified identifier, if it exists. If sublocation with the specified identifier doesn't exist, function returns null.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getSublocationById
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getSublocationById
 *
 *
 */
- (nullable NCSublocation *)getSublocationById:(int32_t)id;

/**
 * @brief Method is used for obtaining a category with the specified identifier from the current location.
 * @param id category identifier.
 * @return @see Category "Category" of the current location with the specified identifier, if it exists. If category with the specified identifier doesn't exist, function returns null.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getCategoryById
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getCategoryById
 *
 *
 */
- (nullable NCCategory *)getCategoryById:(int32_t)id;

/**
 * @brief location's identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief location's version.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getVersion
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getVersion
 *
 *
 */
@property (nonatomic, readonly) int32_t version;

/**
 * @brief location name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief location's description.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getDescript
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getDescript
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * @brief List of venue categories defined for the location @see Category "Category".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getCategories
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getCategories
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCCategory *> * categories;

/**
 * @brief List of sublocations @see Sublocation "Sublocation"
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getSublocations
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getSublocations
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCSublocation *> * sublocations;

/**
 * @brief Flag indicates if location has been modified by user or not
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Location_getModified
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Location_getModified
 *
 *
 */
@property (nonatomic, readonly) BOOL modified;

@end
