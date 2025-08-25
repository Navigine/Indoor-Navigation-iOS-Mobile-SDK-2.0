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
 *
 * Swift code snippet:
 * @snippet LocationManagerExample.swift swift_TransmitterStatus_values
 *
 * Objective C code snippet:
 * @snippet LocationManagerExample.m objc_TransmitterStatus_values
 *
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
