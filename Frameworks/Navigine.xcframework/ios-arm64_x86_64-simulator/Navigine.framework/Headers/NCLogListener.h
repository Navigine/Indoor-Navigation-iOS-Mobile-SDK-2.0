#import "NCExport.h"
#import "NCLogMessage.h"
#import <Foundation/Foundation.h>


/**
 * @file NCLogListener.h
 * @brief @copybrief NCLogListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLogListener <NSObject>

- (void)onMessageRecieved:(nonnull NCLogMessage *)message;

@end
