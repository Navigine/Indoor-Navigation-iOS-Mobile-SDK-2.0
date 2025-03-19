#import "NCExport.h"
#import "NCImageType.h"
#import <Foundation/Foundation.h>


/**
 * @file NCImage.h
 * @brief @copybrief NCImage
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief class described image data in SDK
 *
 * Referenced from @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCImage : NSObject

/**
 * @brief binary source data of the image
 */
@property (nonatomic, nonnull, readonly) NSData * data;

/**
 * @brief decoded image width
 */
@property (nonatomic, readonly) int32_t width;

/**
 * @brief decoded image height
 */
@property (nonatomic, readonly) int32_t height;

/**
 * @brief decoded image type
 */
@property (nonatomic, readonly) NCImageType type;

@end
