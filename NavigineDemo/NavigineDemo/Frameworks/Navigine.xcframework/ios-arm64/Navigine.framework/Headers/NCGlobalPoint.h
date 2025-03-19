#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCGlobalPoint.h
 * @brief @copybrief NCGlobalPoint
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A point at the specified WGS84 coordinates.
 *
 * Referenced from @see GeometryUtils "GeometryUtils", @see NavigationManager "NavigationManager", @see Position "Position", @see Sublocation "Sublocation".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCGlobalPoint : NSObject

/** 
 * @brief Default constructor for class NCGlobalPoint 
 */
- (nonnull instancetype)initWithLatitude:(double)latitude
                               longitude:(double)longitude;

/** 
 * @brief Factory method for class NCGlobalPoint 
 */
+ (nonnull instancetype)globalPointWithLatitude:(double)latitude
                                      longitude:(double)longitude;

/**
 * @brief point's latitude.
 */
@property (nonatomic, readonly) double latitude;

/**
 * @brief point's longitude.
 */
@property (nonatomic, readonly) double longitude;

@end
