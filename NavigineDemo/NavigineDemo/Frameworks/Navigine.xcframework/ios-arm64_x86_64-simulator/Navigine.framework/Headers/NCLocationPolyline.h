// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from location_polyline.djinni

#import "NCExport.h"
#import "NCPolyline.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCLocationPolyline : NSObject
- (nonnull instancetype)initWithPolyline:(nonnull NCPolyline *)polyline
                              locationId:(int32_t)locationId
                           sublocationId:(int32_t)sublocationId;
+ (nonnull instancetype)locationPolylineWithPolyline:(nonnull NCPolyline *)polyline
                                          locationId:(int32_t)locationId
                                       sublocationId:(int32_t)sublocationId;

@property (nonatomic, readonly, nonnull) NCPolyline * polyline;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@end
