#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// :nodoc:
@protocol NCModelProvider

- (NSString*)modelId;
- (NSData*)model;
- (UIImage*)texture;

@end
