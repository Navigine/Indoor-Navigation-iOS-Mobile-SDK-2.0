#import "NCAttributionHorizontalAlignment.h"
#import "NCAttributionVerticalAlignment.h"
#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Screen placement of the OSM attribution overlay.
 * Same shape as typical map logo alignment: horizontal × vertical.
 * Default: right + bottom (OSM Vector Tile Usage Policy).
 * Referenced from ``NCLocationWindow`` `attributionAlignment`.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCAttributionAlignment : NSObject

/** 
 * Default constructor for class NCAttributionAlignment 
 */
- (nonnull instancetype)initWithHorizontalAlignment:(NCAttributionHorizontalAlignment)horizontalAlignment
                                  verticalAlignment:(NCAttributionVerticalAlignment)verticalAlignment;

/** 
 * Factory method for class NCAttributionAlignment 
 */
+ (nonnull instancetype)attributionAlignmentWithHorizontalAlignment:(NCAttributionHorizontalAlignment)horizontalAlignment
                                                  verticalAlignment:(NCAttributionVerticalAlignment)verticalAlignment;

/** 
 * Default constructor for class NCAttributionAlignment 
 */
- (nonnull instancetype)init;

/** 
 * Factory method for class NCAttributionAlignment 
 */
+ (nonnull instancetype)attributionAlignment;

/**
 *
 * @discussion Example:
 * @code
 * NCAttributionAlignment *alignment = [[NCAttributionAlignment alloc]
 *    initWithHorizontalAlignment:NCAttributionHorizontalAlignmentRight
 *             verticalAlignment:NCAttributionVerticalAlignmentBottom];
 * @endcode
 * Horizontal edge or center ``NCAttributionHorizontalAlignment``.
 */
@property (nonatomic, readonly) NCAttributionHorizontalAlignment horizontalAlignment;

/**
 * Vertical edge ``NCAttributionVerticalAlignment``.
 */
@property (nonatomic, readonly) NCAttributionVerticalAlignment verticalAlignment;

@end
