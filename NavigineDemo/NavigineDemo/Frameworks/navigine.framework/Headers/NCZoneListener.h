#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCZone;


NAVIGINE_EXPORT
@protocol NCZoneListener <NSObject>

- (void)onEnterZone:(nullable NCZone *)zone;

- (void)onLeaveZone:(nullable NCZone *)zone;

@end
