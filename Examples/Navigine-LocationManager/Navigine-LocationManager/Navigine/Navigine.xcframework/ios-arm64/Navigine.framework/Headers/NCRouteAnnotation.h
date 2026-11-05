#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCRouteAnnotationType.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteAnnotation : NSObject

/** 
 * Default constructor for class NCRouteAnnotation 
 */
- (nonnull instancetype)initWithType:(NCRouteAnnotationType)type
                               point:(nonnull NCGlobalPoint *)point
                       sublocationId:(nullable NSNumber *)sublocationId
                             advance:(float)advance
                               title:(nullable NSString *)title;

/** 
 * Factory method for class NCRouteAnnotation 
 */
+ (nonnull instancetype)routeAnnotationWithType:(NCRouteAnnotationType)type
                                          point:(nonnull NCGlobalPoint *)point
                                  sublocationId:(nullable NSNumber *)sublocationId
                                        advance:(float)advance
                                          title:(nullable NSString *)title;

@property (nonatomic, readonly) NCRouteAnnotationType type;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

@property (nonatomic, readonly) float advance;

@property (nonatomic, readonly, nullable) NSString * title;

@end
