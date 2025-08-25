#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCMapObjectPickResult;


/**
 * @file NCPickListener.h
 * @brief @copybrief NCPickListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to handle for picking objects on the location view
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPickListener <NSObject>

/**
 *
 * @brief Receive the result from @see LocationWindow "LocationWindow" `pickMapObjectAt` method
 * @param mapObjectPickResult @see MapObjectPickResult "MapObjectPickResult" instance or `nil` if no objects was found.
 * @param screenPosition position where the object was picked in pixels.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_PickListener_onMapObjectPickComplete
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_PickListener_onMapObjectPickComplete
 *
 *
 */
- (void)onMapObjectPickComplete:(nullable NCMapObjectPickResult *)mapObjectPickResult
                 screenPosition:(CGPoint)screenPosition;

/**
 *
 * @brief Receive the result from @see LocationWindow "LocationWindow" `pickMapFeatureAt`
 * @param mapFeaturePickResult dictionary of properties of the picked feature or `nil` if no objects was found.
 * @param screenPosition position where the object was picked in pixels.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowInteractionExample.swift swift_PickListener_onMapFeaturePickComplete
 *
 * Objective C code snippet:
 * @snippet LocationWindowInteractionExample.m objc_PickListener_onMapFeaturePickComplete
 *
 *
 */
- (void)onMapFeaturePickComplete:(nonnull NSDictionary<NSString *, NSString *> *)mapFeaturePickResult
                  screenPosition:(CGPoint)screenPosition;

@end
