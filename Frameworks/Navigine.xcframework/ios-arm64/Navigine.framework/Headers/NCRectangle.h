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
 *
 *
 * Swift code snippet:
 * @snippet BitmapRegionDecoderExample.swift swift_Rectangle_constructor
 *
 * Objective C code snippet:
 * @snippet BitmapRegionDecoderExample.m objc_Rectangle_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRectangle : NSObject

/** 
 * @brief Default constructor for class NCRectangle 
 */
- (nonnull instancetype)initWithX:(int32_t)x
                                y:(int32_t)y
                            width:(int32_t)width
                           height:(int32_t)height;

/** 
 * @brief Factory method for class NCRectangle 
 */
+ (nonnull instancetype)rectangleWithX:(int32_t)x
                                     y:(int32_t)y
                                 width:(int32_t)width
                                height:(int32_t)height;

/**
 *
 * @brief rectangle's origin `x` coordinate.
 *
 */
@property (nonatomic, readonly) int32_t x;

/**
 *
 * @brief rectangle's origin `y` coordinate.
 */
@property (nonatomic, readonly) int32_t y;

/**
 *
 * @brief rectangle's width.
 *
 */
@property (nonatomic, readonly) int32_t width;

/**
 *
 * @brief rectangle's height.
 *
 */
@property (nonatomic, readonly) int32_t height;

@end
