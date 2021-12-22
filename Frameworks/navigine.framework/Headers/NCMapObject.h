#import "NCExport.h"
#import "NCMapObjectType.h"
#import <Foundation/Foundation.h>


NAVIGINE_EXPORT
@interface NCMapObject : NSObject

- (BOOL)setVisible:(BOOL)visible;

- (BOOL)setColor:(float)red
           green:(float)green
            blue:(float)blue
           alpha:(float)alpha;

- (BOOL)setInteractive:(BOOL)interactive;

- (void)setData:(nonnull NSData *)data;

@property (nonatomic, readonly) int32_t id;

@property (nonatomic, readonly) NCMapObjectType type;

@property (nonatomic, nonnull, readonly) NSData * data;

@end
