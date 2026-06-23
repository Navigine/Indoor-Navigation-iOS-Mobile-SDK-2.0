#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCMapObject;


/**
 * Class is used to handle information in ``NCPickListener``.
 * Referenced from ``NCPickListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObjectPickResult : NSObject

/**
 * Location of the picked map object ``NCLocationPoint``.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *point = mapObjectPickResult.point;
 * NSLog(@"Map object picked at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 * NSLog(@"  Object location: (%.1f, %.1f)", point.x, point.y);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCLocationPoint * point;

/**
 * Picked map object ``NCMapObject``.
 *
 * @discussion Example:
 * @code
 * NCMapObject *mapObject = mapObjectPickResult.mapObject;
 * NSLog(@"  Object type: %@", NSStringFromClass([mapObject class]));
 * @endcode
 */
@property (nonatomic, nullable, readonly) NCMapObject * mapObject;

@end
