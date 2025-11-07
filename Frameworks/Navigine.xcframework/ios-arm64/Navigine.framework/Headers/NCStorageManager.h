#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCKeyValueStorage;


/**
 * @file NCStorageManager.h
 * @brief @copybrief NCStorageManager
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Interface for managing multiple key-value storages, providing access and lifecycle control.
 *
 * Referenced from @see NavigineSdk "NavigineSdk".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCStorageManager : NSObject

/**
 * Returns the list of all existing user storages.
 * @return List of storage names (implementation currently returns them in alphabetical order).
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_StorageManager_getStorageList
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_StorageManager_getStorageList
 *
 *
 */
- (nonnull NSArray<NSString *> *)getStorageList;

/**
 * Returns a handle to a storage by name, creating it if it does not exist.
 * @param name Storage name (case-sensitive).
 * @return Key–value storage instance @see KeyValueStorage "KeyValueStorage"
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_StorageManager_getStorage
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_StorageManager_getStorage
 *
 *
 */
- (nullable NCKeyValueStorage *)getStorage:(nonnull NSString *)name;

/**
 * Removes the storage and all its persisted data. If the storage does not exist, this is a no-op.
 * @param name Storage name (case-sensitive).
 * @note Existing handles to this storage become invalid after removal and further operations may fail.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_StorageManager_removeStorage
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_StorageManager_removeStorage
 *
 *
 */
- (void)removeStorage:(nonnull NSString *)name;

@end
