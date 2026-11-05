#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

/**
 * A polyline with specified number of points.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCPolyline : NSObject

/** 
 * Default constructor for class NCPolyline 
 */
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;

/** 
 * Factory method for class NCPolyline 
 */
+ (nonnull instancetype)polylineWithPoints:(nonnull NSArray<NCPoint *> *)points;

/**
 * List of points to connect.
 */
@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
