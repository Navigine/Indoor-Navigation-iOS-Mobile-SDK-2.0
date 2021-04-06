#import "NCReferenceEntryType.h"
#import <Foundation/Foundation.h>


@interface NCReferenceEntry : NSObject

@property (nonatomic, readonly) NCReferenceEntryType type;

@property (nonatomic, nonnull, readonly) NSString * bssid;

@property (nonatomic, nonnull, readonly) NSString * value;

@end
