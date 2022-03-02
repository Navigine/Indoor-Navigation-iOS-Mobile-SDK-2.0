#import "NCExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class NCMapObjectPickResult;


NAVIGINE_EXPORT
@protocol NCPickListener <NSObject>

- (void)onMapObjectPickComplete:(nullable NCMapObjectPickResult *)mapObjectPickResult
                 screenPosition:(CGPoint)screenPosition;

- (void)onMapFeaturePickComplete:(nonnull NSDictionary<NSString *, NSString *> *)mapFeaturePickResult
                  screenPosition:(CGPoint)screenPosition;

@end
