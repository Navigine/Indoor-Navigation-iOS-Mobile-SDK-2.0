#import "NCExport.h"
#import "NCPoint.h"
#import "NCTransmitterStatus.h"
#import <Foundation/Foundation.h>


/**
 *
 * Object describing WiFi transmitter.
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCWifi : NSObject

/** Metrics coordinate of WiFi position (@see Point). */
@property (nonatomic, nonnull, readonly) NCPoint * point;

/** Unique location identifier of WiFi position. */
@property (nonatomic, readonly) int32_t locationId;

/** Unique sublocation identifier of WiFi position. */
@property (nonatomic, readonly) int32_t sublocationId;

/** WiFi name. */
@property (nonatomic, nonnull, readonly) NSString * name;

/** WiFi mac. */
@property (nonatomic, nonnull, readonly) NSString * mac;

/** WiFi status. (@see TransmitterStatus) */
@property (nonatomic, readonly) NCTransmitterStatus status;

@end
