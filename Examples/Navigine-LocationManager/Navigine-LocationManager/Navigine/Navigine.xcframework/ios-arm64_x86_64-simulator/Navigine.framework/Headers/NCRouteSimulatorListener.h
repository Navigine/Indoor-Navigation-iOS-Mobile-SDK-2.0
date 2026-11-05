#import "NCExport.h"
#import "NCRouteSimulatorSample.h"
#import <Foundation/Foundation.h>


/**
 * Walk progress. `onFinished` follows the last sample.
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCRouteSimulatorListener <NSObject>

- (void)onSample:(nonnull NCRouteSimulatorSample *)sample;

- (void)onFinished;

@end
