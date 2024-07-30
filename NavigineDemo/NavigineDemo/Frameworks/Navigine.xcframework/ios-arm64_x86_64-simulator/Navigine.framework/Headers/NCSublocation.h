#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCBeacon;
@class NCEddystone;
@class NCGraph;
@class NCReferencePoint;
@class NCVenue;
@class NCWifi;
@class NCZone;


/**
 *
 * Object describing sublocation in CMS.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSublocation : NSObject

/**
 * Method is used to get sublocation image
 * @param maxTextureSize - maximum texure size to render.
 * @return - platform image.
 */
- (nullable UIImage *)getImage:(nullable NSNumber *)maxTextureSize;

/**
 * Method is used to convert WGS84 coordinates to metrics
 * @param globalPoint - point in WGS84 coordinates (@see GlobalPoint)
 * @return - point in metrics coordinates (@see LocationPoint).
 */
- (nonnull NCLocationPoint *)globalToLocal:(nonnull NCGlobalPoint *)globalPoint;

/**
 * Method is used to convert metrics coordinates to WGS84
 * @param localPoint - point in metrics coordinates (@see LocationPoint)
 * @return - point in WGS84 coordinates (@see GlobalPoint).
 */
- (nonnull NCGlobalPoint *)localToGlobal:(nonnull NCLocationPoint *)localPoint;

/**
 * Method is used to find graph by tag.
 * @param tag - graph tag.
 * @return - found graph or null (@see Graph).
 */
- (nullable NCGraph *)getGraph:(nonnull NSString *)tag;

/**
 * Method is used to find venue by id.
 * @param id - venue unique identifier.
 * @return - found venue object or null (@see Venue).
 */
- (nullable NCVenue *)getVenueById:(int32_t)id;

/**
 * Method is used to find zone by id.
 * @param id - zone unique identifier.
 * @return - found zone object or null (@see Zone).
 */
- (nullable NCZone *)getZoneById:(int32_t)id;

/** Sublocation unique identifier. */
@property (nonatomic, readonly) int32_t id;

/** Location unique identifier to which the sublocation belongs. */
@property (nonatomic, readonly) int32_t location;

/** Sublocation name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Sublocation width in meters. */
@property (nonatomic, readonly) float width;

/** Sublocation height in meters. */
@property (nonatomic, readonly) float height;

/** Sublocation altitude in meters if specified. */
@property (nonatomic, nullable, readonly) NSNumber * altitude;

/** Sublocation azimuth in degrees. */
@property (nonatomic, readonly) float azimuth;

/** Sublocation center point in WGS84 coordinates (@see GlobalPoint). */
@property (nonatomic, nonnull, readonly) NCGlobalPoint * originPoint;

/** Sublocation levelId. */
@property (nonatomic, nonnull, readonly) NSString * levelId;

/** Sublocation externalId. */
@property (nonatomic, nonnull, readonly) NSString * externalId;

/** List of iBeacons installed on sublocation (@see Beacon). */
@property (nonatomic, nonnull, readonly) NSArray<NCBeacon *> * beacons;

/** List of eddystones installed on sublocation (@see Eddystone). */
@property (nonatomic, nonnull, readonly) NSArray<NCEddystone *> * eddystones;

/** List of wifis installed on sublocation (@see Wifi). */
@property (nonatomic, nonnull, readonly) NSArray<NCWifi *> * wifis;

/** @internal */
@property (nonatomic, nonnull, readonly) NSArray<NCReferencePoint *> * referencePoints;

/** List of venues installed on sublocation (@see Venue). */
@property (nonatomic, nonnull, readonly) NSArray<NCVenue *> * venues;

/** List of zones installed on sublocation (@see zones). */
@property (nonatomic, nonnull, readonly) NSArray<NCZone *> * zones;

@end
