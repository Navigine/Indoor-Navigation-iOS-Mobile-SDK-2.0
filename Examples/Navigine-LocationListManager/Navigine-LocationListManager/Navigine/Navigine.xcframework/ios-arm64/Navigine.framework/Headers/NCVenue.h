#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing venue in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVenue : NSObject

/** Metrics coordinate of Venue position (@see Point). */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/** Unique location identifier of Venue position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of Venue position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** Venue unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Venue name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Venue phone. */
@property (nonatomic, nonnull, readonly) NSString * phone;

/** Venue description. */
@property (nonatomic, nonnull, readonly) NSString * descript;

/** Venue alias. */
@property (nonatomic, nonnull, readonly) NSString * alias;

/** Venue category unique identifier (@Category). */
@property (nonatomic, readonly) int32_t categoryId;

/** Venue image url if specified. */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

@end
