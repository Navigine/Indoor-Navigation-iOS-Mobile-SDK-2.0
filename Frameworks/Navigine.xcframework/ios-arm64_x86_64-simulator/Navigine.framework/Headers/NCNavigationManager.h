#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@protocol NCPositionListener;


/**
 * @file NCNavigationManager.h
 * @brief @copybrief NCNavigationManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Class is used for evaluating navigation and calculating users' @see Position "Position"
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigationManager : NSObject

/**
 *
 * @brief Method is used to add @see PositionListener "PositionListener" class element
 * which will notify about new user position.
 * @note Do not forget to remove listener if it is no longer needed!
 * @param listener Сorresponding @see PositionListener "PositionListener" class.
 *
 */
- (void)addPositionListener:(nullable id<NCPositionListener>)listener;

/**
 * @cond
 */
- (void)startLogRecording;

- (void)addCheckPoint:(nonnull NCLocationPoint *)point;

- (void)stopLogRecording;

- (void)addLocationMeasurement:(nonnull NCGlobalPoint *)point
                      accuracy:(double)accuracy
                      provider:(nonnull NSString *)provider;

/**
 * @endcond
 *
 * @brief Method is used for removing previously added @see PositionListener "PositionListener" class element.
 * @param listener Сorresponding @see PositionListener "PositionListener" class to remove.
 *
 */
- (void)removePositionListener:(nullable id<NCPositionListener>)listener;

@end
