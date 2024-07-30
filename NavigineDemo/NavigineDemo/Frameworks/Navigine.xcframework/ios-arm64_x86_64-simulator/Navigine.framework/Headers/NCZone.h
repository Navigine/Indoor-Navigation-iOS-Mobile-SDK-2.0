#import "NCExport.h"
#import "NCPolygon.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing zone in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCZone : NSObject

/** Metrics polygon of Zone (@see Polygon). */
@property (nonatomic, nonnull, readonly) NCPolygon * polygon;

/** Unique location identifier of Zone position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of Zone position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** Zone unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Zone name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Zone color. */
@property (nonatomic, nonnull, readonly) NSString * color;

/** Zone alias. */
@property (nonatomic, nonnull, readonly) NSString * alias;

@end
