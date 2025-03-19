#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


/**
 * @file NCLocationEditListener.h
 * @brief @copybrief NCLocationEditListener-p
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationEditListener <NSObject>

- (void)onLocationEditSuccess:(nullable NCLocation *)location;

- (void)onLocationEditError:(nullable NSError *)error;

@end
