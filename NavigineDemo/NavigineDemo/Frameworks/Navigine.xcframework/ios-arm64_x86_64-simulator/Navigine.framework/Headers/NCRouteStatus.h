#import <Foundation/Foundation.h>

/**
 * @file NCRouteStatus.h
 * @brief @copybrief NCRouteStatus
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Enum describing possible router states.
 *
 * Referenced from @see AsyncRouteListener "AsyncRouteListener".
 *
 *
 * Swift code snippet:
 * @snippet AsyncRouteManagerExample.swift swift_RouteStatus_values
 *
 * Objective C code snippet:
 * @snippet AsyncRouteManagerExample.m objc_RouteStatus_values
 *
 *
 */
typedef NS_ENUM(NSInteger, NCRouteStatus)
{
    /**
     * @brief Router is missing the route graph.
     */
    NCRouteStatusMissingGraph,
    /**
     * @brief Router is missing the current position.
     */
    NCRouteStatusMissingPosition,
    /**
     * @brief Router unable to find the route to the destination point.
     */
    NCRouteStatusMissingRoute,
    /**
     * @brief Current position is off the route graph.
     */
    NCRouteStatusMissingProjection,
    /**
     * @brief Router is ready and has a valid route.
     */
    NCRouteStatusNewRoute,
};
