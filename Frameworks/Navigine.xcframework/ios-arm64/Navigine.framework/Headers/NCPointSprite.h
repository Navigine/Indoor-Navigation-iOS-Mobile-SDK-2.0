#import "NCExport.h"
#import "NCGlobalPoint.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * One arrow in a point batch. Heading is degrees clockwise from north.
 * `size` is pixels (the same unit as a symbol icon).
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPointSprite : NSObject

/** 
 * Default constructor for class NCPointSprite 
 */
- (nonnull instancetype)initWithPosition:(nonnull NCGlobalPoint *)position
                                 heading:(float)heading
                                   color:(nonnull UIColor *)color
                                    size:(float)size;

/** 
 * Factory method for class NCPointSprite 
 */
+ (nonnull instancetype)pointSpriteWithPosition:(nonnull NCGlobalPoint *)position
                                        heading:(float)heading
                                          color:(nonnull UIColor *)color
                                           size:(float)size;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * position;

/**
 * Degrees clockwise from north.
 */
@property (nonatomic, readonly) float heading;

@property (nonatomic, readonly, nonnull) UIColor * color;

/**
 * Arrow length in pixels.
 */
@property (nonatomic, readonly) float size;

@end
