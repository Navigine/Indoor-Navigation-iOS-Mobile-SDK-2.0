#import "NCCategory.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCElevationGraph;
@class NCSublocation;


/**
 * Class is used for storing location parameters: identifier, version, name, a list of sublocations, etc.
 * Location instance can be obtained from ``NCLocationManager`` using ``NCLocationListener`` callback,
 * when the location is loaded.
 * Referenced from ``NCLocationManager`` ``NCLocationListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocation : NSObject

/**
 * Method returns location elevation graph ``NCElevationGraph``
 * for specified tag
 * @param tag Graph tag in CMS
 * @return Elevation graph instance or `null`.
 * @return ``NCElevationGraph`` of the current location with the specified tag, if it exists. If elevation graph with the specified tag doesn't exist, function returns null.
 *
 * @discussion Example:
 * @code
 * // Get elevation graph by tag
 * if (graphTags.count > 0) {
 *    NCElevationGraph *elevationGraph = [location getElevationGraph:graphTags[0]];
 *    if (elevationGraph != nil) {
 *        [self demonstrateElevationGraphUsage:elevationGraph];
 *    }
 * }
 * @endcode
 */
- (nullable NCElevationGraph *)getElevationGraph:(nonnull NSString *)tag;

/**
 * Method returns list of available graph tags.
 * @return Array of existing tags
 *
 * @discussion Example:
 * @code
 * // Get available graph tags
 * NSArray<NSString *> *graphTags = [location getGraphTags];
 * NSLog(@"Available graph tags: %@", graphTags);
 * @endcode
 */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 * Method is used for obtaining a sublocation with the specified identifier from the current location.
 * @param id sublocation identifier.
 * @return The ``NCSublocation`` of the current location with the specified identifier, if it exists. If sublocation with the specified identifier doesn't exist, function returns null.
 *
 * @discussion Example:
 * @code
 * // Get sublocation by ID
 * if (sublocations.count > 0) {
 *    NCSublocation *sublocation = [location getSublocationById:[sublocations[0] getId]];
 *    if (sublocation != nil) {
 *        [self demonstrateSublocationUsage:sublocation];
 *    }
 * }
 * @endcode
 */
- (nullable NCSublocation *)getSublocationById:(int32_t)id;

/**
 * Method is used for obtaining a category with the specified identifier from the current location.
 * @param id category identifier.
 * @return ``NCCategory`` of the current location with the specified identifier, if it exists. If category with the specified identifier doesn't exist, function returns null.
 *
 * @discussion Example:
 * @code
 * // Get category by ID
 * if (categories.count > 0) {
 *    NCCategory *category = [location getCategoryById:[categories[0] getId]];
 *    if (category != nil) {
 *        [self demonstrateCategoryUsage:category];
 *    }
 * }
 * @endcode
 */
- (nullable NCCategory *)getCategoryById:(int32_t)id;

/**
 * location's identifier.
 *
 * @discussion Example:
 * @code
 * // Get location ID
 * int32_t locationId = [location getId];
 * NSLog(@"Location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * location's version.
 *
 * @discussion Example:
 * @code
 * // Get location version
 * int32_t version = [location getVersion];
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
 * NSString *name = [location getName];
 * NSLog(@"Location name: %@", name);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * location's description.
 *
 * @discussion Example:
 * @code
 * // Get location description
 * NSString *description = [location getDescript];
 * NSLog(@"Location description: %@", description);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * List of venue categories defined for the location ``NCCategory``.
 *
 * @discussion Example:
 * @code
 * // Get all categories
 * NSArray<NCCategory *> *categories = [location getCategories];
 * NSLog(@"Number of categories: %lu", (unsigned long)categories.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCCategory *> * categories;

/**
 * List of sublocations ``NCSublocation``
 *
 * @discussion Example:
 * @code
 * // Get all sublocations
 * NSArray<NCSublocation *> *sublocations = [location getSublocations];
 * NSLog(@"Number of sublocations: %lu", (unsigned long)sublocations.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCSublocation *> * sublocations;

/**
 * Flag indicates if location has been modified by user or not
 *
 * @discussion Example:
 * @code
 * // Check if location is modified
 * BOOL isModified = [location getModified];
 * NSLog(@"Location modified: %@", isModified ? @"YES" : @"NO");
 * @endcode
 */
@property (nonatomic, readonly) BOOL modified;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
