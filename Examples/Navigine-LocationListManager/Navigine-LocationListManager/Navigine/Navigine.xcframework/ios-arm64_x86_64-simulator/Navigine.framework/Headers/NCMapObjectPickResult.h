#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@class NCMapObject;


/** Class is useed to handle information in PickListener (@see PickListener). */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObjectPickResult : NSObject

/**
 *
 * @param point - location of the picked map object (@see LocationPoint).
 *
 */
@property (nonatomic, nonnull, readonly) NCLocationPoint * point;

/**
 *
 * @param mapObject - instance of the picked map object (@see MapObject).
 *
 */
@property (nonatomic, nullable, readonly) NCMapObject * mapObject;

@end
