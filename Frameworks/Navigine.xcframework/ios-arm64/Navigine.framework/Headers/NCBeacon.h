#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing iBeacon transmitter.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBeacon : NSObject

/** Metrics coordinate of iBeacon position (@see Point). */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/** Unique location identifier of iBeacon position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of iBeacon position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** iBeacon name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** iBeacon major. Values [1-65535] */
@property (nonatomic, readonly) int32_t major;

/** iBeacon minor. Values [1-65535] */
@property (nonatomic, readonly) int32_t minor;

/** iBeacon uuid. Format [XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX] */
@property (nonatomic, nonnull, readonly) NSString * uuid;

/** iBeacon power. If exsists. */
@property (nonatomic, nullable, readonly) NSNumber * power;

/** iBeacon status. (@see TransmitterStatus) */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
