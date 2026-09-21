#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteProgress : NSObject

/** 
 * Default constructor for class NCRouteProgress 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                        sublocationId:(nullable NSNumber *)sublocationId
                              advance:(float)advance
                    remainingDistance:(float)remainingDistance
                             legIndex:(int32_t)legIndex;

/** 
 * Factory method for class NCRouteProgress 
 */
+ (nonnull instancetype)routeProgressWithPoint:(nonnull NCGlobalPoint *)point
                                 sublocationId:(nullable NSNumber *)sublocationId
                                       advance:(float)advance
                             remainingDistance:(float)remainingDistance
                                      legIndex:(int32_t)legIndex;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@property (nonatomic, readonly) float advance;

@property (nonatomic, readonly) float remainingDistance;

@property (nonatomic, readonly) int32_t legIndex;

@end
