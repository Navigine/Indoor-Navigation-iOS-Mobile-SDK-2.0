#import <Foundation/Foundation.h>

/** Describe zone event types */
typedef NS_ENUM(NSInteger, NCZoneEventType)
{
    /** Happens when user enters paticular zone; */
    NCZoneEventTypeEnter,
    /** Happens when user leaves paticular zone, sublocation has been changed or zone has been removed; */
    NCZoneEventTypeExit,
};
