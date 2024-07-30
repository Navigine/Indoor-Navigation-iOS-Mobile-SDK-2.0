#import "NCExport.h"
#import "NCLocationInfo.h"
#import <Foundation/Foundation.h>


/**
 * Class is used to handle events coming from LocationListManager (@see LocationListManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationListListener <NSObject>

/**
 *
 * @method onLocationListLoaded - called when new list of locations has been downloaded from CMS
 * @parameter locationInfos - dictionary represents location id to location general info (@see LocationInfo).
 *
 */
- (void)onLocationListLoaded:(nonnull NSDictionary<NSNumber *, NCLocationInfo *> *)locationInfos;

/**
 *
 * @method onLocationListFailed - called if unable to download location list from CMS
 * @parameter error - handled error.
 *
 */
- (void)onLocationListFailed:(nullable NSError *)error;

@end
