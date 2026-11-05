#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCRouteAnnotation.h"
#import <Foundation/Foundation.h>


DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteView : NSObject

- (int64_t)id;

- (nonnull NSArray<NCLocationPolyline *> *)geometry;

- (nonnull NSArray<NCRouteAnnotation *> *)annotations;

- (float)length;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
