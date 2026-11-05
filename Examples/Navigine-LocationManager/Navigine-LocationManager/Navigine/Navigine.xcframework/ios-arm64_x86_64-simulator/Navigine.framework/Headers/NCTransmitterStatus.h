#import <Foundation/Foundation.h>

/**
 * enum described possible transmitter state.
 * Referenced from ``NCBeacon``, ``NCEddystone``, ``NCWifi``.
 *
 * @discussion Example:
 * @code
 * // Get all transmitter status values
 * NSLog(@"Available transmitter statuses:");
 * NSLog(@"  - NCTransmitterStatusActive: %ld", (long)NCTransmitterStatusActive);
 * NSLog(@"  - NCTransmitterStatusInactive: %ld", (long)NCTransmitterStatusInactive);
 * @endcode
 */
typedef NS_ENUM(NSInteger, NCTransmitterStatus)
{
    /**
     * Synchronized with CMS.
     */
    NCTransmitterStatusNone,
    /**
     * Added in SDK but not synchronized with CMS.
     */
    NCTransmitterStatusNew,
    /**
     * Deleted in SDK but not synchronized with CMS.
     */
    NCTransmitterStatusDeleted,
    /**
     * Changed in SDK but not synchronized with CMS.
     */
    NCTransmitterStatusModified,
};
