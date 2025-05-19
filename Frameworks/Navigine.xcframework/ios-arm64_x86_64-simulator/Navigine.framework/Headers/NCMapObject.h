#import "NCExport.h"
#import "NCMapObjectType.h"
#import <Foundation/Foundation.h>


/**
 * @file NCMapObject.h
 * @brief @copybrief NCMapObject
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to handle object on @see LocationWindow "LocationWindow" created and managing by user
 * Could be handled in `pickMapObjectAt` method @see LocationWindow "LocationWindow"
 *
 * Referenced from @see CircleMapObject "CircleMapObject", @see IconMapObject "IconMapObject", @see FlatIconMapObject "FlatIconMapObject".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObject : NSObject

/**
 * @brief Unique identifier of map object
 * @return Unique identifier of current map objcet @see MapObjectType "MapObjectType"
 */
- (int32_t)getId;

/**
 * @brief Map object type @see MapObjectType "MapObjectType".
 * Map object could be casted to the specified type.
 * @return Type of current map objcet @see MapObjectType "MapObjectType".
 */
- (NCMapObjectType)getType;

/**
 * @brief Any kind of user's data
 * @return Data stored in map object @see MapObjectType "MapObjectType".
 */
- (nonnull NSData *)getData;

/**
 * @brief Method is used to change visibility of map object.
 * @param visible control visibility of the object.
 * @return true if success, false otherwise.
 */
- (BOOL)setVisible:(BOOL)visible;

/**
 * @brief Method is used to interactive property
 * If True - map object could be handled in `pickMapObjectAt` method.
 * @param interactive control interactivity of the object.
 * @return true if success, false otherwise.
 */
- (BOOL)setInteractive:(BOOL)interactive;

/**
 * @brief Method is used to apply custom styling to map object.
 * @param style styling string (@ref en/styles/styles.md).
 * @return true if success, false otherwise.
 */
- (BOOL)setStyle:(nonnull NSString *)style;

/**
 * @brief Method is used to set any kind of user's data
 * @param data Data to store in map object
 */
- (void)setData:(nonnull NSData *)data;

/**
 * @brief Method is used to set object title.
 * Title will shown on location view.
 * @param title of map object.
 * @return true if success, false otherwise.
 */
- (BOOL)setTitle:(nonnull NSString *)title;

@end
