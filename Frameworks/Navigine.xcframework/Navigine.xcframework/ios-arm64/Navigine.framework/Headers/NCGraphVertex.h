#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 * @file NCGraphVertex.h
 * @brief @copybrief NCGraphVertex
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 *
 * @brief Class is used for storing graph vertex.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGraphVertex : NSObject

/**
 * @brief graph vertex unique identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphVertex_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphVertex_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief graph vertex position in meters @see Point "Point".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphVertex_getPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphVertex_getPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief graph vertex name.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphVertex_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphVertex_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief graph vertex can be used to communicate with external graphs or not.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphVertex_getIsExternal
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphVertex_getIsExternal
 *
 *
 */
@property (nonatomic, readonly) BOOL isExternal;

/**
 * @brief graph vertex used in elevation graph @see ElevationGraph "ElevationGraph" or not.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_GraphVertex_getIsElevation
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_GraphVertex_getIsElevation
 *
 *
 */
@property (nonatomic, readonly) BOOL isElevation;

@end
