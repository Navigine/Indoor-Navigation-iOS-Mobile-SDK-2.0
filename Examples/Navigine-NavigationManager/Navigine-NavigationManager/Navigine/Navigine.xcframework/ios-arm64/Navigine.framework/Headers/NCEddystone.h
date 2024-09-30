#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing eddystone transmitter.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCEddystone : NSObject

/** Metrics coordinate of eddystone position (@see Point). */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/** Unique location identifier of eddystone position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of eddystone position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** Eddystone name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** Eddystone namespaceId. */
@property (nonatomic, nonnull, readonly) NSString * namespaceId;

/** Eddystone instanceId. */
@property (nonatomic, nonnull, readonly) NSString * instanceId;

/** Eddystone power. If exsists. */
@property (nonatomic, nullable, readonly) NSNumber * power;

/** Eddystone status. (@see TransmitterStatus) */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
