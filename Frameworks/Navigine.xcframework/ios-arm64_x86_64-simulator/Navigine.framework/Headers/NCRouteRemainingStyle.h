#import <Foundation/Foundation.h>

/**
 * Rendering style for the remaining (not yet traveled) part of the route.
 * Referenced from ``NCRouteLayer``.
 */
typedef NS_ENUM(NSInteger, NCRouteRemainingStyle)
{
    /**
     * Continuous solid polyline.
     */
    NCRouteRemainingStyleSOLID,
    /**
     * Dashed polyline (see setRemainingDashLength / setRemainingGapLength).
     */
    NCRouteRemainingStyleDASHED,
    /**
     * Points placed along the route (``NCDottedPolylineMapObject``).
     */
    NCRouteRemainingStyleDOTTED,
};
