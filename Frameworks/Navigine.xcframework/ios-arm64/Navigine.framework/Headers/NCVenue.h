#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


/**
 * Class is used for storing venue.
 * Referenced from ``NCSublocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVenue : NSObject

/**
 * venue's X and Y coordinates in meters as ``NCPoint`` (within the sublocation).
 *
 * @discussion Example:
 * @code
 * // Get venue point
 * NCPoint *point = [venue getPoint];
 * if (point != nil) {
 *    [self demonstratePointUsage:point];
 * }
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/**
 * venue's location identifier.
 *
 * @discussion Example:
 * @code
 * // Get venue location ID
 * int32_t locationId = [venue getLocationId];
 * NSLog(@"Venue location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t locationId;

/**
 * venue's sublocation identifier.
 *
 * @discussion Example:
 * @code
 * // Get venue sublocation ID
 * int32_t sublocationId = [venue getSublocationId];
 * NSLog(@"Venue sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t sublocationId;

/**
 * venue's identifier.
 *
 * @discussion Example:
 * @code
 * // Get venue ID
 * int32_t venueId = [venue getId];
 * NSLog(@"Venue ID: %d", venueId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * venue's name.
 *
 * @discussion Example:
 * @code
 * // Get venue name
 * NSString *venueName = [venue getName];
 * NSLog(@"Venue name: %@", venueName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * venue's phone.
 *
 * @discussion Example:
 * @code
 * // Get venue phone
 * NSString *phone = [venue getPhone];
 * NSLog(@"Venue phone: %@", phone);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * phone;

/**
 * venue's description.
 *
 * @discussion Example:
 * @code
 * // Get venue description
 * NSString *venueDescription = [venue getDescript];
 * NSLog(@"Venue description: %@", venueDescription);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * descript;

/**
 * venue's alias.
 *
 * @discussion Example:
 * @code
 * // Get venue alias
 * NSString *alias = [venue getAlias];
 * NSLog(@"Venue alias: %@", alias);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * alias;

/**
 * venue's category unique identifier ``NCCategory``
 *
 * @discussion Example:
 * @code
 * // Get category ID
 * int32_t categoryId = [venue getCategoryId];
 * NSLog(@"Venue category ID: %d", categoryId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t categoryId;

/**
 * venue's image url if specified.
 *
 * @discussion Example:
 * @code
 * // Get venue image URL
 * NSString *imageUrl = [venue getImageUrl];
 * if (imageUrl != nil) {
 *    NSLog(@"Venue image URL: %@", imageUrl);
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSString * imageUrl;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
