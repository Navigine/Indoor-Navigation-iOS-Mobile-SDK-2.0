#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCLocation;


DEFAULT_EXPORT_ATTRIBUTE
@protocol NCLocationEditListener <NSObject>

- (void)onLocationEditSuccess:(nullable NCLocation *)location;

- (void)onLocationEditError:(nullable NSError *)error;

@end
