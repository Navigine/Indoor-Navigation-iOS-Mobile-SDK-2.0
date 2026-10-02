#import "NCExport.h"
#import "NCLocationPolyline.h"
#import "NCRouteSimulatorSample.h"
#import <Foundation/Foundation.h>
@protocol NCRouteSimulatorListener;


/**
 * Walks a polyline at a constant speed for demos and guidance QA.
 * Distinct from ``NCMeasurementManager`` signal generators.
 * Does not publish a navigation position and does not move the user-location layer.
 * Hosts apply `sample` to an icon or other preview.
 * Created with ``NCNavigineSdk`` `getRouteSimulator`.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteSimulator : NSObject

/**
 * Geometry in walk order. A later polyline may be on another floor.
 * @return false when fewer than two distinct points were given.
 *
 * @discussion Example:
 * @code
 * NCLocationPolyline *walk = [[NCLocationPolyline alloc] initWithPoints:@[
 *    [[NCGlobalPoint alloc] initWithLatitude:55.751 longitude:37.618],
 *    [[NCGlobalPoint alloc] initWithLatitude:55.752 longitude:37.618],
 * ] sublocationId:nil];
 * [routeSimulator setGeometry:@[walk]];
 * @endcode
 */
- (BOOL)setGeometry:(nonnull NSArray<NCLocationPolyline *> *)polylines;

/**
 * Walking speed in meters per second. Default is 1.4. Zero pauses motion.
 *
 * @discussion Example:
 * @code
 * [routeSimulator setSpeed:1.4f];
 * @endcode
 */
- (void)setSpeed:(float)metersPerSecond;

/**
 * Current speed in meters per second.
 */
- (float)speed;

/**
 * Starts from the beginning, or continues when already active.
 * @return false when geometry is missing.
 *
 * @discussion Example:
 * @code
 * BOOL started = [routeSimulator start];
 * NSLog(@"Route walk started: %@", started ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)start;

/**
 * Stops and rewinds to the start. Does not emit `onFinished`.
 */
- (void)stop;

/**
 * True while a walk is in progress.
 */
- (BOOL)active;

/**
 * Latest sample, or null before the first tick.
 *
 * @discussion Example:
 * @code
 * NCRouteSimulatorSample *sample = [routeSimulator sample];
 * if (sample) {
 *    NSLog(@"Walk advance: %f m", sample.advance);
 * }
 * @endcode
 */
- (nullable NCRouteSimulatorSample *)sample;

- (void)addListener:(nullable id<NCRouteSimulatorListener>)listener;

- (void)removeListener:(nullable id<NCRouteSimulatorListener>)listener;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
