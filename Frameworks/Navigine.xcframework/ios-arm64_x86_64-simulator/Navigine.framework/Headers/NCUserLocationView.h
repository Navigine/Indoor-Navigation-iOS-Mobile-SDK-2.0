#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCCircleMapObject;
@class NCIconMapObject;


/**
 * @file NCUserLocationView.h
 * @brief @copybrief NCUserLocationView
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCUserLocationView : NSObject

/**
 *
 * @brief Icon map object representing user arrow.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationView_getArrow
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationView_getArrow
 *
 *
 */
@property (nonatomic, nullable, readonly) NCIconMapObject * arrow;

/**
 *
 * @brief Accuracy circle around user position.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_UserLocationView_getAccuracyCircle
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_UserLocationView_getAccuracyCircle
 *
 *
 */
@property (nonatomic, nullable, readonly) NCCircleMapObject * accuracyCircle;

@end
