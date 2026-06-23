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
 * Class is used for storing sublocation parameters: identifier, name, width, height, etc.
 * The list of sublocations for the current location can be obtained from ``NCLocation`` class using public method getSublocations.
 * Referenced from ``NCLocation``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSublocation : NSObject

/**
 * Method is used to obtain origin sublocation image with specified maxTextureSize.
 * @param maxTextureSize maximum texture size to render.
 * @return platform image.
 *
 * @discussion Example:
 * @code
 * // Get sublocation image
 * NCImageWrapper *image = [sublocation getImage:@1024]; // max texture size 1024
 * if (image != nil) {
 *    NSLog(@"Sublocation image obtained with max texture size 1024");
 * }
 * @endcode
 */
- (nullable UIImage *)getImage:(nullable NSNumber *)maxTextureSize;

/**
 * Method is used for converting the global geographic coordinates (latitude and longitude) to the local sublocation coordinates (x and y)
 * using the geographic binding of the sublocation
 * @param globalPoint point in WGS84 coordinates ``NCGlobalPoint``
 * @return point in metrics coordinates ``NCLocationPoint``.
 *
 * @discussion Example:
 * @code
 * // Convert global coordinates to local coordinates
 * NCGlobalPoint *globalPoint = [[NCGlobalPoint alloc] initWithLat:55.7558 lon:37.6176]; // Moscow coordinates
 * NCLocationPoint *localPoint = [sublocation globalToLocal:globalPoint];
 * NSLog(@"Global point %.6f, %.6f converted to local: %.2f, %.2f",
 *      [globalPoint getLat], [globalPoint getLon], [localPoint getX], [localPoint getY]);
 * @endcode
 */
- (nonnull NCLocationPoint *)globalToLocal:(nonnull NCGlobalPoint *)globalPoint;

/**
 * Method is used for converting the local sublocation coordinates to the global geographic coordinates (latitude and longitude)
 * using the geographic binding of the sublocation.
 * @param localPoint point in metrics coordinates ``NCLocationPoint``
 * @return point in WGS84 coordinates ``NCGlobalPoint``.
 *
 * @discussion Example:
 * @code
 * // Convert local coordinates to global coordinates
 * NCLocationPoint *localPoint2 = [[NCLocationPoint alloc] initWithX:100.0 y:200.0];
 * NCGlobalPoint *globalPoint2 = [sublocation localToGlobal:localPoint2];
 * NSLog(@"Local point %.2f, %.2f converted to global: %.6f, %.6f",
 *      [localPoint2 getX], [localPoint2 getY], [globalPoint2 getLat], [globalPoint2 getLon]);
 * @endcode
 */
- (nonnull NCGlobalPoint *)localToGlobal:(nonnull NCLocationPoint *)localPoint;

/**
 * Method is used to obtain graph (within the current sublocation)
 * with the specified identifier or `null` if no such graph.
 * @param tag graph tag.
 * @return found graph or `null` ``NCGraph``.
 *
 * @discussion Example:
 * @code
 * // Get graph
 * NCGraph *graph = [sublocation getGraph];
 * if (graph != nil) {
 *    [self demonstrateGraphUsage:graph];
 * }
 * @endcode
 */
- (nullable NCGraph *)getGraph:(nonnull NSString *)tag;

/**
 * Method returns the venue (within the current sublocation)
 * with the specified identifier or `null` if no such venue exists.
 * @param id venue unique identifier.
 * @return found venue object or `null` ``NCVenue``.
 *
 * @discussion Example:
 * @code
 * // Get venue by ID
 * if (venues.count > 0) {
 *    NCVenue *venueById = [sublocation getVenueById:[venues.firstObject getId]];
 *    if (venueById != nil) {
 *        NSLog(@"Found venue by ID: %d", [venueById getId]);
 *        [self demonstrateVenueUsage:venueById];
 *    }
 * }
 * @endcode
 */
- (nullable NCVenue *)getVenueById:(int32_t)id;

/**
 * Method returns the zone (within the current sublocation)
 * with the specified identifier or `null` if no such zone exists.
 * @param id zone unique identifier.
 * @return found zone object or `null` ``NCZone``.
 *
 * @discussion Example:
 * @code
 * // Get zone by ID
 * if (zones.count > 0) {
 *    NCZone *zoneById = [sublocation getZoneById:[zones.firstObject getId]];
 *    if (zoneById != nil) {
 *        NSLog(@"Found zone by ID: %d", [zoneById getId]);
 *        [self demonstrateZoneUsage:zoneById];
 *    }
 * }
 * @endcode
 */
- (nullable NCZone *)getZoneById:(int32_t)id;

/**
 * sublocation's identifier.
 *
 * @discussion Example:
 * @code
 * // Get sublocation ID
 * int32_t sublocationId = [sublocation getId];
 * NSLog(@"Sublocation ID: %d", sublocationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t id;

/**
 * location's identifier to which the sublocation belongs.
 *
 * @discussion Example:
 * @code
 * // Get location ID
 * int32_t locationId = [sublocation getLocation];
 * NSLog(@"Sublocation location ID: %d", locationId);
 * @endcode
 */
