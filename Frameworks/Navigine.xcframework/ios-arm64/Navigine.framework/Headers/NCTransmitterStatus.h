#import <Foundation/Foundation.h>

/** Describe possible transmitter state */
typedef NS_ENUM(NSInteger, NCTransmitterStatus)
{
    /** Syncronized with CMS. */
    NCTransmitterStatusNone,
    /** Added in SDK but not syncronized with CMS. */
    NCTransmitterStatusNew,
    /** Deleted in SDK but not syncronized with CMS. */
    NCTransmitterStatusDeleted,
    /** Changed in SDK but not syncronized with CMS. */
    NCTransmitterStatusModified,
};
