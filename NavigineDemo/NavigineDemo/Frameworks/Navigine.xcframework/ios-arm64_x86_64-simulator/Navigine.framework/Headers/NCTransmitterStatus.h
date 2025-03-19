#import <Foundation/Foundation.h>

/**
 * @file NCTransmitterStatus.h
 * @brief @copybrief NCTransmitterStatus
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief enum described possible transmitter state.
 *
 * Referenced from @see Beacon "Beacon", @see Eddystone "Eddystone", @see Wifi "Wifi".
 *
 */
typedef NS_ENUM(NSInteger, NCTransmitterStatus)
{
    /**
     * @brief Syncronized with CMS.
     */
    NCTransmitterStatusNone,
    /**
     * @brief Added in SDK but not syncronized with CMS.
     */
    NCTransmitterStatusNew,
    /**
     * @brief Deleted in SDK but not syncronized with CMS.
     */
    NCTransmitterStatusDeleted,
    /**
     * @brief Changed in SDK but not syncronized with CMS.
     */
    NCTransmitterStatusModified,
};
