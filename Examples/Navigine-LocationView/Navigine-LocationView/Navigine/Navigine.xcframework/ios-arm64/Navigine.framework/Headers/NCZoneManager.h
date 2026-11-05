#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCZoneListener;


/**
 * Class is used for notifying about entering or leaving ``NCZone``s.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneManager : NSObject

/**
 * Method is used to add ``NCZoneListener`` class element
 * which will notify entering or leaving ``NCZone``s.
 * @discussion Note: Do not forget to remove listener if it is no longer needed!
 * @param listener Corresponding ``NCZoneListener`` class.
 *
 * @discussion Example:
 * @code
 * // Add zone listener
 * [self.zoneManager addZoneListener:self.zoneListener];
 * NSLog(@"Added zone listener");
 * @endcode
 */
- (void)addZoneListener:(nullable id<NCZoneListener>)listener;

/**
 * Method is used for removing previously added ``NCZoneListener`` class element.
 * @param listener Corresponding ``NCZoneListener`` class to remove.
 *
 * @discussion Example:
 * @code
 * // Remove zone listener
 * [self.zoneManager removeZoneListener:self.zoneListener];
 * NSLog(@"Removed zone listener");
 * @endcode
 */
- (void)removeZoneListener:(nullable id<NCZoneListener>)listener;

@end
