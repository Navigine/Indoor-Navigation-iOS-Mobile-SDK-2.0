#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLocationPoint.h
 * @brief @copybrief NCLocationPoint
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief Class is used for representing certain point within the location.
 *
 * Referenced from: @ref AsyncRouteListener "AsyncRouteListener", @ref AsyncRouteManager "AsyncRouteManager", @ref CircleMapObject "CircleMapObject",
 * @ref IconMapObject "IconMapObject", @ref MapObjectPickResult "MapObjectPickResult",
 * @ref NavigationManager "NavigationManager", @ref Notification "Notification", @ref Position "Position", @ref RouteManager "RouteManager",
 * @ref RoutePath "RoutePath", @ref Sublocation "Sublocation", @ref Venue "Venue".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPoint : NSObject

/** 
 * @brief Default constructor for class NCLocationPoint 
 */
- (nonnull instancetype)initWithPoint:(nonnull NCPoint *)point
                           locationId:(int32_t)locationId
                        sublocationId:(int32_t)sublocationId;

/** 
 * @brief Factory method for class NCLocationPoint 
 */
+ (nonnull instancetype)locationPointWithPoint:(nonnull NCPoint *)point
                                    locationId:(int32_t)locationId
                                 sublocationId:(int32_t)sublocationId;

/**
 * @brief location point X and Y coordinates in meters as Point (within the sublocation).
 */
@property (nonatomic, readonly, nonnull) NCPoint * point;

/**
 * @brief location point location identifier.
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * @brief location point sublocation identifier.
 */
@property (nonatomic, readonly) int32_t sublocationId;

@end
