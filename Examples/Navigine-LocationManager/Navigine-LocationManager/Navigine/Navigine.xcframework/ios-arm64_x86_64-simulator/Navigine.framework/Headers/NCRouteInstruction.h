#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCRouteAnnotationType.h"
#import <Foundation/Foundation.h>

/**
 * Next instruction for a guidance banner.
 * Built from the next ``NCRouteAnnotation`` ahead of the
 * current route progress. `distance` is meters along the route, not a
 * straight-line chord. This is a pedestrian manoeuvre (no lanes, signs, or road
 * events).
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCRouteInstruction : NSObject

/** 
 * Default constructor for class NCRouteInstruction 
 */
- (nonnull instancetype)initWithType:(NCRouteAnnotationType)type
                               point:(nonnull NCGlobalPoint *)point
                       sublocationId:(nullable NSNumber *)sublocationId
                            distance:(float)distance
                               title:(nullable NSString *)title;

/** 
 * Factory method for class NCRouteInstruction 
 */
+ (nonnull instancetype)routeInstructionWithType:(NCRouteAnnotationType)type
                                           point:(nonnull NCGlobalPoint *)point
                                   sublocationId:(nullable NSNumber *)sublocationId
                                        distance:(float)distance
                                           title:(nullable NSString *)title;

/**
 * Annotation kind (transition, maneuver, finish, …).
 */
@property (nonatomic, readonly) NCRouteAnnotationType type;

/**
 * Instruction point in WGS84.
 */
@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

/**
 * Floor id, or null when the instruction is outdoor.
 */
@property (nonatomic, readonly, nullable) NSNumber * sublocationId;

/**
 * Meters along the route from the current progress to this point.
 */
@property (nonatomic, readonly) float distance;

/**
 * Short label, when the annotation has one.
 */
@property (nonatomic, readonly, nullable) NSString * title;

@end
