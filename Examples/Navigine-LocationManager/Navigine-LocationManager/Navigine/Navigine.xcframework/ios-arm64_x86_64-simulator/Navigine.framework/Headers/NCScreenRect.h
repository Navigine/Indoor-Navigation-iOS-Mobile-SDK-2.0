#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Rectangle on the device screen, in screen pixels (same units as ScreenPoint).
 * Used as `LocationWindow.focusRect` and with `getEnclosingCameraWithFocus`
 * so chrome (floor selector, follow-me, POI card) does not cover the fitted
 * geometry. Null / unset means the full viewport.
 * Origin is the top-left of the map view; +x right, +y down.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCScreenRect : NSObject

/** 
 * Default constructor for class NCScreenRect 
 */
- (nonnull instancetype)initWithTopLeft:(CGPoint)topLeft
                            bottomRight:(CGPoint)bottomRight;

/** 
 * Factory method for class NCScreenRect 
 */
+ (nonnull instancetype)screenRectWithTopLeft:(CGPoint)topLeft
                                  bottomRight:(CGPoint)bottomRight;

/**
 * Top-left corner ``NCScreenPoint``.
 */
@property (nonatomic, readonly) CGPoint topLeft;

/**
 * Bottom-right corner ``NCScreenPoint``.
 */
@property (nonatomic, readonly) CGPoint bottomRight;

@end
