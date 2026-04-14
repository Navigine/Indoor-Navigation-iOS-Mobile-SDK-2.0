//
//  NCFloorSelectorView.h
//  Floor selector widget for navigation view
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NCFloorSelectorViewConfig;

/** @brief Level information model. */
@interface LevelInfo : NSObject
@property (nonatomic, strong) NSString* levelId;
@property (nonatomic, assign) int32_t sublocationId;
+ (instancetype)itemWithLevelId:(NSString *)levelId sublocationId:(int32_t)sublocationId;
@end

/** @brief Callback invoked when a floor (sublocation) is selected. */
typedef void(^NCFloorSelectorCallback)(int32_t sublocationId);

/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_default_navigation_view
 *
 * @brief Vertical floor selector for navigation view.
 * Shows available sublocations, scrolls when needed, hides for single-floor cases.
 *
 * @ref NCFloorSelectorViewConfig "NCFloorSelectorViewConfig" for styling.
 */
@interface NCFloorSelectorView : UIView <UITableViewDataSource, UITableViewDelegate>

/**
 * @brief Initializes floor selector.
 * @param origin Top-left point where selector should appear.
 * @param onSublocationSelected Callback called when user picks a floor.
 */
- (instancetype)initWithOrigin:(CGPoint)origin onSublocationSelected:(NCFloorSelectorCallback)onSublocationSelected;

/**
 * @brief Initializes floor selector with optional config.
 * @param origin Top-left point where selector should appear.
 * @param onSublocationSelected Callback called when user picks a floor.
 * @param config Optional config for styles and layout. nil = use defaults.
 */
- (instancetype)initWithOrigin:(CGPoint)origin
          onSublocationSelected:(NCFloorSelectorCallback)onSublocationSelected
                         config:(nullable NCFloorSelectorViewConfig *)config;

/** @brief Applies config at runtime. Call when config has changed. */
- (void)applyConfig:(nullable NCFloorSelectorViewConfig *)config;

/** @brief Sets list of floors to display. */
- (void)setFloors:(NSArray<LevelInfo *> *)floors;

/** @brief Highlights the active sublocation and scrolls to it when needed. */
- (void)setSublocationId:(int32_t)sublocationId;

@property (nonatomic, assign) NSInteger selectedFloorIndex;
@property (nonatomic, strong) NSArray<LevelInfo *> *floors;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UIButton *topButton;
@property (nonatomic, strong) UIButton *bottomButton;
@property (nonatomic, assign) CGPoint defaultPosition;

@end

NS_ASSUME_NONNULL_END
