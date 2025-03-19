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
 */
- (nullable NCElevationGraph *)getElevationGraph:(nonnull NSString *)tag;

/**
 * @brief Method returns list of available graph tags.
 * @return Array of existing tags
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 * @brief Method is used for obtaining a sublocation with the specified identifier from the current location.
 * @param id sublocation identifier.
 * @return The @see Sublocation "Sublocation" of the current location with the specified identifier, if it exists. If sublocation with the specified identifier doesn't exist, function returns null.
 */
- (nullable NCSublocation *)getSublocationById:(int32_t)id;

/**
 * @brief Method is used for obtaining a category with the specified identifier from the current location.
 * @param id category identifier.
 * @return @see Category "Category" of the current location with the specified identifier, if it exists. If category with the specified identifier doesn't exist, function returns null.
 */
- (nullable NCCategory *)getCategoryById:(int32_t)id;

/**
 * @brief location's identifier.
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief location's version.
 */
@property (nonatomic, readonly) int32_t version;

/**
 * @brief location name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief location's description.
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * @brief List of venue categories defined for the location @see Category "Category".
 */
@property (nonatomic, nonnull, readonly) NSArray<NCCategory *> * categories;

/**
 * @brief List of sublocations @see Sublocation "Sublocation"
 */
@property (nonatomic, nonnull, readonly) NSArray<NCSublocation *> * sublocations;

/**
 * @brief Flag indicates if location has been modified by user or not
 */
@property (nonatomic, readonly) BOOL modified;

@end
