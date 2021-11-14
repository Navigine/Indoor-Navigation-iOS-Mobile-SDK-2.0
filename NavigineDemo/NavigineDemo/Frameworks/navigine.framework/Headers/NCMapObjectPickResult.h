#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import "NCExport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Data structure holding the result of a marker selection that occured on the location view.

 See `-[NCLocationView pickMapObjectAt:]` and `[NCLocationViewDelegate locationView:didSelectMapObject:atScreenPosition:]`.
 */
NAVIGINE_EXPORT
@interface NCMapObjectPickResult : NSObject

/// The geographic coordinates of the selected label
@property (readonly, nonatomic) CLLocationCoordinate2D coordinates;

/// The selected marker
@property (readonly, nonatomic) NSObject* mapObject;

NS_ASSUME_NONNULL_END

@end
