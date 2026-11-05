#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Structure representing a 3D vector for sensor measurements.
 * Referenced from ``NCSensorMeasurement``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCVector3d : NSObject

/** 
 * Default constructor for class NCVector3d 
 */
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                                z:(float)z;

/** 
 * Factory method for class NCVector3d 
 */
+ (nonnull instancetype)vector3dWithX:(float)x
                                    y:(float)y
                                    z:(float)z;

/**
 * X-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float x;

/**
 * Y-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float y;

/**
 * Z-coordinate of the 3D vector
 */
@property (nonatomic, readonly) float z;

- (NSComparisonResult)compare:(nonnull NCVector3d *)other;

@end
