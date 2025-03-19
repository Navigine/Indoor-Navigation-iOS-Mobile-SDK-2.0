#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCRectangle.h
 * @brief @copybrief NCRectangle
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_geometry_classes
 *
 * @brief A rectangle with specified origin and size.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRectangle : NSObject

/** 
 * @brief Default constructor for class NCRectangle 
 */
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                            width:(float)width
                           height:(float)height;

/** 
 * @brief Factory method for class NCRectangle 
 */
+ (nonnull instancetype)rectangleWithX:(float)x
                                     y:(float)y
                                 width:(float)width
                                height:(float)height;

/**
 *
 * @brief rectangle's origin `x` coordinate.
 *
 */
@property (nonatomic, readonly) float x;

/**
 *
 * @brief rectangle's origin `y` coordinate.
 *
 */
@property (nonatomic, readonly) float y;

/**
 *
 * @brief rectangle's width.
 *
 */
@property (nonatomic, readonly) float width;

/**
 *
 * @brief rectangle's height.
 *
 */
@property (nonatomic, readonly) float height;

@end
