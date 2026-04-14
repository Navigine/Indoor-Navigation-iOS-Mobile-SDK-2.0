#import <Foundation/Foundation.h>

/**
 * @file NCTurnType.h
 * @brief @copybrief NCTurnType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Enum describing turn direction/severity for @see TurnEvent "TurnEvent".
 *
 * Referenced from @see TurnEvent "TurnEvent".
 *
 *
 *
 *Swift code snippet:
 *@snippet RouteManagerExample.swift swift_TurnType_values
 *
 *Objective C code snippet:
 *@snippet RouteManagerExample.m objc_TurnType_values
 *
 *
 */
typedef NS_ENUM(NSInteger, NCTurnType)
{
    /**
     * Minor left adjustment (approx. 10°–40°).
     */
    NCTurnTypeLEFTSLIGHT,
    /**
     * Standard left turn (approx. 40°–100°).
     */
    NCTurnTypeLEFTNORMAL,
    /**
     * Sharp left turn (approx. 100°–160°).
     */
    NCTurnTypeLEFTSHARP,
    /**
     * Minor right adjustment (approx. 10°–40°).
     */
    NCTurnTypeRIGHTSLIGHT,
    /**
     * Standard right turn (approx. 40°–100°).
     */
    NCTurnTypeRIGHTNORMAL,
    /**
     * Sharp right turn (approx. 100°–160°).
     */
    NCTurnTypeRIGHTSHARP,
    /**
     * Near U-turn / reversal (approx. 160°–180°).
     */
    NCTurnTypeCOMPLETE,
};
