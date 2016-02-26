//
//  KKStaticTableView.h
//  CommeTube
//
//  Created by Keisuke Karijuku on 2013/11/20.
//  Copyright (c) 2013年 IRIE JUNYA. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, KKStaticTableViewCellType) {
    KKStaticTableViewCellTypeDefault,
    KKStaticTableViewCellTypeSubTitle,
    KKStaticTableViewCellTypeValue1,
    KKStaticTableViewCellTypeCustom
};

@class KKStaticTableViewSectionItem, KKStaticTableViewRowItem;

@interface KKStaticTableView : UITableView

@property (strong, nonatomic, readonly) NSMutableArray * _Nonnull sections;

@property (strong, nonatomic) UIColor * _Nonnull cellTextColor;
@property (strong, nonatomic) UIFont * _Nonnull cellTextFont;
@property (strong, nonatomic) UIColor * _Nonnull cellDetailTextColor;
@property (strong, nonatomic) UIFont * _Nonnull cellDetailTextFontTypeSubTitle;
@property (strong, nonatomic) UIFont * _Nonnull cellDetailTextFontTypeValue1;

- (KKStaticTableViewSectionItem * _Nonnull)addSectionWithTitle:(NSString * _Nonnull)sectionTitle;

- (KKStaticTableViewSectionItem * _Nonnull)addSectionWithTitle:(NSString * _Nonnull)sectionTitle description:(NSString * _Nullable)description;


- (KKStaticTableViewRowItem * _Nonnull)addCellAtSection:(NSString * _Nonnull)sectionTitle
                                              cellTitle:(NSString * _Nonnull)cellTitle
                                              didSelect:(void (^ _Nullable)(KKStaticTableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath))didSelectCellAction;

- (KKStaticTableViewRowItem * _Nonnull)addCellAtSection:(NSString * _Nonnull)sectionTitle
                                         staticCellType:(KKStaticTableViewCellType)cellType
                                                   cell:(void (^ _Nullable)(UITableViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath))customCell
                                             cellHeight:(CGFloat)cellHeight
                                              didSelect:(void (^_Nullable)(KKStaticTableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath))didSelectCellAction;

- (KKStaticTableViewRowItem * _Nonnull)addCellAtSection:(NSString * _Nonnull)sectionTitle
                                        customCellClass:(id _Nonnull)customCellClass
                                                   cell:(void (^ _Nullable)(UITableViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath))customCell
                                             cellHeight:(CGFloat)cellHeight
                                              didSelect:(void (^ _Nullable)(KKStaticTableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath))didSelectCellAction;

- (void)reloadSection:(KKStaticTableViewSectionItem * _Nonnull)staticSection;
- (void)reloadSectionWithTitle:(NSString * _Nonnull)sectionTitle;
- (void)reloadCell:(KKStaticTableViewRowItem * _Nonnull)staticCell;

- (void)removeSection:(KKStaticTableViewSectionItem * _Nonnull)staticSection;
- (void)removeCell:(KKStaticTableViewRowItem * _Nonnull)staticCell;

@end


@interface KKStaticTableViewSectionItem : NSObject

@property (strong, nonatomic) NSString * _Nonnull title;
@property (strong, nonatomic) NSString * _Nonnull detail;
@property (strong, nonatomic) NSMutableArray * _Nonnull cells;

@end


@interface KKStaticTableViewRowItem : NSObject

@property (nonatomic) KKStaticTableViewCellType type;
@property (strong, nonatomic) NSString * _Nonnull title;
@property (strong, nonatomic) NSString * _Nonnull subTitle;
@property (copy, nonatomic) void (^ _Nullable customCell)(UITableViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath);
@property (nonatomic) CGFloat customCellHeight;
@property (copy, nonatomic) void (^ _Nullable didSelectCellAction)();
@property (strong, nonatomic) id _Nonnull customCellClass;

@end
