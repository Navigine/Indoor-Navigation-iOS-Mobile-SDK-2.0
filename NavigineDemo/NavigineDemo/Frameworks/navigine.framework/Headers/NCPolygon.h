#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>

NAVIGINE_EXPORT
@interface NCPolygon : NSObject
- (nonnull instancetype)initWithPoints:(nonnull NSArray<NCPoint *> *)points;
+ (nonnull instancetype)polygonWithPoints:(nonnull NSArray<NCPoint *> *)points;

@property (nonatomic, readonly, nonnull) NSArray<NCPoint *> * points;

@end
