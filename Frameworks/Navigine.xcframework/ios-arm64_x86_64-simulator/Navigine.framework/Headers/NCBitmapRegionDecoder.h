#import "NCExport.h"
#import "NCRectangle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCBitmapRegionDecoder;
@class NCImage;


/**
 * @file NCBitmapRegionDecoder.h
 * @brief @copybrief NCBitmapRegionDecoder
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Class is used for getting bitmaps (png, jpg, svg) from byte array.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBitmapRegionDecoder : NSObject

/**
 * @brief Method is used to create instance of BitmapRegionDecoder
 * @param data raw image data (could be raw svg string)
 * @return nstance of decoder, which could be used for decoding byte array to bitmap.
 *
 *
 *
 *Swift code snippet:
 *@snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_newInstance
 *
 *Objective C code snippet:
 *@snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_newInstance
 *
 *
 */
+ (nullable NCBitmapRegionDecoder *)newInstance:(nonnull NSData *)data;

/**
 * @brief Creates decoder from @see Image "Image" without copying raw bytes again.
 * @param data image instance (e.g. from SDK pipeline); must remain valid while decoder is used
 * @return decoder instance or null on error
 *
 *
 *
 *Swift code snippet:
 *@snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_newInstanceFromImage
 *
 *Objective C code snippet:
 *@snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_newInstanceFromImage
 *
 *
 */
+ (nullable NCBitmapRegionDecoder *)newInstanceFromImage:(nullable NCImage *)data;

/**
 * @brief Method is used to decode rectangle region in the image specified by rect.
 * @param rect area to render @see Rectangle "Rectangle"
 * @param sampleSize if set to a value > 1, requests the decoder to subsample the original image, returning a smaller image to save memory.
 * @return constructed bitmap
 *
 *
 *
 *Swift code snippet:
 *@snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_decodeRegion
 *
 *Objective C code snippet:
 *@snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_decodeRegion
 *
 *
 */
- (nullable UIImage *)decodeRegion:(nonnull NCRectangle *)rect
                        sampleSize:(float)sampleSize;

/**
 * @brief Width of the source image in pixels (after header parse / decode metadata).
 *
 *
 *
 *Swift code snippet:
 *@snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_getWidth
 *
 *Objective C code snippet:
 *@snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_getWidth
 *
 *
 */
@property (nonatomic, readonly) int32_t width;

/**
 * @brief Height of the source image in pixels (after header parse / decode metadata).
 *
 *
 *
 *Swift code snippet:
 *@snippet BitmapRegionDecoderExample.swift swift_BitmapRegionDecoder_getHeight
 *
 *Objective C code snippet:
 *@snippet BitmapRegionDecoderExample.m objc_BitmapRegionDecoder_getHeight
 *
 *
 */
@property (nonatomic, readonly) int32_t height;

@end
