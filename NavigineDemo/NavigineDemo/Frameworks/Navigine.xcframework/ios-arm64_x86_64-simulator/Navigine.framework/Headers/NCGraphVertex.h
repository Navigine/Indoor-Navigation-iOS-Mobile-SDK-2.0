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
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief graph vertex position in meters @see Point "Point".
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * @brief graph vertex name.
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief graph vertex can be used to communicate with external graphs or not.
 */
@property (nonatomic, readonly) BOOL isExternal;

/**
 * @brief graph vertex used in elevation graph @see ElevationGraph "ElevationGraph" or not.
 */
@property (nonatomic, readonly) BOOL isElevation;

@end
