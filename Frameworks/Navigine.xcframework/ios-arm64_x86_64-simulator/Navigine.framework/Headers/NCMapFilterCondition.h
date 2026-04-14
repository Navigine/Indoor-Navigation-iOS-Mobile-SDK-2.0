#import "NCExport.h"
#import <Foundation/Foundation.h>

/**
 * @file NCMapFilterCondition.h
 * @brief @copybrief NCMapFilterCondition
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_location_view
 *
 * @brief A single filter condition: property must match one of the given values.
 *
 *
 *
 *Swift code snippet:
 *@snippet LocationWindowCommonExample.swift swift_MapFilterCondition_constructor
 *
 *Objective C code snippet:
 *@snippet LocationWindowCommonExample.m objc_MapFilterCondition_constructor
 *
 *
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCMapFilterCondition : NSObject

/** 
 * @brief Default constructor for class NCMapFilterCondition 
 */
- (nonnull instancetype)initWithProperty:(nonnull NSString *)property
                                  values:(nonnull NSArray<NSString *> *)values;

/** 
 * @brief Factory method for class NCMapFilterCondition 
 */
+ (nonnull instancetype)mapFilterConditionWithProperty:(nonnull NSString *)property
                                                values:(nonnull NSArray<NSString *> *)values;

/**
 * @brief The feature property to match (e.g. "category", "kind").
 */
@property (nonatomic, readonly, nonnull) NSString * property;

/**
 * @brief List of allowed values. Feature is visible if its property matches any of these.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> * values;

@end
