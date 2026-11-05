#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@protocol NCPositionListener;


/**
 * Class is used for evaluating navigation and calculating users' ``NCPosition``
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigationManager : NSObject

/**
 * Method is used to add ``NCPositionListener`` class element
 * which will notify about new user position.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCPositionListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add position listener
 * [self.navigationManager addPositionListener:self];
 * @endcode
 */
- (void)addPositionListener:(nullable id<NCPositionListener>)listener;

- (void)startLogRecording;

- (void)addCheckPoint:(nonnull NCLocationPoint *)point;

- (void)stopLogRecording;

- (void)addLocationMeasurement:(nonnull NCGlobalPoint *)point
                      accuracy:(float)accuracy
                      provider:(nonnull NSString *)provider;

/**
 * Method is used for removing previously added ``NCPositionListener`` class element.
 * @param listener Corresponding ``NCPositionListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove position listener
 * [self.navigationManager removePositionListener:self];
 * @endcode
 */
- (void)removePositionListener:(nullable id<NCPositionListener>)listener;

@end
