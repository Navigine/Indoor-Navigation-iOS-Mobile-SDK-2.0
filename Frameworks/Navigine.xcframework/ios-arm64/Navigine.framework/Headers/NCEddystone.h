// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from eddystone.djinni

#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


DEFAULT_EXPORT_ATTRIBUTE
@interface NCEddystone : NSObject

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, nonnull, readonly) NSString * namespaceId;

@property (nonatomic, nonnull, readonly) NSString * instanceId;

@property (nonatomic, nullable, readonly) NSNumber * power;

@property (nonatomic, readonly) NCTransmitterStatus status;

@end
