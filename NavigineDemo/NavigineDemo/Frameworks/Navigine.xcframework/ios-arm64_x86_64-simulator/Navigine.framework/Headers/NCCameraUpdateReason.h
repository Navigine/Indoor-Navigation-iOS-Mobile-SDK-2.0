#import <Foundation/Foundation.h>

/** Reason of the camera update. */
typedef NS_ENUM(NSInteger, NCCameraUpdateReason)
{
    /** User manipulation, for example: zoom, scroll, rotate, fling. */
    NCCameraUpdateReasonGestures,
    /** Application, by calling the LocationLiew::move methods. */
    NCCameraUpdateReasonApplication,
};
