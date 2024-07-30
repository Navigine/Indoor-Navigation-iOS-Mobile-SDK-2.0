#import "NCCategory.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCElevationGraph;
@class NCSublocation;


/**
 *
 * Object describing location in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocation : NSObject

/** Method returns location elevation graph (@see ElevationGraph). */
- (nullable NCElevationGraph *)getElevationGraph:(nonnull NSString *)tag;

/** Method returns list of available graph tags. */
- (nonnull NSArray<NSString *> *)getGraphTags;

/**
 * Method returns sublocation by id.
 * @param id - unique sublocation identifier.
 * @return - sublocation instance or null.
 */
- (nullable NCSublocation *)getSublocationById:(int32_t)id;

/**
 * Method returns category by id.
 * @param id - unique category identifier.
 * @return - category instance or null.
 */
- (nullable NCCategory *)getCategoryById:(int32_t)id;

/** Location unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Current location version. */
@property (nonatomic, readonly) int32_t version;

/** Location name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Location description. */
@property (nonatomic, nonnull, readonly) NSString * descript;

/** List of supported categories (@see Category). */
@property (nonatomic, nonnull, readonly) NSArray<NCCategory *> * categories;

/** List of created sublocations (@see Sublocation). */
@property (nonatomic, nonnull, readonly) NSArray<NCSublocation *> * sublocations;

/** Flag indicates if location has been modified by user or not */
@property (nonatomic, readonly) BOOL modified;

@end
