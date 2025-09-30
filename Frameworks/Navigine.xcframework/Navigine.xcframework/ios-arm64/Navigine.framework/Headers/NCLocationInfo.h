#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLocationInfo.h
 * @brief @copybrief NCLocationInfo
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief General information about location
 *
 * Referenced from: @see LocationListListener "LocationListListener", @see LocationListListener "LocationListListener"
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationInfo : NSObject

/** 
 * @brief Default constructor for class NCLocationInfo 
 */
- (nonnull instancetype)initWithId:(int32_t)id
                           version:(int32_t)version
                              name:(nonnull NSString *)name;

/** 
 * @brief Factory method for class NCLocationInfo 
 */
+ (nonnull instancetype)locationInfoWithId:(int32_t)id
                                   version:(int32_t)version
                                      name:(nonnull NSString *)name;

/**
 * @brief Unique location identifier.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationInfo_getId
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationInfo_getId
 *
 *
 */
@property (nonatomic, readonly) int32_t id;

/**
 * @brief Current location version.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationInfo_getVersion
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationInfo_getVersion
 *
 *
 */
@property (nonatomic, readonly) int32_t version;

/**
 * @brief location name.
 *
 *
 * Swift code snippet:
 * @snippet LocationListManagerExample.swift swift_LocationInfo_getName
 *
 * Objective C code snippet:
 * @snippet LocationListManagerExample.m objc_LocationInfo_getName
 *
 *
 */
@property (nonatomic, readonly, nonnull) NSString * name;

@end
