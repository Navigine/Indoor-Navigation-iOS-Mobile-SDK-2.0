#import <Foundation/Foundation.h>

/**
 * @file NCRouteEventType.h
 * @brief @copybrief NCRouteEventType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Enum describing route event variants.
 *
 * Referenced from @see RouteEvent "RouteEvent".
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_RouteEventType_values
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_RouteEventType_values
 *
 *
 */
typedef NS_ENUM(NSInteger, NCRouteEventType)
{
    NCRouteEventTypeTURNEVENT,
    NCRouteEventTypeTRANSITIONENTRYEVENT,
    NCRouteEventTypeTRANSITIONEXITEVENT,
    NCRouteEventTypeTARGETREACHEDEVENT,
};
