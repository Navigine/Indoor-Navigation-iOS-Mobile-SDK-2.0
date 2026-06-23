#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * Represents metadata for a log file.
 * Referenced from ``NCResourceManager``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCLogInfo : NSObject

/** 
 * Default constructor for class NCLogInfo 
 */
- (nonnull instancetype)initWithName:(nonnull NSString *)name
                        absolutePath:(nonnull NSString *)absolutePath
                                size:(int32_t)size
                            duration:(int32_t)duration
                                date:(nonnull NSString *)date
                 numberOfCheckpoints:(int32_t)numberOfCheckpoints;

/** 
 * Factory method for class NCLogInfo 
 */
+ (nonnull instancetype)logInfoWithName:(nonnull NSString *)name
                           absolutePath:(nonnull NSString *)absolutePath
                                   size:(int32_t)size
                               duration:(int32_t)duration
                                   date:(nonnull NSString *)date
                    numberOfCheckpoints:(int32_t)numberOfCheckpoints;

/**
 * The name of the log file.
 */
@property (nonatomic, readonly, nonnull) NSString * name;

/**
 * The absolute file path of the log file.
 */
@property (nonatomic, readonly, nonnull) NSString * absolutePath;

/**
 * The size of the log file in bytes.
 */
@property (nonatomic, readonly) int32_t size;

/**
 * The duration of the logged activity in seconds.
 */
@property (nonatomic, readonly) int32_t duration;

/**
 * The date the log file was created or last modified, in string format.
 */
@property (nonatomic, readonly, nonnull) NSString * date;

/**
 * The number of checkpoints recorded in the log file.
 */
@property (nonatomic, readonly) int32_t numberOfCheckpoints;

@end
