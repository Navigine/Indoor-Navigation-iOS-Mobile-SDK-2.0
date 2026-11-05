#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCMapObjectPickResult;


/**
 * Class is used to handle for picking objects on the location view
 * Referenced from ``NCLocationWindow``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPickListener <NSObject>

/**
 * Receive the result from ``NCLocationWindow`` `pickMapObjectAt` method
 * @param mapObjectPickResult ``NCMapObjectPickResult`` instance or `nil` if no objects was found.
 * @param screenPosition position where the object was picked in pixels.
 *
 * @discussion Example:
 * @code
 * - (void)onMapObjectPickCompleteWithMapObjectPickResult:(NCMapObjectPickResult *)mapObjectPickResult screenPosition:(NCPoint *)screenPosition {
 *    if (mapObjectPickResult != nil) {
 *        // [objc_MapObjectPickResult_getPoint]
 *        NCLocationPoint *point = mapObjectPickResult.point;
 *        NSLog(@"Map object picked at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 *        NSLog(@"  Object location: (%.1f, %.1f)", point.x, point.y);
 *        // [objc_MapObjectPickResult_getPoint]
 *        // [objc_MapObjectPickResult_getMapObject]
 *        NCMapObject *mapObject = mapObjectPickResult.mapObject;
 *        NSLog(@"  Object type: %@", NSStringFromClass([mapObject class]));
 *        // [objc_MapObjectPickResult_getMapObject]
 *    } else {
 *        NSLog(@"No map object found at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 *    }
 * }
 * @endcode
 */
- (void)onMapObjectPickComplete:(nullable NCMapObjectPickResult *)mapObjectPickResult
                 screenPosition:(CGPoint)screenPosition;

/**
 * Receive the result from ``NCLocationWindow`` `pickMapFeatureAt`
 * @param mapFeaturePickResult dictionary of properties of the picked feature or `nil` if no objects was found.
 * @param screenPosition position where the object was picked in pixels.
 *
 * @discussion Example:
 * @code
 * - (void)onMapFeaturePickCompleteWithMapFeaturePickResult:(NSDictionary<NSString *, NSString *> *)mapFeaturePickResult screenPosition:(NCPoint *)screenPosition {
 *    if (mapFeaturePickResult != nil) {
 *        NSLog(@"Map feature picked at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 *        NSLog(@"  Feature properties: %@", mapFeaturePickResult);
 *    } else {
 *        NSLog(@"No map feature found at screen position (%.1f, %.1f)", screenPosition.x, screenPosition.y);
 *    }
 * }
 * @endcode
 */
- (void)onMapFeaturePickComplete:(nonnull NSDictionary<NSString *, NSString *> *)mapFeaturePickResult
                  screenPosition:(CGPoint)screenPosition;

@end
