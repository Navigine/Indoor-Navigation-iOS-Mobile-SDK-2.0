// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from line.djinni

#import "NCExport.h"
#import "NCSegment.h"
#import <Foundation/Foundation.h>

NAVIGINE_EXPORT
@interface NCLine : NSObject
- (nonnull instancetype)initWithSegments:(nonnull NSArray<NCSegment *> *)segments;
+ (nonnull instancetype)lineWithSegments:(nonnull NSArray<NCSegment *> *)segments;

@property (nonatomic, readonly, nonnull) NSArray<NCSegment *> * segments;

@end