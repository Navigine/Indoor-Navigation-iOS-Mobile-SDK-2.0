#import "NCExport.h"
#import "NCPoint.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCVenue : NSObject

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, nonnull, readonly) NSString * phone;

@property (nonatomic, nonnull, readonly) NSString * descript;

@property (nonatomic, nonnull, readonly) NSString * alias;

@property (nonatomic, readonly) int32_t categoryId;

@property (nonatomic, nullable, readonly) NSString * imageId;

@end