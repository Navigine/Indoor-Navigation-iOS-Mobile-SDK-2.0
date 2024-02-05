// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from position.djinni

#import "NCExport.h"
#import "NCGlobalPoint.h"
#import "NCLocationPoint.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCPosition : NSObject
- (nonnull instancetype)initWithPoint:(nonnull NCGlobalPoint *)point
                             accuracy:(double)accuracy
                              heading:(nullable NSNumber *)heading
                        locationPoint:(nullable NCLocationPoint *)locationPoint
                      locationHeading:(nullable NSNumber *)locationHeading;
+ (nonnull instancetype)positionWithPoint:(nonnull NCGlobalPoint *)point
                                 accuracy:(double)accuracy
                                  heading:(nullable NSNumber *)heading
                            locationPoint:(nullable NCLocationPoint *)locationPoint
                          locationHeading:(nullable NSNumber *)locationHeading;

@property (nonatomic, readonly, nonnull) NCGlobalPoint * point;

@property (nonatomic, readonly) double accuracy;

@property (nonatomic, readonly, nullable) NSNumber * heading;

@property (nonatomic, readonly, nullable) NCLocationPoint * locationPoint;

@property (nonatomic, readonly, nullable) NSNumber * locationHeading;

@end