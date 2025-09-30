#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCAsyncRouteListener;


/**
 * @file NCRouteSession.h
 * @brief @copybrief NCRouteSession
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for managing async route listeners
 *
 * Referenced from @see AsyncRouteManager "AsyncRouteManager".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteSession : NSObject

/**
 *
 * @brief Method is used to add @see AsyncRouteListener "AsyncRouteListener" class element
 * which will notify async route events.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see AsyncRouteListener "AsyncRouteListener" class.
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_RouteSession_addRouteListener
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_RouteSession_addRouteListener
 *
 *
 */
- (void)addRouteListener:(nullable id<NCAsyncRouteListener>)listener;

/**
 *
 * @brief Method is used for removing previously added @see AsyncRouteListener "AsyncRouteListener" class element.
 * @param listener Сorresponding @see AsyncRouteListener "AsyncRouteListener" class to remove.
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_RouteSession_addRouteListener
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_RouteSession_addRouteListener
 *
 *
 */
- (void)removeRouteListener:(nullable id<NCAsyncRouteListener>)listener;

@end
