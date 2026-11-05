#import "NCExport.h"
#import "NCUserLocationFollowMode.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 * Layer that automatically renders current user position (arrow and accuracy circle) on the map.
 * Provides visibility and anchoring controls.
 * Referenced from ``NCLocationView``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCUserLocationLayer : NSObject

/**
 * Shows or hides user location layer.
 *
 * @discussion Example:
 * @code
 * [_userLocationLayer setVisible:YES];
 * NSLog(@"User location layer set visible");
 * @endcode
 */
- (void)setVisible:(BOOL)visible;

/**
 * Returns true if user location layer is visible.
 *
 * @discussion Example:
 * @code
 * BOOL visible = [_userLocationLayer isVisible];
 * NSLog(@"User location layer is visible: %@", visible ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)isVisible;

/**
 * Sets anchor point for user indicator in screen pixels.
 *
 * @discussion Example:
 * @code
 * NCScreenPoint *anchor = [[NCScreenPoint alloc] initWithX:100.0f y:200.0f];
 * [_userLocationLayer setAnchor:anchor];
 * NSLog(@"Set user location anchor to: (%.1f, %.1f)", anchor.x, anchor.y);
 * @endcode
 */
- (void)setAnchor:(CGPoint)anchor;

/**
 * Resets anchor to default (center).
 *
 * @discussion Example:
 * @code
 * [_userLocationLayer resetAnchor];
 * NSLog(@"Anchor reset to default");
 * @endcode
 */
- (void)resetAnchor;

/**
 * Returns true if custom anchor is enabled.
 *
 * @discussion Example:
 * @code
 * BOOL anchorEnabled = [_userLocationLayer anchorEnabled];
 * NSLog(@"Anchor enabled: %@", anchorEnabled ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)anchorEnabled;

/**
 * Enables or disables heading-up mode while the user location layer is anchored.
 * When enabled and a location heading is available, the map camera rotates to keep
 * the user's heading pointed toward the top of the screen. Without an anchor the
 * location icon keeps rotating independently.
 *
 * @discussion Example:
 * @code
 * [_userLocationLayer setHeadingModeActive:YES];
 * NSLog(@"Heading-up mode enabled");
 * @endcode
 */
- (void)setHeadingModeActive:(BOOL)active;

/**
 * Returns true if heading-up mode is enabled.
 * Same as followMode() == HEADING.
 *
 * @discussion Example:
 * @code
 * BOOL headingModeActive = [_userLocationLayer headingModeActive];
 * NSLog(@"Heading-up mode active: %@", headingModeActive ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)headingModeActive;

/**
 * Sets how the camera follows the user.
 * NONE stops following and keeps a previously set anchor point.
 * POSITION, HEADING and COURSE follow even without setAnchor (screen center).
 * setAnchor() from NONE switches to POSITION. resetAnchor() switches to NONE.
 * setHeadingModeActive(true) switches to HEADING.
 *
 * @discussion Example:
 * @code
 * [_userLocationLayer setFollowMode:NCUserLocationFollowModeHEADING];
 * NSLog(@"Follow mode set to heading");
 * @endcode
 */
- (void)setFollowMode:(NCUserLocationFollowMode)mode;

/**
 * Returns the current follow mode.
 *
 * @discussion Example:
 * @code
 * NCUserLocationFollowMode followMode = [_userLocationLayer followMode];
 * NSLog(@"Follow mode: %ld", (long)followMode);
 * @endcode
 */
- (NCUserLocationFollowMode)followMode;

/**
 * Replaces the heading arrow bitmap.
 * Null restores the built-in heading fan.
 *
 * @discussion Example:
 * @code
 * UIImage *arrow = [UIImage imageWithContentsOfFile:@"/path/to/arrow.png"];
 * if (arrow != nil) {
 *    [_userLocationLayer setArrowBitmap:arrow];
 * }
 * [_userLocationLayer setArrowBitmap:nil];
 * NSLog(@"Custom arrow bitmap cleared");
 * @endcode
 */
- (void)setArrowBitmap:(nullable UIImage *)bitmap;

/**
 * Sets the accuracy-circle fill. Default is a translucent blue.
 *
 * @discussion Example:
 * @code
 * [_userLocationLayer setAccuracyColor:[UIColor colorWithRed:0.19 green:0.67 blue:0.85 alpha:0.26]];
 * NSLog(@"Accuracy circle color updated");
 * @endcode
 */
- (void)setAccuracyColor:(nonnull UIColor *)color;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
