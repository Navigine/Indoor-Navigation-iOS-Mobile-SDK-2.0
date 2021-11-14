#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NCLocationView;
@class NCMapObjectPickResult;

/**
 A map view delegate can receive various map events.

 @note All of these methods are called from main thread, these methods are all **optional**.
 */
@protocol NCLocationViewDelegate <NSObject>
@optional

/**
 Receive the result from `-[NCLocationView pickMapObjectAt:]`.

 @param locationView The location view instance.
 @param pickResult A result object with information about the picked object or `nil` if no object was found.
 @param position The view position where object was picked.
 */
- (void)locationView:(nonnull NCLocationView *)mapView
didSelectMapObject:(nullable NCMapObjectPickResult *)markerPickResult
atScreenPosition:(CGPoint)position;

@end // protocol NCLocationViewDelegate
