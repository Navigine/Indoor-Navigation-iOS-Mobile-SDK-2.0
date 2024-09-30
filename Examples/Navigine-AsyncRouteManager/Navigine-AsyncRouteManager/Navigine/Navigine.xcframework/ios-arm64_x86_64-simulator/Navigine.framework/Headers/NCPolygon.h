#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 *
 * A polygon with specified list of points.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolygon : NSObject
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;
+ (nonnull instancetype)polygonWithPoints:(nonnull NSArray<NCPoint *> *)points;

/** The ring specifying the area. */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
