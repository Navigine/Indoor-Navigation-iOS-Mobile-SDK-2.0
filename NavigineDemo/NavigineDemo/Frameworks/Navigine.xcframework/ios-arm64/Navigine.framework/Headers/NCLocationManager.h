#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCLocationListener;


/** Class is used to manage locations */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationManager : NSObject

/**
 *
 * Method is used to add listener to handle location updates (@see LocationListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addLocationListener:(nullable id<NCLocationListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeLocationListener:(nullable id<NCLocationListener>)listener;

/**
 *
 * Method is used to select a specific location id from CMS to work with.
 * Result will be handled by LocationListener (@see LocationListener)
 *
 */
- (void)setLocationId:(int32_t)locationId;

/**
 *
 * Method returns current location unique identifier
 *
 */
- (int32_t)getLocationId;

/**
 *
 * Method is used to change interval in seconds ещcheck for new version in CMS
 * Default: 300s
 *
 */
- (void)setLocationUpdateInterval:(int32_t)interval;

/** @internal */
- (void)commitChanges;

/** @internal */
- (void)revertChanges;

@end
