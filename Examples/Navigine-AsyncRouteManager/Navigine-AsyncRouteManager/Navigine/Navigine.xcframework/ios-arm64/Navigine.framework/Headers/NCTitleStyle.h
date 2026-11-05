#import "NCExport.h"
#import "NCTitleAnchor.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Style parameters for a map object title.
 * Used with ``NCMapObject`` `setTitleWithStyle`.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCTitleStyle : NSObject

/** 
 * Default constructor for class NCTitleStyle 
 */
- (nonnull instancetype)initWithFontSize:(float)fontSize
                                   color:(nonnull UIColor *)color
                            outlineColor:(nonnull UIColor *)outlineColor
                            outlineWidth:(float)outlineWidth
                                  anchor:(NCTitleAnchor)anchor
                                 visible:(BOOL)visible;

/** 
 * Factory method for class NCTitleStyle 
 */
+ (nonnull instancetype)titleStyleWithFontSize:(float)fontSize
                                         color:(nonnull UIColor *)color
                                  outlineColor:(nonnull UIColor *)outlineColor
                                  outlineWidth:(float)outlineWidth
                                        anchor:(NCTitleAnchor)anchor
                                       visible:(BOOL)visible;

/** 
 * Default constructor for class NCTitleStyle 
 */
- (nonnull instancetype)init;

/** 
 * Factory method for class NCTitleStyle 
 */
+ (nonnull instancetype)titleStyle;

/**
 *
 * @discussion Example:
 * @code
 * NCTitleStyle *titleStyle = [[NCTitleStyle alloc] init];
 * titleStyle.fontSize = 14;
 * titleStyle.color = @"#3366CC";
 * titleStyle.outlineColor = @"#FFFFFF";
 * titleStyle.anchor = NCTitleAnchorTop;
 * titleStyle.visible = YES;
 * @endcode
 * Font size in pixels.
 */
@property (nonatomic, readonly) float fontSize;

/**
 * Title fill color.
 */
@property (nonatomic, readonly, nonnull) UIColor * color;

/**
 * Title outline (halo) color.
 */
@property (nonatomic, readonly, nonnull) UIColor * outlineColor;

/**
 * Title outline (halo) width in pixels.
 */
@property (nonatomic, readonly) float outlineWidth;

/**
 * Title anchor relative to the placement point ``NCTitleAnchor``.
 */
@property (nonatomic, readonly) NCTitleAnchor anchor;

/**
 * Whether the title is visible.
 */
@property (nonatomic, readonly) BOOL visible;

@end
