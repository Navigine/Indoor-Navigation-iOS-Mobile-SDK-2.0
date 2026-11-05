#import "NCExport.h"
#import "NCRectangle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCBitmapRegionDecoder;
@class NCImage;


/**
 * Class is used for getting bitmaps (png, jpg, svg) from byte array.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBitmapRegionDecoder : NSObject

/**
 * Method is used to create instance of BitmapRegionDecoder
 * @param data raw image data (could be raw svg string)
 * @return instance of decoder, which could be used for decoding byte array to bitmap.
 *
 * @discussion Example:
 * @code
 * // Create new instance of BitmapRegionDecoder
 * self.decoder = [NCBitmapRegionDecoder newInstanceWithData:self.imageData];
 * NSLog(@"Created BitmapRegionDecoder instance");
 * @endcode
 */
+ (nullable NCBitmapRegionDecoder *)newInstance:(nonnull NSData *)data;

/**
 * Creates decoder from ``NCImage`` without copying raw bytes again.
 * @param data image instance (e.g. from SDK pipeline); must remain valid while decoder is used
 * @return decoder instance or null on error
 *
 * @discussion Example:
 * @code
 * // When you already have an Image (e.g. from SDK), create decoder without passing raw bytes again
 * NCImage *imageForDecoder = nil; // set from your pipeline when available
 * NCBitmapRegionDecoder *decoderFromImage = [NCBitmapRegionDecoder newInstanceFromImageWithData:imageForDecoder];
 * NSLog(@"Decoder from Image: %@", decoderFromImage != nil ? @"yes" : @"no");
 * @endcode
 */
+ (nullable NCBitmapRegionDecoder *)newInstanceFromImage:(nullable NCImage *)data;

/**
 * Method is used to decode rectangle region in the image specified by rect.
 * @param rect area to render ``NCRectangle``
 * @param sampleSize if set to a value > 1, requests the decoder to subsample the original image, returning a smaller image to save memory.
 * @return constructed bitmap
 *
 * @discussion Example:
 * @code
 * // Decode region with sample size 1 (full resolution)
 * id decodedImage = [self.decoder decodeRegionWithRect:sampleRect sampleSize:1];
 * NSLog(@"Decoded region: %dx%d at sample size 1", sampleRect.width, sampleRect.height);
 * @endcode
 */
- (nullable UIImage *)decodeRegion:(nonnull NCRectangle *)rect
                        sampleSize:(float)sampleSize;

/**
 * Width of the source image in pixels (after header parse / decode metadata).
 *
 * @discussion Example:
 * @code
 * int32_t sourceWidth = self.decoder.width;
 * NSLog(@"Source image width: %d", sourceWidth);
 * @endcode
 */
@property (nonatomic, readonly) int32_t width;

/**
 * Height of the source image in pixels (after header parse / decode metadata).
 *
 * @discussion Example:
 * @code
 * int32_t sourceHeight = self.decoder.height;
 * NSLog(@"Source image height: %d", sourceHeight);
 * @endcode
 */
@property (nonatomic, readonly) int32_t height;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
