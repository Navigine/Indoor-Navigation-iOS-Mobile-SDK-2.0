#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * @file NCKeyValueStorage.h
 * @brief @copybrief NCKeyValueStorage
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_managers
 * @brief Interface for key-value storage operations, allowing storage and retrieval of various data types.
 *
 * Referenced from @see StorageManager "StorageManager".
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCKeyValueStorage : NSObject

/**
 * Checks whether the key exists in the storage.
 * @param key Key to check.
 * @return true if a value is stored under the key (regardless of type).
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_contains
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_contains
 *
 *
 */
- (BOOL)contains:(nonnull NSString *)key;

/**
 * Returns all keys currently stored.
 * @return List of keys. Order is implementation-defined (not guaranteed).
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getKeys
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getKeys
 *
 *
 */
- (nonnull NSArray<NSString *> *)getKeys;

/**
 * Gets a 32-bit integer value.
 * Returns defaultValue if the key is missing or the stored type is not int.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored int32 or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getInt
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getInt
 *
 *
 */
- (int32_t)getInt:(nonnull NSString *)key
     defaultValue:(int32_t)defaultValue;

/**
 * Gets a 64-bit integer value.
 * Returns defaultValue if the key is missing or the stored type is not long.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored int64 or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getLong
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getLong
 *
 *
 */
- (int64_t)getLong:(nonnull NSString *)key
      defaultValue:(int64_t)defaultValue;

/**
 * Gets a boolean value.
 * Returns defaultValue if the key is missing or the stored type is not bool.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored bool or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getBool
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getBool
 *
 *
 */
- (BOOL)getBool:(nonnull NSString *)key
   defaultValue:(BOOL)defaultValue;

/**
 * Gets a 32-bit floating-point value.
 * Returns defaultValue if the key is missing or the stored type is not float.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored float or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getFloat
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getFloat
 *
 *
 */
- (float)getFloat:(nonnull NSString *)key
     defaultValue:(float)defaultValue;

/**
 * Gets a 64-bit floating-point value.
 * Returns defaultValue if the key is missing or the stored type is not double.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored double or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getDouble
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getDouble
 *
 *
 */
- (double)getDouble:(nonnull NSString *)key
       defaultValue:(double)defaultValue;

/**
 * Gets a string value.
 * Returns defaultValue if the key is missing or the stored type is not string.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored string or defaultValue.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_getString
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_getString
 *
 *
 */
- (nonnull NSString *)getString:(nonnull NSString *)key
                   defaultValue:(nonnull NSString *)defaultValue;

/**
 * Stores a 32-bit integer value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putInt
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putInt
 *
 *
 */
- (void)putInt:(nonnull NSString *)key
         value:(int32_t)value;

/**
 * Stores a 64-bit integer value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putLong
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putLong
 *
 *
 */
- (void)putLong:(nonnull NSString *)key
          value:(int64_t)value;

/**
 * Stores a boolean value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putBool
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putBool
 *
 *
 */
- (void)putBool:(nonnull NSString *)key
          value:(BOOL)value;

/**
 * Stores a 32-bit floating-point value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putFloat
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putFloat
 *
 *
 */
- (void)putFloat:(nonnull NSString *)key
           value:(float)value;

/**
 * Stores a 64-bit floating-point value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putDouble
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putDouble
 *
 *
 */
- (void)putDouble:(nonnull NSString *)key
            value:(double)value;

/**
 * Stores a string value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_putString
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_putString
 *
 *
 */
- (void)putString:(nonnull NSString *)key
            value:(nonnull NSString *)value;

/**
 * Removes a value by key. No-op if the key does not exist.
 * @param key Key to remove.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_remove
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_remove
 *
 *
 */
- (void)remove:(nonnull NSString *)key;

/**
 * Removes all entries from the storage.
 *
 *
 * Swift code snippet:
 * @snippet StorageManagerExample.swift swift_KeyValueStorage_clear
 *
 * Objective C code snippet:
 * @snippet StorageManagerExample.m objc_KeyValueStorage_clear
 *
 *
 */
- (void)clear;

@end
