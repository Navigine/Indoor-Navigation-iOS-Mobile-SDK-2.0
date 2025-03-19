#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCCameraCallback.h
 * @brief @copybrief NCCameraCallback
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief Callback specified after the camera movement is stopped
 *
 * Referenced from: @ref LocationWindow "LocationWindow".
 */

/**
 *
 * @brief Called when the move if finished.
 * @param completed determine whether the movement is finished or cancelled
 *
 */
typedef void (^NCCameraCallback)(BOOL completed);

