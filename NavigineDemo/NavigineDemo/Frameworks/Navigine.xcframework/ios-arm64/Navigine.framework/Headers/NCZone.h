#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>


/**
 * @file NCZone.h
 * @brief @copybrief NCZone
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @brief Class is used for storing location polygonal zones.
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZone : NSObject

/**
 * @brief zone's list of points composing the polygonal zone @see Polygon "Polygon"
 */
@property (nonatomic, nonnull, readonly) NCPolygon * polygon;

/**
 * @brief zone's location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief zone's sublocationId identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief zone's identifier.
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief zone's name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief zone's color.
 */
@property (nonatomic, nonnull, readonly) NSString * color;

/**
 * @brief zone's alias.
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

@end
