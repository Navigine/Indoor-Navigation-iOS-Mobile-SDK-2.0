#import "NCExport.h"
#import "NCPosition.h"
#import <Foundation/Foundation.h>


/**
 * Class is used to handle events coming from NavigationManager (@see NavigationManager).
 * Methods invoked in UI
 */
DEFAULT_EXPORT_ATTRIBUTE
@protocol NCPositionListener <NSObject>

/**
 *
 * @method onPositionUpdated - called when new position has been calculated
 * @parameter position - current user position (@see Position).
 *
 */
- (void)onPositionUpdated:(nonnull NCPosition *)position;

/**
 *
 * @method onPositionError - called if unable to calculate user's position
 * @parameter error - handled error.
 *
 */
- (void)onPositionError:(nullable NSError *)error;

@end
