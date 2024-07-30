#import "NCExport.h"
#import <Foundation/Foundation.h>
@protocol NCZoneListener;


/** Class is used to manage enter/exit zone events */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZoneManager : NSObject

/**
 *
 * Method is used to add listener to handle new enter/exit zone events (@see ZoneListener).
 * Do not forget to remove listener if it is no longer needed!
 *
 */
- (void)addZoneListener:(nullable id<NCZoneListener>)listener;

/**
 *
 * Method is used to remove listener.
 *
 */
- (void)removeZoneListener:(nullable id<NCZoneListener>)listener;

@end
