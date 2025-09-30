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
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getPolygon
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getPolygon
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPolygon * polygon;

/**
 * @brief zone's location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getLocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getLocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief zone's sublocationId identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getSublocationId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getSublocationId
 *
 *
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * @brief zone's identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief zone's name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief zone's color.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getColor
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getColor
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * color;

/**
 * @brief zone's alias.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Zone_getAlias
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Zone_getAlias
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

@end
