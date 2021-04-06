#import "NCMapObjectData.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


@interface NCLineMapObject : NSObject

- (void)setPoints:(nonnull NSArray<NCPoint *> *)points;

- (void)setWidth:(float)width;

- (float)getWidth;

- (void)setData:(nonnull NCMapObjectData *)data;

- (nonnull NCMapObjectData *)getData;

- (void)setEnabled:(BOOL)visibility;

- (void)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

@end
