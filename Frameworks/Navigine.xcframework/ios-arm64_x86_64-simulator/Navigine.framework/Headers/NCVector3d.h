#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCVector3d.h
 * @brief @copybrief NCVector3d
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

@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;

@property (nonatomic, readonly) float z;

- (NSComparisonResult)compare:(nonnull NCVector3d *)other;

@end
