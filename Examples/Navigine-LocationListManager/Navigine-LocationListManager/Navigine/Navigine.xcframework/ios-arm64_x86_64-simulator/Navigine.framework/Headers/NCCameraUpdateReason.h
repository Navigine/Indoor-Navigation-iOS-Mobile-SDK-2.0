#import <Foundation/Foundation.h>

/**
 * Reason of the camera update.
 * Referenced from ``NCCameraListener``.
 */
typedef NS_ENUM(NSInteger, NCCameraUpdateReason)
{
    /**
     * user manipulation.
     * For example: zoom, scroll, rotate, fling.
     */
    NCCameraUpdateReasonGestures,
    /**
     * Application.
     * By calling the LocationView::move methods.
     */
    NCCameraUpdateReasonApplication,
};
