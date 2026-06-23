#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * Class is used for representing certain point within the location.
 * Referenced from: ``NCAsyncRouteListener``, ``NCAsyncRouteManager``, ``NCCircleMapObject``,
 * ``NCIconMapObject``, ``NCMapObjectPickResult``,
 * ``NCNavigationManager``, ``NCNotification``, ``NCPosition``, ``NCRouteManager``,
 * ``NCRoutePath``, ``NCSublocation``, ``NCVenue``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPoint : NSObject

/** 
 * Default constructor for class NCLocationPoint 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                           locationId:(int32_t)locationId
                        sublocationId:(int32_t)sublocationId;

/** 
 * Factory method for class NCLocationPoint 
 */
+ (nonnull instancetype)locationPointWithPoint:(nonnull NCPoint *)point
                                    locationId:(int32_t)locationId
                                 sublocationId:(int32_t)sublocationId;

/**
 * location point X and Y coordinates in meters as Point (within the sublocation).
 */
@property (nonatomic, readonly, nonnull) NCPoint * point;

/**
 * location point location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * location point sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
