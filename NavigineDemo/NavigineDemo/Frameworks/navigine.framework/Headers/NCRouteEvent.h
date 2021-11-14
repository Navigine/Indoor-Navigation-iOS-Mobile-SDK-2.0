#import "NCExport.h"
#import "NCRouteEventType.h"
#import <Foundation/Foundation.h>

NAVIGINE_EXPORT
@interface NCRouteEvent : NSObject
- (nonnull instancetype)initWithType:(NCRouteEventType)type
                               value:(int32_t)value
                            distance:(float)distance;
+ (nonnull instancetype)routeEventWithType:(NCRouteEventType)type
                                     value:(int32_t)value
                                  distance:(float)distance;

@property (nonatomic, readonly) NCRouteEventType type;

@property (nonatomic, readonly) int32_t value;

@property (nonatomic, readonly) float distance;

@end
