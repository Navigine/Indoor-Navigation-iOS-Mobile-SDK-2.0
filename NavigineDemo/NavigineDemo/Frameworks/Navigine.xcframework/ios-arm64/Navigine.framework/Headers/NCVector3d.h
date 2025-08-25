#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCVector3d.h
 * @brief @copybrief NCVector3d
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Structure representing a 3D vector for sensor measurements.
 *
 * Referenced from @see SensorMeasurement "SensorMeasurement".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVector3d : NSObject

/** 
 * @brief Default constructor for class NCVector3d 
 */
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                                z:(float)z;

/** 
 * @brief Factory method for class NCVector3d 
 */
+ (nonnull instancetype)vector3dWithX:(float)x
                                    y:(float)y
                                    z:(float)z;

/**
 * @brief X-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float x;

/**
 * @brief Y-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float y;

/**
 * @brief Z-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float z;

- (NSComparisonResult)compare:(nonnull NCVector3d *)other;

@end
