#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCKeyValueStorage;


/**
 * Interface for managing multiple key-value storages, providing access and lifecycle control.
 * Referenced from ``NCNavigineSdk``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCStorageManager : NSObject

/**
 * Returns the list of all existing user storages.
 * @return List of storage names (implementation currently returns them in alphabetical order).
 *
 * @discussion Example:
 * @code
 * // Get list of all existing storages
 * NSArray<NSString *> *storageList = [self.storageManager getStorageList];
 * NSLog(@"Existing storages: %@", storageList);
 * @endcode
 */
- (nonnull NSArray<NSString *> *)getStorageList;

/**
 * Returns a handle to a storage by name, creating it if it does not exist.
 * @param name Storage name (case-sensitive).
 * @return Key–value storage instance ``NCKeyValueStorage``
 *
 * @discussion Example:
 * @code
 * // Get or create different storage instances
 * self.userStorage = [self.storageManager getStorage:@"user_preferences"];
 * self.appStorage = [self.storageManager getStorage:@"app_settings"];
 * self.cacheStorage = [self.storageManager getStorage:@"cache"];
 * @endcode
 */
- (nullable NCKeyValueStorage *)getStorage:(nonnull NSString *)name;

/**
 * Removes the storage and all its persisted data. If the storage does not exist, this is a no-op.
 * @param name Storage name (case-sensitive).
 * @discussion Note: Existing handles to this storage become invalid after removal and further operations may fail.
 *
 * @discussion Example:
 * @code
 * // Remove storage and all its data
 * [self.storageManager removeStorage:@"test_storage"];
 * NSLog(@"Removed test storage");
 * @endcode
 */
- (void)removeStorage:(nonnull NSString *)name;

@end
