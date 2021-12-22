#import "NCExport.h"
#import "NCPosition.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@protocol NCPositionListener <NSObject>

- (void)onPositionUpdated:(nonnull NCPosition *)position;

- (void)onPositionError:(nullable NSError *)error;

@end
