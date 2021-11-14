#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCZone;


NAVIGINE_EXPORT
@protocol NCZoneListener

- (void)onEnterZone:(nullable NCZone *)zone;

- (void)onLeaveZone:(nullable NCZone *)zone;

@end
