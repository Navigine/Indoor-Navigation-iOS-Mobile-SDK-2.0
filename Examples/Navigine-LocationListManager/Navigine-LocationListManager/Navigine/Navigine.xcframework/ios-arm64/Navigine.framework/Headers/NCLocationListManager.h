#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListListener;


/** Class is used to manage list of available locations */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationListManager : NSObject

/**
 *
 * Method is used to add listener to handle location list updates (@see LocationListListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeLocationListListener:(nullable id<NCLocationListListener>)listener;

/**
 *
 * Method is used to force reload location list.
 *
 */
- (void)updateLocationList;

/**
 *
 * Method is used to get current location list.
 *
 */
- (nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)getLocationList;

@end
