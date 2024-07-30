#import "NCExport.h"
#import "NCMapObjectType.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object on map created and managing by user
 * Could be handled in `pickMapObjectAt` method (@see LocationWindow)
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObject : NSObject

/** Unique identifier of map object */
- (int32_t)getId;

/**
 * Map object type (@see MapObjectType).
 * Map object could be casted to the specified type.
 */
- (NCMapObjectType)getType;

/** Any kind of user's data */
- (nonnull NSData *)getData;

/** Method is used to change visibility of map object. */
- (BOOL)setVisible:(BOOL)visible;

/**
 * Method is used to interactive property
 * If True - map object could be handled in `pickMapObjectAt` method.
 */
- (BOOL)setInteractive:(BOOL)interactive;

/** Method is used to apply custom styling to map object. */
- (BOOL)setStyle:(nonnull NSString *)style;

/** Method is used to set any kind of user's data */
- (void)setData:(nonnull NSData *)data;

/**
 * Method is used to set object title.
 * Title will shown on LocationView.
 */
- (BOOL)setTitle:(nonnull NSString *)title;

@end
