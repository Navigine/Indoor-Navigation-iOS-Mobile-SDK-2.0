#import "NCLocationPoint.h"
#import "NCRouteEvent.h"
#import <Foundation/Foundation.h>


@interface NCRoutePath : NSObject

@property (nonatomic, readonly) float length;

@property (nonatomic, nonnull, readonly) NSArray<NCRouteEvent *> * events;

@property (nonatomic, nonnull, readonly) NSArray<NCLocationPoint *> * points;

@end
