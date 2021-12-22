#import "NCAnimationType.h"
#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCMapObject.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NAVIGINE_EXPORT
@interface NCIconMapObject : NCMapObject

- (BOOL)setPosition:(nonnull NCLocationPoint *)point;

- (BOOL)setPositionAnimated:(nonnull NCLocationPoint *)point
                   duration:(float)duration
                       type:(NCAnimationType)type;

- (BOOL)setBitmap:(nullable UIImage *)bitmap;

- (BOOL)setSize:(float)width
         height:(float)height;

@end
