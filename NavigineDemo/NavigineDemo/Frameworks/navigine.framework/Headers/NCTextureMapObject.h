#import "NCExport.h"
#import "NCMapObjectData.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCTextureMapObject : NSObject

- (void)setPosition:(nonnull NCPoint *)point;

- (nonnull NCPoint *)getPosition;

- (void)setSize:(float)width
         height:(float)height;

- (float)getWidth;

- (float)getHeight;

- (void)setData:(nonnull NCMapObjectData *)data;

- (nonnull NCMapObjectData *)getData;

- (void)setEnabled:(BOOL)status;

- (void)setTexture:(nonnull NSData *)data
        imageWidth:(int32_t)imageWidth
       imageHeight:(int32_t)imageHeight;

@end
