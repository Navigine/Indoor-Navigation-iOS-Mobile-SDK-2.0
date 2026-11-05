#import <Foundation/Foundation.h>

/**
 * Operating mode of the location view.
 * Controls whether the view shows indoor floors only, an outdoor vector basemap,
 * or outdoor basemap with indoor building overlays.
 */
typedef NS_ENUM(NSInteger, NCOperatingMode)
{
    /**
     *
     * @discussion Example:
     * @code
     * NSArray<NSNumber *> *modes = @[@(NCOperatingModeIndoorOnly), @(NCOperatingModeOutdoor), @(NCOperatingModeOutdoorIndoor)];
     * NSLog(@"Operating modes: %lu", (unsigned long)modes.count);
     * @endcode
     * Indoor floors only (no outdoor vector basemap).
     * Camera stick-to-border / centering apply to the active floor plan.
     */
    NCOperatingModeIndoorOnly,
    /**
     * Outdoor vector basemap only (OSM MVT).
     */
    NCOperatingModeOutdoor,
    /**
     * Outdoor vector basemap plus indoor building floor overlays.
     */
    NCOperatingModeOutdoorIndoor,
};
