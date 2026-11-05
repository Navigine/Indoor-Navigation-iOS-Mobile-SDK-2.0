#import "NCExport.h"
#import <Foundation/Foundation.h>


/**
 * Interface for key-value storage operations, allowing storage and retrieval of various data types.
 * Referenced from ``NCStorageManager``.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCKeyValueStorage : NSObject

/**
 * Checks whether the key exists in the storage.
 * @param key Key to check.
 * @return true if a value is stored under the key (regardless of type).
 *
 * @discussion Example:
 * @code
 * // Check if keys exist
 * BOOL hasUserName = [self.userStorage contains:@"user_name"];
 * BOOL hasNonExistent = [self.userStorage contains:@"non_existent_key"];
 * NSLog(@"Contains 'user_name': %@", hasUserName ? @"YES" : @"NO");
 * NSLog(@"Contains 'non_existent_key': %@", hasNonExistent ? @"YES" : @"NO");
 * @endcode
 */
- (BOOL)contains:(nonnull NSString *)key;

/**
 * Returns all keys currently stored.
 * @return List of keys. Order is implementation-defined (not guaranteed).
 *
 * @discussion Example:
 * @code
 * // Get all stored keys
 * NSArray<NSString *> *allKeys = [self.userStorage getKeys];
 * NSLog(@"All stored keys: %@", allKeys);
 * @endcode
 */
- (nonnull NSArray<NSString *> *)getKeys;

/**
 * Gets a 32-bit integer value.
 * Returns defaultValue if the key is missing or the stored type is not int.
 * @param key Lookup key.
 * @param defaultValue Value to return when not found or type mismatch.
 * @return Stored int32 or defaultValue.
 *
 * @discussion Example:
 * @code
 * // Retrieve integer values with defaults
 * int32_t userAge = [self.userStorage getInt:@"user_age" defaultValue:0];
 * int32_t loginCount = [self.userStorage getInt:@"login_count" defaultValue:0];
 * int32_t nonExistentInt = [self.userStorage getInt:@"non_existent_int" defaultValue:-1];
 * NSLog(@"User age: %d", userAge);
 * NSLog(@"Login count: %d", loginCount);
 * NSLog(@"Non-existent int: %d", nonExistentInt);
 * @endcode
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
 * @discussion Example:
 * @code
 * // Retrieve long values with defaults
 * int64_t regTimestamp = [self.userStorage getLong:@"registration_timestamp" defaultValue:0];
 * int64_t lastLogin = [self.userStorage getLong:@"last_login_timestamp" defaultValue:0];
 * int64_t nonExistentLong = [self.userStorage getLong:@"non_existent_long" defaultValue:-1];
 * NSLog(@"Registration timestamp: %lld", regTimestamp);
 * NSLog(@"Last login timestamp: %lld", lastLogin);
 * NSLog(@"Non-existent long: %lld", nonExistentLong);
 * @endcode
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
 * @discussion Example:
 * @code
 * // Retrieve boolean values with defaults
 * BOOL isPremium = [self.userStorage getBool:@"is_premium" defaultValue:NO];
 * BOOL notificationsEnabled = [self.userStorage getBool:@"notifications_enabled" defaultValue:YES];
 * BOOL nonExistentBool = [self.userStorage getBool:@"non_existent_bool" defaultValue:NO];
 * NSLog(@"Is premium: %@", isPremium ? @"YES" : @"NO");
 * NSLog(@"Notifications enabled: %@", notificationsEnabled ? @"YES" : @"NO");
 * NSLog(@"Non-existent bool: %@", nonExistentBool ? @"YES" : @"NO");
 * @endcode
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
 * @discussion Example:
 * @code
 * // Retrieve float values with defaults
 * float userRating = [self.userStorage getFloat:@"user_rating" defaultValue:0.0f];
 * float temperature = [self.userStorage getFloat:@"temperature" defaultValue:0.0f];
 * float nonExistentFloat = [self.userStorage getFloat:@"non_existent_float" defaultValue:-1.0f];
 * NSLog(@"User rating: %f", userRating);
 * NSLog(@"Temperature: %f", temperature);
 * NSLog(@"Non-existent float: %f", nonExistentFloat);
 * @endcode
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
 * @discussion Example:
 * @code
 * // Retrieve double values with defaults
 * double userLat = [self.userStorage getDouble:@"user_location_lat" defaultValue:0.0];
 * double userLng = [self.userStorage getDouble:@"user_location_lng" defaultValue:0.0];
 * double nonExistentDouble = [self.userStorage getDouble:@"non_existent_double" defaultValue:-1.0];
 * NSLog(@"User location lat: %f", userLat);
 * NSLog(@"User location lng: %f", userLng);
 * NSLog(@"Non-existent double: %f", nonExistentDouble);
 * @endcode
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
 * @discussion Example:
 * @code
 * // Retrieve string values with defaults
 * NSString *userName = [self.userStorage getString:@"user_name" defaultValue:@"Unknown"];
 * NSString *userEmail = [self.userStorage getString:@"user_email" defaultValue:@""];
 * NSString *nonExistent = [self.userStorage getString:@"non_existent_key" defaultValue:@"default_value"];
 * NSLog(@"User name: %@", userName);
 * NSLog(@"User email: %@", userEmail);
 * NSLog(@"Non-existent key: %@", nonExistent);
 * @endcode
 */
