#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>

/**
 * Route endpoint in WGS84 coordinates.
 * When sublocationId is set, the endpoint is treated as indoor and projected
 * to that sublocation. When sublocationId is null, the endpoint is treated as
 * outdoor.
 * Referenced from ``NCRouteLayer``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteEndpoint : NSObject

/** 
 * Default constructor for class NCRouteEndpoint 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                        sublocationId:(nullable NSNumber *)sublocationId;

/** 
 * Factory method for class NCRouteEndpoint 
 */
+ (nonnull instancetype)routeEndpointWithPoint:(nonnull NCGlobalPoint *)point
                                 sublocationId:(nullable NSNumber *)sublocationId;

/**
 * Endpoint in WGS84 coordinates.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

/**
 * Floor id for an indoor endpoint, or null for outdoor.
 */
@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@end
