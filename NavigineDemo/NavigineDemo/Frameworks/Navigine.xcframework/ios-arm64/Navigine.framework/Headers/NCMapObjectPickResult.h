#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>
@class NCMapObject;


/**
 * Class is used to handle information in ``NCPickListener``.
 * Referenced from ``NCPickListener``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObjectPickResult : NSObject

/**
 * WGS84 location of the picked map object ``NCGlobalPoint``.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *point = mapObjectPickResult.point;
 * NSLog(@"Map object picked at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 * NSLog(@"  Object location: (%.1f, %.1f)", point.x, point.y);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCGlobalPoint * point;

/**
 * Floor the picked object is attached to, or null for the outdoor map.
 */
@property (nonatomic, nullable, readonly) NSNumber * sublocationId;

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