- (nonnull NSString *)getString:(nonnull NSString *)key
                   defaultValue:(nonnull NSString *)defaultValue;

/**
 * Stores a 32-bit integer value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store integer values
 * [self.userStorage putInt:@"user_age" value:25];
 * [self.userStorage putInt:@"login_count" value:42];
 * NSLog(@"Stored integer values");
 * @endcode
 */
- (void)putInt:(nonnull NSString *)key
         value:(int32_t)value;

/**
 * Stores a 64-bit integer value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store long values
 * [self.userStorage putLong:@"registration_timestamp" value:1640995200000LL];
 * [self.userStorage putLong:@"last_login_timestamp" value:(long long)[[NSDate date] timeIntervalSince1970] * 1000];
 * NSLog(@"Stored long values");
 * @endcode
 */
- (void)putLong:(nonnull NSString *)key
          value:(int64_t)value;

/**
 * Stores a boolean value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store boolean values
 * [self.userStorage putBool:@"is_premium" value:YES];
 * [self.userStorage putBool:@"notifications_enabled" value:NO];
 * NSLog(@"Stored boolean values");
 * @endcode
 */
- (void)putBool:(nonnull NSString *)key
          value:(BOOL)value;

/**
 * Stores a 32-bit floating-point value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store float values
 * [self.userStorage putFloat:@"user_rating" value:4.5f];
 * [self.userStorage putFloat:@"temperature" value:23.5f];
 * NSLog(@"Stored float values");
 * @endcode
 */
- (void)putFloat:(nonnull NSString *)key
           value:(float)value;

/**
 * Stores a 64-bit floating-point value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store double values
 * [self.userStorage putDouble:@"user_location_lat" value:55.7558];
 * [self.userStorage putDouble:@"user_location_lng" value:37.6176];
 * NSLog(@"Stored double values");
 * @endcode
 */
- (void)putDouble:(nonnull NSString *)key
            value:(double)value;

/**
 * Stores a string value under the key, replacing any existing value.
 * @param key Key to set.
 * @param value Value to store.
 *
 * @discussion Example:
 * @code
 * // Store string values
 * [self.userStorage putString:@"user_name" value:@"John Doe"];
 * [self.userStorage putString:@"user_email" value:@"john.doe@example.com"];
 * NSLog(@"Stored string values");
 * @endcode
 */
- (void)putString:(nonnull NSString *)key
            value:(nonnull NSString *)value;

/**
 * Removes a value by key. No-op if the key does not exist.
 * @param key Key to remove.
 *
 * @discussion Example:
 * @code
 * // Remove specific keys
 * [self.userStorage remove:@"user_age"];
 * [self.userStorage remove:@"non_existent_key"]; // No-op
 * NSLog(@"Removed 'user_age' key");
 * @endcode
 */
- (void)remove:(nonnull NSString *)key;

/**
 * Removes all entries from the storage.
 *
 * @discussion Example:
 * @code
 * // Clear all data
 * [self.userStorage clear];
 * NSLog(@"Cleared all data from user storage");
 * @endcode
 */
- (void)clear;

@end
