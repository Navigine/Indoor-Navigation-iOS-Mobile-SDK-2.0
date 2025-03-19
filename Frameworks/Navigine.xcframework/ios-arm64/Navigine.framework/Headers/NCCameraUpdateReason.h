#import <Foundation/Foundation.h>

/**
 * @file NCCameraUpdateReason.h
 * @brief @copybrief NCCameraUpdateReason
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 * @brief Reason of the camera update.
 *
 * Referenced from @see CameraListener "CameraListener".
 *
 */
typedef NS_ENUM(NSInteger, NCCameraUpdateReason)
{
    /**
     * @brief user manipulation.
     *
     * For example: zoom, scroll, rotate, fling.
     */
    NCCameraUpdateReasonGestures,
    /**
     * @brief Application.
     *
     * By calling the LocationLiew::move methods.
     */
    NCCameraUpdateReasonApplication,
};
