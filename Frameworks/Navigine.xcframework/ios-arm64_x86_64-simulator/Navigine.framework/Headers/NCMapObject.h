#import "NCExport.h"
#import "NCMapObjectType.h"
#import <Foundation/Foundation.h>


/**
 * Base interface for handling objects on the location view.
 * Used to manage objects in ``NCLocationWindow``.
 * Can be handled in the `pickMapObjectAt` method ``NCLocationWindow``.
 * Referenced from ``NCCircleMapObject``, ``NCIconMapObject``, ``NCClusterMapObject``, ``NCPolylineMapObject``, ``NCPolygonMapObject``, ``NCDottedPolylineMapObject``, ``NCModelMapObject``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapObject : NSObject

/**
 * Gets the unique identifier of the map object.
 * @return The unique identifier of the map object.
 *
 * @discussion Example:
 * @code
 * // Get object ID
 * NSInteger objectId = circleObject.id;
 * NSLog(@"Circle object ID: %ld", (long)objectId);
 * @endcode
 */
- (int32_t)getId;

/**
 * Gets the type of the map object.
 * @return The type of the map object ``NCMapObjectType``.
 *
 * @discussion Example:
 * @code
 * // Get object type
 * NSString *objectTypeString = circleObject.type;
 * NSLog(@"Circle object type: %@", objectTypeString);
 * @endcode
 */
- (NCMapObjectType)getType;

/**
 * Gets the user-defined data associated with the map object.
 * @return The data stored in the map object.
 *
 * @discussion Example:
 * @code
 * // Get custom data
 * NSDictionary *retrievedData = circleObject.data;
 * NSLog(@"Circle custom data: %@", retrievedData);
 * @endcode
 */
- (nonnull NSData *)getData;

/**
 * Method is used to specify the visibility of the map object.
 * @param visible Specifies whether the object is visible (true) or hidden (false). Default: true.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set visibility
 * BOOL visibleSuccess = [circleObject setVisible:YES];
 * NSLog(@"Set circle visibility to true: %@", visibleSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setVisible:(BOOL)visible;

/**
 * Method is used to specify whether the map object can be interacted with.
 * @param interactive Specifies whether the object can be picked in the `pickMapObjectAt` method (true) or not (false). Default: false.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set interactive mode
 * BOOL interactiveSuccess = [circleObject setInteractive:YES];
 * NSLog(@"Set circle interactive to true: %@", interactiveSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setInteractive:(BOOL)interactive;

/**
 * Method is used to set user-defined data for the map object.
 * @param data Data to store in the map object.
 *
 * @discussion Example:
 * @code
 * // Set custom data
 * NSDictionary *customData = @{@"key": @"value", @"number": @"42"};
 * BOOL dataSuccess = [circleObject setData:customData];
 * NSLog(@"Set circle custom data: %@", dataSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (void)setData:(nonnull NSData *)data;

/**
 * Method is used to set the title of the map object.
 * @param title The title to display on the location view.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set title
 * BOOL titleSuccess = [circleObject setTitle:@"Circle Object"];
 * NSLog(@"Set circle title to 'Circle Object': %@", titleSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setTitle:(nonnull NSString *)title;

/**
 * Method is used to set the opacity of the map object.
 * @param alpha Opacity multiplier. Values below 0 will be set to 0. Values above 1 will be set to 1. Default: 1.
 * @return true if the operation is successful, false otherwise.
 *
 * @discussion Example:
 * @code
 * // Set alpha transparency
 * BOOL alphaSuccess = [circleObject setAlpha:0.7];
 * NSLog(@"Set circle alpha to 0.7: %@", alphaSuccess ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)setAlpha:(float)alpha;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
