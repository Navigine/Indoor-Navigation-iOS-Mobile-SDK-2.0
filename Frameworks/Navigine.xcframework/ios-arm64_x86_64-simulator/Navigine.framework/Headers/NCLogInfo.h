#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCLogInfo.h
 * @brief @copybrief NCLogInfo
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 *
 * @brief Represents metadata for a log file.
 *
 * Referenced from @see ResourceManager "ResourceManager".
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLogInfo : NSObject

/** 
 * @brief Default constructor for class NCLogInfo 
 */
- (nonnull instancetype)initWithName:(nonnull NSString *)name
                        absolutePath:(nonnull NSString *)absolutePath
                                size:(int32_t)size
                            duration:(int32_t)duration
                                date:(nonnull NSString *)date
                 numberOfCheckpoints:(int32_t)numberOfCheckpoints;

/** 
 * @brief Factory method for class NCLogInfo 
 */
+ (nonnull instancetype)logInfoWithName:(nonnull NSString *)name
                           absolutePath:(nonnull NSString *)absolutePath
                                   size:(int32_t)size
                               duration:(int32_t)duration
                                   date:(nonnull NSString *)date
                    numberOfCheckpoints:(int32_t)numberOfCheckpoints;

/**
 * @brief The name of the log file.
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * @brief The absolute file path of the log file.
 */
@property (nonatomic, readonly, nonnull) NSString * absolutePath;

/**
 * @brief The size of the log file in bytes.
 */
@property (nonatomic, readonly) int32_t size;

/**
 * @brief The duration of the logged activity in seconds.
 */
@property (nonatomic, readonly) int32_t duration;

/**
 * @brief The date the log file was created or last modified, in string format.
 */
@property (nonatomic, readonly, nonnull) NSString * date;

/**
 * @brief The number of checkpoints recorded in the log file.
 */
@property (nonatomic, readonly) int32_t numberOfCheckpoints;

@end
