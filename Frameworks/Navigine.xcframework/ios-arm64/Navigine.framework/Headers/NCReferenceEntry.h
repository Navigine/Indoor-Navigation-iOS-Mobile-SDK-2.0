#import "NCExport.h"
#import "NCReferenceEntryType.h"
#import <Foundation/Foundation.h>


/**
 * @file NCReferenceEntry.h
 * @brief @copybrief NCReferenceEntry
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCReferenceEntry : NSObject

@property (nonatomic, readonly) NCReferenceEntryType type;

@property (nonatomic, nonnull, readonly) NSString * bssid;

@property (nonatomic, nonnull, readonly) NSString * value;

@end
