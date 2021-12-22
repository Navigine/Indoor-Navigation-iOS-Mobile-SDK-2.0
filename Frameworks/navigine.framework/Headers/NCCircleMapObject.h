#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCCircleMapObject : NCMapObject

- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

- (BOOL)setRadius:(float)radius;

@end
