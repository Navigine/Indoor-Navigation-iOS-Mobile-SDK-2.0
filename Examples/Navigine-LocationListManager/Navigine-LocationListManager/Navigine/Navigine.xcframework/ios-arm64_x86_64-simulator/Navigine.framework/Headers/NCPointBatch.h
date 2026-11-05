#import "NCExport.h"
#import "NCMapObject.h"
#import "NCPointSprite.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * One object for a cloud of screen-space arrows.
 * `setPoints` replaces the whole set. The list order is the index returned by
 * `hitTest`. The host draws the tooltip. Points are not clustered.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPointBatch : NCMapObject

/**
 * Replaces every arrow. `sublocationId` null draws on the outdoor map.
 * @return false when the object has been removed.
 */
- (BOOL)setPoints:(nonnull NSArray<NCPointSprite *> *)points
    sublocationId:(nullable NSNumber *)sublocationId;

/**
 * Index of the nearest arrow inside `radius` pixels, or null.
 */
- (nullable NSNumber *)hitTest:(CGPoint)point
                        radius:(float)radius;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
