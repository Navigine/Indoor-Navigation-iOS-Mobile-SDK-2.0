#import "NCExport.h"
#import "NCImageType.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object with image data in SDK
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCImage : NSObject

/** binary source data of the image */
@property (nonatomic, nonnull, readonly) NSData * data;

/** decoded image width */
@property (nonatomic, readonly) int32_t width;

/** decoded image height */
@property (nonatomic, readonly) int32_t height;

/** decoded image type */
@property (nonatomic, readonly) NCImageType type;

@end
