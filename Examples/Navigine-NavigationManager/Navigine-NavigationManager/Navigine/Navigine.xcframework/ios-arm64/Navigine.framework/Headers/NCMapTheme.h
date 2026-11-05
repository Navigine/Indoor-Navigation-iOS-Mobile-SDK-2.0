#import <Foundation/Foundation.h>

/**
 * Color theme of the outdoor vector basemap.
 * Indoor floor rasters, venue icons, and user map objects are unchanged.
 */
typedef NS_ENUM(NSInteger, NCMapTheme)
{
    /**
     *
     * @discussion Example:
     * @code
     * NSArray<NSNumber *> *themes = @[@(NCMapThemeLight), @(NCMapThemeDark)];
     * NSLog(@"Map themes: %lu", (unsigned long)themes.count);
     * @endcode
     * Light outdoor basemap (default).
     */
    NCMapThemeLight,
    /**
     * Dark outdoor basemap (versatiles-shadow palette).
     */
    NCMapThemeDark,
};
