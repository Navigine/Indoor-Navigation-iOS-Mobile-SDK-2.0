#import <Foundation/Foundation.h>

/**
 * @file NCDebugFlag.h
 * @brief @copybrief NCDebugFlag
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Debug visualization flags for the map view @see LocationWindow "LocationWindow".
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowCommonExample.swift swift_DebugFlag_enum
 *
 *Objective C code snippet:
 *@snippet LocationWindowCommonExample.m objc_DebugFlag_enum
 *
 *
 */
typedef NS_ENUM(NSInteger, NCDebugFlag)
{
    NCDebugFlagNone,
    NCDebugFlagInfos,
    NCDebugFlagStats,
    NCDebugFlagLabels,
    NCDebugFlagDrawAllLabels,
    NCDebugFlagSelectionBuffer,
};
