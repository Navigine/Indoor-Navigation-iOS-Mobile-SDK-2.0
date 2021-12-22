#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCPolylineMapObject : NCMapObject

- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

- (BOOL)setWidth:(float)width;

@end
