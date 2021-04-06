#import <Foundation/Foundation.h>
@class NCZone;


@protocol NCZoneListener

- (void)onEnterZone:(nullable NCZone *)zone;

- (void)onLeaveZone:(nullable NCZone *)zone;

@end
