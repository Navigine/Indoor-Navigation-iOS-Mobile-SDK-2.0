#import "NCExport.h"
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
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
