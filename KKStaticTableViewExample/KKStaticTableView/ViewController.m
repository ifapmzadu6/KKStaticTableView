//
//  ViewController.m
//  KKStaticTableView
//
//  Created by Keisuke Karijuku on 2014/09/03.
//  Copyright (c) 2014年 Keisuke Karijuku. All rights reserved.
//

#import "ViewController.h"

#import "KKStaticTableView.h"

@interface ViewController ()
@property (nonatomic) KKStaticTableView *tableView;
@end

@implementation ViewController
            
- (void)viewDidLoad {
    [super viewDidLoad];
    
    _tableView = [[KKStaticTableView alloc]initWithFrame:self.view.bounds];
    _tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _tableView.contentInset = UIEdgeInsetsMake(20, 0, 0, 0); //status bar height
    
    NSString *section1 = @"fluit";
    NSString *section2 = @"vegetable";
    
    [_tableView addSectionWithTitle:section1];
    [_tableView addCellAtSection:section1
                  staticCellType:KKStaticTableViewCellTypeDefault
                            cell:^(UITableViewCell *cell, NSIndexPath *indexPath) {
                                cell.textLabel.text = @"Apple";
                            }
                      cellHeight:44.0
                       didSelect:^(KKStaticTableView *tableView, NSIndexPath *indexPath) {
                           NSLog(@"Apple selected!");
                       }];
    [_tableView addCellAtSection:section1
                  staticCellType:KKStaticTableViewCellTypeDefault
                            cell:^(UITableViewCell *cell, NSIndexPath *indexPath) {
                                cell.textLabel.text = @"Orange";
                            }
                      cellHeight:44.0
                       didSelect:^(KKStaticTableView *tableView, NSIndexPath *indexPath) {
                           NSLog(@"Orange selected!");
                       }];
    
    [_tableView addSectionWithTitle:section2];
    [_tableView addCellAtSection:section2
                  staticCellType:KKStaticTableViewCellTypeValue1
                            cell:^(UITableViewCell *cell, NSIndexPath *indexPath) {
                                cell.textLabel.text = @"Piment";
                                cell.detailTextLabel.text = @"delisious";
                            }
                      cellHeight:44.0
                       didSelect:^(KKStaticTableView *tableView, NSIndexPath *indexPath) {
                           
                       }];
    [_tableView addCellAtSection:section2
                  staticCellType:KKStaticTableViewCellTypeValue1
                            cell:^(UITableViewCell *cell, NSIndexPath *indexPath) {
                                cell.textLabel.text = @"celery";
                                cell.detailTextLabel.text = @"so-so";
                            }
                      cellHeight:44.0
                       didSelect:^(KKStaticTableView *tableView, NSIndexPath *indexPath) {
                           
                       }];
    
    [self.view addSubview:_tableView];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
