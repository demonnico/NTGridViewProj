//
//  NTGridView.h
//  NTGridViewProj
//
//  Created by demon on 4/23/13.
//  Copyright (c) 2013 demon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NTGridCellView.h"

@class  NTGridView;

@protocol NTGridViewDelegate <NSObject>

- (CGFloat)gridView:(NTGridView *)gridView
         sizeForRow:(NSInteger)rowNum
             inList:(NSInteger)listNum;

@end

@protocol NTGridViewDataSource <NSObject>

@required
- (NSInteger)gridView:(NTGridView*)gridView
   numberOfRowsInList:(NSInteger)listNum;

- (NTGridCellView*)gridView:(UITableView *)tableView
                 cellForRow:(NSInteger)rowNum
                    forList:(NSInteger)listNum;
@end

@interface NTGridView : UIScrollView

-(void)reloadData;
- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier
                                 inList:(NSInteger)listNum;
@end
