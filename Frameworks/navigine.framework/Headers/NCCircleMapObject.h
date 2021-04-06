#import "NCMapObjectData.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


@interface NCCircleMapObject : NSObject

- (void)setPosition:(nonnull NCPoint *)point;

- (nonnull NCPoint *)getPosition;

- (void)setRadius:(float)radius;

- (float)getRadius;

- (void)setData:(nonnull NCMapObjectData *)data;

- (nonnull NCMapObjectData *)getData;

- (void)setEnabled:(BOOL)visibility;

- (void)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
