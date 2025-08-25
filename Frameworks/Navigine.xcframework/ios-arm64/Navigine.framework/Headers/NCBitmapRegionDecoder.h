#import "NCExport.h"
#import "NCRectangle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCBitmapRegionDecoder;


/**
 * @file NCBitmapRegionDecoder.h
 * @brief @copybrief NCBitmapRegionDecoder
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Сlass is used for getting bitmaps (png, jpg, svg) from byte array.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBitmapRegionDecoder : NSObject

/**
 *
 * @brief Method is used to create instance of BitmapRegionDecoder
 * @param data raw image data (could be raw svg string)
 * @return nstance of decoder, which could be used for decoding byte array to bitmap.
 *
 *
 * Swift code snippet:
 * @snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_newInstance
 *
 * Objective C code snippet:
 * @snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_newInstance
 *
 *
 */
+ (nullable NCBitmapRegionDecoder *)newInstance:(nonnull NSData *)data;

/**
 *
 * @brief Method is used to decode rectangle region in the image specified by rect.
 * @param rect area to render @see Rectangle "Rectangle"
 * @param sampleSize if set to a value > 1, requests the decoder to subsample the original image, returning a smaller image to save memory.
 * @return constructed bitmap
 *
 *
 * Swift code snippet:
 * @snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_decodeRegion
 *
 * Objective C code snippet:
 * @snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_decodeRegion
 *
 *
 */
- (nullable UIImage *)decodeRegion:(nonnull NCRectangle *)rect
                        sampleSize:(float)sampleSize;

@end
