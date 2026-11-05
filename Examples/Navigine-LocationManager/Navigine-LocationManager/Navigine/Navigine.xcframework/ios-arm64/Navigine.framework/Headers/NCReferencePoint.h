#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>
@class NCReferenceEntry;


DEFAULT_EXPORT_ATTRIBUTE
@interface NCReferencePoint : NSObject

@property (nonatomic, readonly) int32_t locationId;

@property (nonatomic, readonly) int32_t sublocationId;

@property (nonatomic, nonnull, readonly) NSString * name;

@property (nonatomic, nonnull, readonly) NSString * uuid;

@property (nonatomic, nonnull, readonly) NCPoint * point;

@property (nonatomic, readonly) int32_t quality;

@property (nonatomic, readonly) int64_t duration;

@property (nonatomic, nonnull, readonly) NSString * deviceId;

@property (nonatomic, nonnull, readonly) NSString * deviceModel;

@property (nonatomic, nonnull, readonly) NSString * timeLabel;

@property (nonatomic, nonnull, readonly) NSArray<NCReferenceEntry *> * entries;

@property (nonatomic, readonly) NCTransmitterStatus status;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
