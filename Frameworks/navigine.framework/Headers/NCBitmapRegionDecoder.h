#import "NCRectangle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCBitmapRegionDecoder;


@interface NCBitmapRegionDecoder : NSObject

+ (nullable NCBitmapRegionDecoder *)newInstance:(nonnull NSData *)data
                                         length:(int32_t)length;

- (nullable UIImage *)decodeRegion:(nonnull NCRectangle *)rect
                        sampleSize:(int32_t)sampleSize;

@end
