#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * HTTP XYZ source for outdoor vector tiles.
 * `urlTemplate` must contain `{z}`, `{x}`, `{y}`. Optional query parameters
 * (API keys such as `key`, `access_token`, `apikey`) are appended to each
 * request. Optional headers cover `Authorization`, `Referer`, or a custom
 * `User-Agent`. The SDK always sends an identifying User-Agent unless the
 * headers map already has one. Keys may also be baked into `urlTemplate`.
 * Referenced from ``NCTileProvider``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCHttpTileSource : NSObject

/** 
 * Default constructor for class NCHttpTileSource 
 */
- (nonnull instancetype)initWithUrlTemplate:(nonnull NSString *)urlTemplate
                                    headers:(nullable NSDictionary<NSString *, NSString *> *)headers
                            queryParameters:(nullable NSDictionary<NSString *, NSString *> *)queryParameters;

/** 
 * Factory method for class NCHttpTileSource 
 */
+ (nonnull instancetype)httpTileSourceWithUrlTemplate:(nonnull NSString *)urlTemplate
                                              headers:(nullable NSDictionary<NSString *, NSString *> *)headers
                                      queryParameters:(nullable NSDictionary<NSString *, NSString *> *)queryParameters;

/**
 *
 * @discussion Example:
 * @code
 * NCHttpTileSource *http = [[NCHttpTileSource alloc]
 *    initWithUrlTemplate:@"https://api.maptiler.com/tiles/v3-openmaptiles/{z}/{x}/{y}.pbf"
 *                headers:nil
 *       queryParameters:@{@"key": @"YOUR_MAPTILER_KEY"}];
 * @endcode
 * HTTPS XYZ template with `{z}`, `{x}`, `{y}`.
 */
@property (nonatomic, readonly, nonnull) NSString * urlTemplate;

/**
 * Extra request headers. Null or empty: none. Overrides the default
 * User-Agent when that header is set.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> * headers;

/**
 * Extra query parameters appended to each tile URL. Null or empty: none.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> * queryParameters;

@end