@property (nonatomic, readonly) int32_t location;

/**
 * sublocation's name.
 *
 * @discussion Example:
 * @code
 * // Get sublocation name
 * NSString *sublocationName = [sublocation getName];
 * NSLog(@"Sublocation name: %@", sublocationName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * sublocation's width in meters.
 *
 * @discussion Example:
 * @code
 * // Get sublocation width in meters
 * double width = [sublocation getWidth];
 * NSLog(@"Sublocation width: %.2f meters", width);
 * @endcode
 */
@property (nonatomic, readonly) float width;

/**
 * sublocation's height in meters.
 *
 * @discussion Example:
 * @code
 * // Get sublocation height in meters
 * double height = [sublocation getHeight];
 * NSLog(@"Sublocation height: %.2f meters", height);
 * @endcode
 */
@property (nonatomic, readonly) float height;

/**
 * sublocation's altitude in meters if specified.
 *
 * @discussion Example:
 * @code
 * // Get sublocation altitude in meters
 * NSNumber *altitude = [sublocation getAltitude];
 * if (altitude != nil) {
 *    NSLog(@"Sublocation altitude: %.2f meters", [altitude doubleValue]);
 * }
 * @endcode
 */
@property (nonatomic, nullable, readonly) NSNumber * altitude;

/**
 * sublocation's azimuth in degrees clockwise.
 *
 * @discussion Example:
 * @code
 * // Get sublocation azimuth in degrees
 * double azimuth = [sublocation getAzimuth];
 * NSLog(@"Sublocation azimuth: %.2f degrees", azimuth);
 * @endcode
 */
@property (nonatomic, readonly) float azimuth;

/**
 * sublocation's center point in WGS84 coordinates ``NCGlobalPoint``.
 *
 * @discussion Example:
 * @code
 * // Get sublocation origin point in WGS84 coordinates
 * NCGlobalPoint *originPoint = [sublocation getOriginPoint];
 * NSLog(@"Sublocation origin point: %.6f, %.6f", [originPoint getLat], [originPoint getLon]);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NCGlobalPoint * originPoint;

/**
 * sublocation's levelId.
 *
 * @discussion Example:
 * @code
 * // Get sublocation level ID
 * NSString *levelId = [sublocation getLevelId];
 * NSLog(@"Sublocation level ID: %@", levelId);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * levelId;

/**
 * sublocation's externalId.
 *
 * @discussion Example:
 * @code
 * // Get sublocation external ID
 * NSString *externalId = [sublocation getExternalId];
 * NSLog(@"Sublocation external ID: %@", externalId);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * externalId;

/**
 * sublocation's building name (e.g. "Outdoor" for overview plan).
 *
 * @discussion Example:
 * @code
 * // Get sublocation building name
 * NSString *buildingName = [sublocation getBuildingName];
 * NSLog(@"Sublocation building name: %@", buildingName);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSString * buildingName;

/**
 * List of beacons, attached to this sublocation ``NCBeacon``.
 *
 * @discussion Example:
 * @code
 * // Get beacons
 * NSArray<NCBeacon *> *beacons = [sublocation getBeacons];
 * NSLog(@"Number of beacons: %lu", (unsigned long)beacons.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCBeacon *> * beacons;

/**
 * List of eddystones, attached to this sublocation ``NCEddystone``.
 *
 * @discussion Example:
 * @code
 * // Get Eddystone beacons
 * NSArray<NCEddystone *> *eddystones = [sublocation getEddystones];
 * NSLog(@"Number of Eddystone beacons: %lu", (unsigned long)eddystones.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCEddystone *> * eddystones;

/**
 * List of wifis, attached to this sublocation ``NCWifi``.
 *
 * @discussion Example:
 * @code
 * // Get WiFi access points
 * NSArray<NCWifi *> *wifis = [sublocation getWifis];
 * NSLog(@"Number of WiFi access points: %lu", (unsigned long)wifis.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCWifi *> * wifis;

@property (nonatomic, nonnull, readonly) NSArray<NCReferencePoint *> * referencePoints;

/**
 * List of venues, attached to this sublocation ``NCVenue``.
 *
 * @discussion Example:
 * @code
 * // Get venues
 * NSArray<NCVenue *> *venues = [sublocation getVenues];
 * NSLog(@"Number of venues: %lu", (unsigned long)venues.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCVenue *> * venues;

/**
 * List of zones, attached to this sublocation ``NCZone``.
 *
 * @discussion Example:
 * @code
 * // Get zones
 * NSArray<NCZone *> *zones = [sublocation getZones];
 * NSLog(@"Number of zones: %lu", (unsigned long)zones.count);
 * @endcode
 */
@property (nonatomic, nonnull, readonly) NSArray<NCZone *> * zones;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
