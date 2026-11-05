#import "NCExport.h"
#import "NCLocationPoint.h"
#import "NCRouteEvent.h"
#import <Foundation/Foundation.h>

/**
 * Class describing one node of the evaluated route.
 * Referenced from ``NCRoutePath``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteNode : NSObject

/** 
 * Default constructor for class NCRouteNode 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCLocationPoint *)point
                               weight:(float)weight
                             distance:(float)distance
                               events:(nonnull NSArray<NCRouteEvent *> *)events;

/** 
 * Factory method for class NCRouteNode 
 */
+ (nonnull instancetype)routeNodeWithPoint:(nonnull NCLocationPoint *)point
                                    weight:(float)weight
                                  distance:(float)distance
                                    events:(nonnull NSArray<NCRouteEvent *> *)events;

/**
 * Location point of this node.
 *
 * @discussion Example:
 * @code
 * NCLocationPoint *point = [node getPoint];
 * [self demonstrateLocationPointUsage:point];
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NCLocationPoint * point;

/**
 * Route cost/weight value at this node.
 *
 * @discussion Example:
 * @code
 * float weight = [node getWeight];
 * NSLog(@"Node weight: %f", weight);
 * @endcode
 */
@property (nonatomic, readonly) float weight;

/**
 * Distance from route start to this node (meters).
 *
 * @discussion Example:
 * @code
 * float distance = [node getDistance];
 * NSLog(@"Node distance: %f meters", distance);
 * @endcode
 */
@property (nonatomic, readonly) float distance;

/**
 * Events associated with this node.
 *
 * @discussion Example:
 * @code
 * NSArray<NCRouteEvent *> *events = [node getEvents];
 * NSLog(@"Node has %lu events", (unsigned long)events.count);
 * for (NCRouteEvent *event in events) {
 *    [self demonstrateRouteEventUsage:event];
 * }
 * @endcode
 */
@property (nonatomic, readonly, nonnull) NSArray<NCRouteEvent *> * events;

@end
