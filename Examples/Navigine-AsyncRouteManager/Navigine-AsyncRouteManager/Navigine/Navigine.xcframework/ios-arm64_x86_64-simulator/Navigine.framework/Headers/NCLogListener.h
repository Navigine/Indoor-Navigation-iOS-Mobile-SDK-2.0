#import "NCExport.h"
#import "NCLogMessage.h"
#import <Foundation/Foundation.h>


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLogListener <NSObject>

- (void)onMessageRecieved:(nonnull NCLogMessage *)message;

@end
