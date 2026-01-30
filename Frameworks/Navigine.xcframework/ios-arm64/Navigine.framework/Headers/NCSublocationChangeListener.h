#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCSublocationChangeListener.h
 * @brief @copybrief NCSublocationChangeListener-p
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Class is used to listen for sublocation change events
 *
 * Referenced from @see LocationWindow "LocationWindow".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCSublocationChangeListener <NSObject>

/**
 * @brief Called when active sublocation changes.
 * @param sublocationId New active sublocation identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationWindowCommonExample.swift swift_SublocationChangeListener_onActiveSublocationChanged
 *
 * Objective C code snippet:
 * @snippet LocationWindowCommonExample.m objc_SublocationChangeListener_onActiveSublocationChanged
 *
 *
 */
- (void)onActiveSublocationChanged:(int32_t)sublocationId;

@end
