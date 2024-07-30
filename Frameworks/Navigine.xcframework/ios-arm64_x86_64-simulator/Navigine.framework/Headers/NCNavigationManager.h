#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
@protocol NCPositionListener;


/** Class is used to manage navigation routine */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCNavigationManager : NSObject

/**
 *
 * Method is used to add listener to handle position updates (@see PositionListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addPositionListener:(nullable id<NCPositionListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removePositionListener:(nullable id<NCPositionListener>)listener;

/** @internal */
- (void)startLogRecording;

/** @internal */
- (void)addCheckPoint:(nonnull NCLocationPoint *)point;

/** @internal */
- (void)stopLogRecording;

/** @internal */
- (void)addLocationMeasurement:(nonnull NCGlobalPoint *)point
                      accuracy:(double)accuracy
                      provider:(nonnull NSString *)provider;

@end
