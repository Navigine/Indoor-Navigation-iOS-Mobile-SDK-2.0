#import "NCExport.h"
#import <Foundation/Foundation.h>
@class NCSublocation;


/**
 * Interface for a building with multiple floors (Sublocations).
 * Allows selecting the active floor directly via setActiveSublocationId.
 */
DEFAULT_EXPORT_ATTRIBUTE
@interface NCBuilding : NSObject

/**
 *
 * @discussion Example:
 * @code
 * NSArray<id<NCSublocation>> *floors = [activeBuilding getSublocations];
 * NSLog(@"Focused building, floor count: %lu", (unsigned long)floors.count);
 * @endcode
 */
- (nonnull NSArray<NCSublocation *> *)getSublocations;

/**
 *
 * @discussion Example:
 * @code
 * int32_t activeFloorId = [activeBuilding getActiveSublocationId];
 * NSLog(@"Active sublocation id: %d", activeFloorId);
 * @endcode
 */
- (int32_t)getActiveSublocationId;

/**
 *
 * @discussion Example:
 * @code
 * [activeBuilding setActiveSublocationId:activeFloorId];
 * @endcode
 */
- (void)setActiveSublocationId:(int32_t)activeSublocationId;

/**
 * Tells if this object is valid or not. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
