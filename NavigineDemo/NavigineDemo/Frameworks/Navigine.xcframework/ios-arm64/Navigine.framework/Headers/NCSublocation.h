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
 * @file NCSublocation.h
 * @brief @copybrief NCSublocation
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_elements
 * @brief Class is used for storing sublocation parameters: identifier, name, width, heigth, etc.
 *
 * The list of sublocations for the current location can be obtained from @see Location "Location" class using public method getSublocations.
 *
 * Referenced from @see Location "Location".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCSublocation : NSObject

/**
 * @brief Method is used to obtain origin sublocation image with specified maxTextureSize.
 * @param maxTextureSize maximum texure size to render.
 * @return platform image.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getImage
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getImage
 *
 *
 */
- (nullable UIImage *)getImage:(nullable NSNumber *)maxTextureSize;

/**
 * Method is used for converting the global geographic coordinates (latitude and longitude) to the local sublocation coordinates (x and y)
 * using the geographic binding of the sublocation
 * @param globalPoint point in WGS84 coordinates @see GlobalPoint "GlobalPoint"
 * @return point in metrics coordinates @see LocationPoint "LocationPoint".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_globalToLocal
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_globalToLocal
 *
 *
 */
- (nonnull NCLocationPoint *)globalToLocal:(nonnull NCGlobalPoint *)globalPoint;

/**
 * @brief Method is used for converting the local sublocation coordinates to the global geographic coordinates (latitude and longitude)
 * using the geographic binding of the sublocation.
 * @param localPoint point in metrics coordinates @see LocationPoint "LocationPoint"
 * @return point in WGS84 coordinates @see GlobalPoint "GlobalPoint".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_localToGlobal
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_localToGlobal
 *
 *
 */
- (nonnull NCGlobalPoint *)localToGlobal:(nonnull NCLocationPoint *)localPoint;

/**
 * @brief Method is used to obtain graph (within the current sublocation)
 * with the specified identifier or `null` if no such graph.
 * @param tag graph tag.
 * @return found graph or `null` @see Graph "Graph".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getGraph
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getGraph
 *
 *
 */
- (nullable NCGraph *)getGraph:(nonnull NSString *)tag;

/**
 * @brief Method returns the venue (within the current sublocation)
 * with the specified identifier or `null` if no such venue exists.
 * @param id venue unique identifier.
 * @return found venue object or `null` @see Venue "Venue".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getVenueById
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getVenueById
 *
 *
 */
- (nullable NCVenue *)getVenueById:(int32_t)id;

/**
 * @brief Method returns the zone (within the current sublocation)
 * with the specified identifier or `null` if no such zone exists.
 * @param id zone unique identifier.
 * @return found zone object or `null` @see Zone "Zone".
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getZoneById
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getZoneById
 *
 *
 */
- (nullable NCZone *)getZoneById:(int32_t)id;

/**
 * @brief sublocation's identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief location's identifier to which the sublocation belongs.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getLocation
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getLocation
 *
 *
 */
@property (nonatomic, readonly) int32_t location;

/**
 * @brief sublocation's name.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getName
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getName
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * name;

/**
 * @brief sublocation's width in meters.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getWidth
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getWidth
 *
 *
 */
@property (nonatomic, readonly) float width;

/**
 * @brief sublocation's height in meters.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getHeight
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getHeight
 *
 *
 */
@property (nonatomic, readonly) float height;

/**
 * @brief sublocation's altitude in meters if specified.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getAltitude
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getAltitude
 *
 *
 */
@property (nonatomic, nullable, readonly) NSNumber * altitude;

/**
 * @brief sublocation's azimuth in degrees clockwise.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getAzimuth
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getAzimuth
 *
 *
 */
@property (nonatomic, readonly) float azimuth;

/**
 * @brief sublocation's center point in WGS84 coordinates @see GlobalPoint "GlobalPoint".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getOriginPoint
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getOriginPoint
 *
 *
 */
@property (nonatomic, nonnull, readonly) NCGlobalPoint * originPoint;

/**
 * @brief sublocation's levelId.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getLevelId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getLevelId
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * levelId;

/**
 * @brief sublocation's externalId.
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getExternalId
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getExternalId
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSString * externalId;

/**
 * @brief List of beacons, attached to this sublocation @see Beacon "Beacon".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getBeacons
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getBeacons
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCBeacon *> * beacons;

/**
 * @brief List of eddystones, attached to this sublocation @see Eddystone "Eddystone".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getEddystones
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getEddystones
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCEddystone *> * eddystones;

/**
 * @brief List of wifis, attached to this sublocation @see Wifi "Wifi".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getWifis
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getWifis
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCWifi *> * wifis;

/**
 * @cond
 */
@property (nonatomic, nonnull, readonly) NSArray<NCReferencePoint *> * referencePoints;

/**
 * @endcond
 * @brief List of venues, attached to this sublocation @see Venue "Venue".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getVenues
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getVenues
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCVenue *> * venues;

/**
 * @brief List of zones, attached to this sublocation @see Zone "Zone".
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_Sublocation_getZones
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_Sublocation_getZones
 *
 *
 */
@property (nonatomic, nonnull, readonly) NSArray<NCZone *> * zones;

@end
