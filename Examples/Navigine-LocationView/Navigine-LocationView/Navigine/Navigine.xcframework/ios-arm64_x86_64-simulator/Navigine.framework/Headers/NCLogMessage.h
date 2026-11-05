#import "NCExport.h"
#import "NCLogLevel.h"
#import <Foundation/Foundation.h>

DEFAULT_EXPORT_ATTRIBUTE
@interface NCLogMessage : NSObject

/** 
 * Default constructor for class NCLogMessage 
 */
- (nonnull instancetype)initWithTime:(int64_t)time
                               level:(NCLogLevel)level
                               scope:(nonnull NSString *)scope
                             message:(nonnull NSString *)message
                         verboseInfo:(nonnull NSString *)verboseInfo;

/** 
 * Factory method for class NCLogMessage 
 */
+ (nonnull instancetype)logMessageWithTime:(int64_t)time
                                     level:(NCLogLevel)level
                                     scope:(nonnull NSString *)scope
                                   message:(nonnull NSString *)message
                               verboseInfo:(nonnull NSString *)verboseInfo;

@property (nonatomic, readonly) int64_t time;

@property (nonatomic, readonly) NCLogLevel level;

@property (nonatomic, readonly, nonnull) NSString * scope;

@property (nonatomic, readonly, nonnull) NSString * message;

@property (nonatomic, readonly, nonnull) NSString * verboseInfo;

@end
