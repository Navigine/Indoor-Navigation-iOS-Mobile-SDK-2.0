#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCMapObjectPickResult;


/** Class is used to handle for picking objects on the view (@see LocationView) */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPickListener <NSObject>

/**
 *
 * Receive the result from LocationView `pickMapObjectAt` method (@see LocationView)
 * @param mapObjectPickResult - MapObjectPickResult instance or `nil` if no objects was found (@see MapObjectPickResult).
 * @param screenPosition - position where the object was picked in pixels.
 *
 */
- (void)onMapObjectPickComplete:(nullable NCMapObjectPickResult *)mapObjectPickResult
                 screenPosition:(CGPoint)screenPosition;

/**
 *
 * Receive the result from LocationView `pickMapFeatureAt` method (@see LocationView)
 * @param mapFeaturePickResult - dictionary of properties of the picked feature or `nil` if no objects was found.
 * @param screenPosition - position where the object was picked in pixels.
 *
 */
- (void)onMapFeaturePickComplete:(nonnull NSDictionary<NSString *, NSString *> *)mapFeaturePickResult
                  screenPosition:(CGPoint)screenPosition;

@end
