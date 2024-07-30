#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


/**
 * Class is used to handle events coming from LocationManager (@see LocationManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListener <NSObject>

/**
 *
 * @method onLocationLoaded - called when new location version has been downloaded from CMS
 * @parameter location - downloaded location instance (@see Location).
 *
 */
- (void)onLocationLoaded:(nullable NCLocation *)location;

/**
 *
 * @method onLocationFailed - called if unable to download location version from CMS
 * @parameter locationId - location unique identifier in SMC.
 * @parameter error - handled error.
 *
 */
- (void)onLocationFailed:(int32_t)locationId
                   error:(nullable NSError *)error;

/** @internal */
- (void)onLocationUploaded:(int32_t)locationId;

@end
