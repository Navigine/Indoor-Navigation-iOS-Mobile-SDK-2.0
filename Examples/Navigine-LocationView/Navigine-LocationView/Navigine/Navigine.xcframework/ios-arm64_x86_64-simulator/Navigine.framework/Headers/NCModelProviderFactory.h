#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NCModelProvider.h"

/// :nodoc:
@interface NCModelProviderFactory : NSObject

+ (id<NCModelProvider>)fromFile:(NSString*)path texture:(UIImage*)texture;
+ (id<NCModelProvider>)fromData:(NSData*)data texture:(UIImage*)texture;

@end
