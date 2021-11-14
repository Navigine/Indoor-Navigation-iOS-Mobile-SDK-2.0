#import "NCExport.h"
#import "NCLocationPolyline.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCPolylineMapObject : NSObject

- (BOOL)setPolyLine:(nonnull NCLocationPolyline *)polyline;

- (BOOL)setWidth:(float)width;

- (BOOL)setVisible:(BOOL)visible;

- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
