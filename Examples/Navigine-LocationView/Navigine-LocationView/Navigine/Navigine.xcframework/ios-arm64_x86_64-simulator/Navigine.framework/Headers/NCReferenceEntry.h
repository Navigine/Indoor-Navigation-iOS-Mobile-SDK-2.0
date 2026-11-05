#import "NCExport.h"
#import "NCReferenceEntryType.h"
#import <Foundation/Foundation.h>


DEFAULT_EXPORT_ATTRIBUTE
@interface NCReferenceEntry : NSObject

@property (nonatomic, readonly) NCReferenceEntryType type;

@property (nonatomic, nonnull, readonly) NSString * bssid;

@property (nonatomic, nonnull, readonly) NSString * value;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
