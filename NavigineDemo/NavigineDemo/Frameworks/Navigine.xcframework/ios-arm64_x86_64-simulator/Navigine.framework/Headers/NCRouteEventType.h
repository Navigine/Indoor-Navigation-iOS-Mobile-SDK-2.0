#import <Foundation/Foundation.h>

/** Available route events */
typedef NS_ENUM(NSInteger, NCRouteEventType)
{
    /** An event showing a left turn. */
    NCRouteEventTypeTURNLEFT,
    /** An event showing a right turn. */
    NCRouteEventTypeTURNRIGHT,
    /** An event showing a chaning of sublocation (floor). */
    NCRouteEventTypeTRANSITION,
};
