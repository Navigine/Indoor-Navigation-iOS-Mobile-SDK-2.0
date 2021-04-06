#import "NCCategory.h"
#import <Foundation/Foundation.h>
@class NCElevationGraph;
@class NCSublocation;


@interface NCLocation : NSObject

- (nullable NCElevationGraph *)getElevationGraph:(nonnull NSString *)tag;

- (nonnull NSArray<NSString *> *)getGraphTags;

- (nullable NCSublocation *)getSublocationById:(int32_t)id;

- (nullable NCCategory *)getCategoryById:(int32_t)id;

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, readonly) int32_t version;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, nonnull, readonly) NSString * descript;

@property (nonatomic, nonnull, readonly) NSArray<NCCategory *> * categories;

@property (nonatomic, nonnull, readonly) NSArray<NCSublocation *> * sublocations;

@end
