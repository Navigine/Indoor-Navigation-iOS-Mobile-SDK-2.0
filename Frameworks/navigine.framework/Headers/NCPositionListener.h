#import "NCPosition.h"
#import <Foundation/Foundation.h>


@protocol NCPositionListener

- (void)onPositionUpdated:(nonnull NCPosition *)position;

- (void)onPositionError:(nullable NSError *)error;

@end
