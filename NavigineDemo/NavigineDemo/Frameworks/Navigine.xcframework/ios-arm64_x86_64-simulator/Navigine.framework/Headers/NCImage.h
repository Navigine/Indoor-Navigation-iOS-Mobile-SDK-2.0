#import "NCExport.h"
#import "NCImageType.h"
#import <Foundation/Foundation.h>


/**
 * class described image data in SDK
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCImage : NSObject

/**
 * binary source data of the image
 */
@property (nonatomic, nonnull, readonly) NSData * data;

/**
 * decoded image width
 */
@property (nonatomic, readonly) int32_t width;

/**
 * decoded image height
 */
@property (nonatomic, readonly) int32_t height;

/**
 * decoded image type
 */
@property (nonatomic, readonly) NCImageType type;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
