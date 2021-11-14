#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCCircleMapObject : NSObject

- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

- (BOOL)setRadius:(float)radius;

- (BOOL)setVisible:(BOOL)visible;

- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
