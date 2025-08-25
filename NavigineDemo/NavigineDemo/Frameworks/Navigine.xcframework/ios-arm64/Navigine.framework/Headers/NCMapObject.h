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
 * @brief Base interface for handling objects on the location view.
 *
 * Used to manage objects in @see LocationWindow "LocationWindow".
 * Can be handled in the `pickMapObjectAt` method @see LocationWindow "LocationWindow".
 *
 * Referenced from @see CircleMapObject "CircleMapObject", @see IconMapObject "IconMapObject", @see PolylineMapObject "PolylineMapObject", @see PolygonMapObject "PolygonMapObject", @see DottedPolylineMapObject "DottedPolylineMapObject".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObject : NSObject

/**
 *
 * @brief Gets the unique identifier of the map object.
 * @return The unique identifier of the map object.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_getId
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_getId
 *
 *
 */
- (int32_t)getId;

/**
 *
 * @brief Gets the type of the map object.
 * @return The type of the map object @see MapObjectType "MapObjectType".
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_getType
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_getType
 *
 *
 */
- (NCMapObjectType)getType;

/**
 *
 * @brief Gets the user-defined data associated with the map object.
 * @return The data stored in the map object.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_getData
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_getData
 *
 *
 */
- (nonnull NSData *)getData;

/**
 *
 * @brief Method is used to specify the visibility of the map object.
 * @param visible Specifies whether the object is visible (true) or hidden (false). Default: true.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_setVisible
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_setVisible
 *
 *
 */
- (BOOL)setVisible:(BOOL)visible;

/**
 *
 * @brief Method is used to specify whether the map object can be interacted with.
 * @param interactive Specifies whether the object can be picked in the `pickMapObjectAt` method (true) or not (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_setInteractive
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_setInteractive
 *
 *
 */
- (BOOL)setInteractive:(BOOL)interactive;

/**
 *
 * @brief Method is used to set user-defined data for the map object.
 * @param data Data to store in the map object.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_setData
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_setData
 *
 *
 */
- (void)setData:(nonnull NSData *)data;

/**
 *
 * @brief Method is used to set the title of the map object.
 * @param title The title to display on the location view.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_setTitle
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_setTitle
 *
 *
 */
- (BOOL)setTitle:(nonnull NSString *)title;

/**
 *
 * @brief Method is used to set the opacity of the map object.
 * @param alpha Opacity multiplier. Values below 0 will be set to 0. Values above 1 will be set to 1. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowMapObjectsExample.swift swift_MapObject_setAlpha
 *
 * Objective C code snippet:
 * @snippet LocationWindowMapObjectsExample.m objc_MapObject_setAlpha
 *
 *
 */
- (BOOL)setAlpha:(float)alpha;

@end
