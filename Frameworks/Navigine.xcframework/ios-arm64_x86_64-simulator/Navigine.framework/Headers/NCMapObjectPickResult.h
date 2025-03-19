#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCMapObject;


/**
 * @file NCMapObjectPickResult.h
 * @brief @copybrief NCMapObjectPickResult
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is useed to handle information in @see PickListener "PickListener".
 *
 * Referenced from @see PickListener "PickListener".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObjectPickResult : NSObject

/**
 *
 * @brief Location of the picked map object @see LocationPoint "LocationPoint".
 *
 */
@property (nonatomic, nonnull, readonly) NCLocationPoint * point;

/**
 *
 * @brief Picked map object @see MapObject "MapObject".
 *
 */
@property (nonatomic, nullable, readonly) NCMapObject * mapObject;

@end
