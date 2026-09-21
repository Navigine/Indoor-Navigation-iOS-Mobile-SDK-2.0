#import "NCExport.h"
#import "NCPlacement.h"
#import "NCRouteEndpoint.h"
#import "NCRouteRemainingStyle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCRouteView;
@protocol NCRouteLayerListener;
@protocol NCRouteViewListener;


/**
 * Layer that renders a route on the map as traveled and remaining polylines.
 * Independent from ``NCUserLocationLayer``: a route can be shown
 * without a user marker, and a user marker can be shown without a route.
 * Location and position are taken from the SDK automatically (same pattern as
 * ``NCUserLocationLayer``).
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteLayer : NSObject

/**
 * Shows or hides the route layer.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setVisible:YES];
 * NSLog(@"Route layer set visible");
 * @endcode
 */
- (void)setVisible:(BOOL)visible;

/**
 * Returns true if the route layer is visible.
 *
 * @discussion Example:
 * @code
 * BOOL visible = [_routeLayer isVisible];
 * NSLog(@"Route layer is visible: %d", visible);
 * @endcode
 */
- (BOOL)isVisible;

/**
 * Starts turn-by-turn guidance to the target from the current position.
 * @param target Destination endpoint. Route and progress are updated automatically.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setTarget:to];
 * NSLog(@"Guidance target applied");
 * @endcode
 */
- (void)setTarget:(nonnull NCRouteEndpoint *)target;

/**
 * Builds and shows a static route between two points (no live guidance).
 * @param from Route start endpoint.
 * @param to Route finish endpoint.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRouteFrom:from to:to];
 * NSLog(@"Static route applied");
 * @endcode
 */
- (void)setRoute:(nonnull NCRouteEndpoint *)from
              to:(nonnull NCRouteEndpoint *)to;

/**
 * Cancels guidance / static route and removes polylines from the map.
 *
 * @discussion Example:
 * @code
 * [_routeLayer clear];
 * NSLog(@"Route layer cleared");
 * @endcode
 */
- (void)clear;

/**
 * Returns currently rendered routes. V1 exposes a single active route.
 *
 * @discussion Example:
 * @code
 * NSArray<id<NCRouteView>> *routes = [_routeLayer routes];
 * NSLog(@"Visible routes: %lu", (unsigned long)routes.count);
 * @endcode
 */
- (nonnull NSArray<NCRouteView *> *)routes;

/**
 * Returns selected route view, or null when no route is selected.
 *
 * @discussion Example:
 * @code
 * id<NCRouteView> selectedRoute = [_routeLayer selectedRoute];
 * if (selectedRoute != nil) {
 *    NSLog(@"Selected route length: %f", [selectedRoute length]);
 * }
 * @endcode
 */
- (nullable NCRouteView *)selectedRoute;

/**
 * Selects the provided route view. Pass null to clear selection.
 * @param route Route view from ``NCRouteLayer``, or null.
 *
 * @discussion Example:
 * @code
 * if (routes.count > 0) {
 *    [_routeLayer selectRoute:routes.firstObject];
 * }
 * @endcode
 */
- (void)selectRoute:(nullable NCRouteView *)route;

/**
 * Adds listener for route lifecycle, progress and target reach events.
 *
 * @discussion Example:
 * @code
 * _routeLayerListener = [[DemoRouteLayerListener alloc] init];
 * [_routeLayer addRouteLayerListener:_routeLayerListener];
 * @endcode
 */
- (void)addRouteLayerListener:(nullable id<NCRouteLayerListener>)listener;

/**
 * Removes previously added route layer listener.
 */
- (void)removeRouteLayerListener:(nullable id<NCRouteLayerListener>)listener;

/**
 * Adds listener for route view list, selection and tap events.
 *
 * @discussion Example:
 * @code
 * _routeViewListener = [[DemoRouteViewListener alloc] init];
 * _routeViewListener.routeLayer = _routeLayer;
 * [_routeLayer addRouteViewListener:_routeViewListener];
 * @endcode
 */
- (void)addRouteViewListener:(nullable id<NCRouteViewListener>)listener;

/**
 * Removes previously added route view listener.
 */
- (void)removeRouteViewListener:(nullable id<NCRouteViewListener>)listener;

/**
 * Sets traveled (passed) route polyline color.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setTraveledColor:[UIColor colorWithRed:0.47 green:0.47 blue:0.47 alpha:0.7]];
 * NSLog(@"Traveled color updated");
 * @endcode
 */
- (void)setTraveledColor:(nonnull UIColor *)color;

/**
 * Sets remaining route polyline color.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingColor:[UIColor colorWithRed:0.19 green:0.67 blue:0.85 alpha:1.0]];
 * NSLog(@"Remaining color updated");
 * @endcode
 */
- (void)setRemainingColor:(nonnull UIColor *)color;

/**
 * Sets route polyline width in pixels (also used as default dotted point size).
 *
 * @discussion Example:
 * @code
 * [_routeLayer setWidth:8.0f];
 * NSLog(@"Route width updated");
 * @endcode
 */
- (void)setWidth:(float)width;

/**
 * Sets rendering style for the remaining route.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingStyle:NCRouteRemainingStyleDotted];
 * NSLog(@"Remaining style set to DOTTED");
 * @endcode
 */
- (void)setRemainingStyle:(NCRouteRemainingStyle)style;

/**
 * Returns the remaining route rendering style.
 *
 * @discussion Example:
 * @code
 * NCRouteRemainingStyle remainingStyle = [_routeLayer remainingStyle];
 * NSLog(@"Remaining style: %ld", (long)remainingStyle);
 * @endcode
 */
- (NCRouteRemainingStyle)remainingStyle;

/**
 * Sets dash length for DASHED remaining style. Use 0 to disable dashing.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingDashLength:0.5f];
 * NSLog(@"Remaining dash length updated");
 * @endcode
 */
- (void)setRemainingDashLength:(float)dashLength;

/**
 * Sets gap length for DASHED remaining style. Use 0 to disable dashing.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingGapLength:0.4f];
 * NSLog(@"Remaining gap length updated");
 * @endcode
 */
- (void)setRemainingGapLength:(float)gapLength;

/**
 * Sets point size for DOTTED remaining style.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingPointSize:8.0f height:8.0f];
 * NSLog(@"Remaining point size updated");
 * @endcode
 */
- (void)setRemainingPointSize:(float)width
                       height:(float)height;

/**
 * Sets point placement mode for DOTTED remaining style.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingPlacement:NCPlacementSpaced];
 * NSLog(@"Remaining placement updated");
 * @endcode
 */
- (void)setRemainingPlacement:(NCPlacement)placement;

/**
 * Sets spacing between points for DOTTED + SPACED placement (pixels).
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingPlacementSpacing:8.0f];
 * NSLog(@"Remaining placement spacing updated");
 * @endcode
 */
- (void)setRemainingPlacementSpacing:(float)spacing;

/**
 * Sets minimum polyline length ratio for DOTTED placement.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingPlacementMinRatio:0.0f];
 * NSLog(@"Remaining placement min ratio updated");
 * @endcode
 */
- (void)setRemainingPlacementMinRatio:(float)ratio;

/**
 * Enables or disables collision for DOTTED remaining points.
 *
 * @discussion Example:
 * @code
 * [_routeLayer setRemainingCollisionEnabled:NO];
 * NSLog(@"Remaining collision disabled");
 * @endcode
 */
- (void)setRemainingCollisionEnabled:(BOOL)enabled;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
