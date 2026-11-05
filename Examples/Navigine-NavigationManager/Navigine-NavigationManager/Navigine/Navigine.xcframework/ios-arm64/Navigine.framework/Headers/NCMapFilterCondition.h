#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * A single filter condition: property must match one of the given values.
 *
 * @discussion Example:
 * @code
 * // Create filter condition: show only venues with category "Toilet" or "Cafe"
 * NCMapFilterCondition *condition = [[NCMapFilterCondition alloc] initWithProperty:@"category" values:@[@"Toilet", @"Cafe"]];
 * @endcode
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapFilterCondition : NSObject

/** 
 * Default constructor for class NCMapFilterCondition 
 */
- (nonnull instancetype)initWithProperty:(nonnull NSString *)property
                                  values:(nonnull NSArray<NSString *> *)values;

/** 
 * Factory method for class NCMapFilterCondition 
 */
+ (nonnull instancetype)mapFilterConditionWithProperty:(nonnull NSString *)property
                                                values:(nonnull NSArray<NSString *> *)values;

/**
 * The feature property to match (e.g. "category", "kind").
 */
@property (nonatomic, readonly, nonnull) NSString * property;

/**
 * List of allowed values. Feature is visible if its property matches any of these.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> * values;

@end
