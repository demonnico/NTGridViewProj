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


/**
 *	@brief	获得gridView中子tableView的宽度/高度
 *
 *	@param 	gridView
 *	@param 	listIndex 	子tableView的index
 *
 *	@return	listIndex对应子TableView的宽度/高度
 */
- (CGFloat)gridView:(NTGridView *)gridView
         sizeForRow:(NSInteger)rowNum
             inList:(NSInteger)listNum;

/**
 *	@brief	获得gridView中子tableView的cell高度/宽度
 *
 *	@param 	gridView
 *	@param 	listIndex 	子tableview中cell的index
 *
 *	@return	rowIndex对应子tableView中cell的高度/宽度
 */
-(CGFloat)gridView:(NTGridView *)gridView
       sizeForRow:(NSInteger)rowIndex;



@end

@protocol NTGridViewDataSource <NSObject>

@required
/**
 *	@brief	从DataSource中得到对应List的table条数
 *
 *	@param 	gridView
 *	@param 	listIndex 	list(行/列)
 *
 *	@return	对应listInde的tableView条数
 */
- (NSInteger)gridView:(NTGridView*)gridView
   numberOfRowsInList:(NSInteger)listIndex;


/**
 *	@brief	获得子TableView的个数
 *
 *	@param 	gridView
 *
 *	@return	gridView中子TableView的个数
 */
- (NSInteger)gridViewAmountOfList:(NTGridView*)gridView;



/**
 *	@brief	获得子tableView中的cell对象
 *
 *	@param 	tableView
 *	@param 	rowIndex 	cell的row/col
 *	@param 	listIndex 	list(子tableView)的列/行
 *
 *	@return	子视图
 */
- (NTGridCellView*)gridView:(UITableView *)tableView
                 cellForRow:(NSInteger)rowIndex
                    forList:(NSInteger)listIndex;

@end

typedef enum
{
    NTGridViewVertical,
    NTGridViewHorizonal
}NTGridViewOrientation;

@interface NTGridView : UIScrollView

@property (nonatomic,assign) NTGridViewOrientation      orientation;
@property (nonatomic,assign) id<NTGridViewDataSource>   dataSource;
@property (nonatomic,assign) id<NTGridViewDelegate>     delegate;

-(id)initWithFrame:(CGRect)frame
 scrollOrientation:(NTGridViewOrientation)orientation;
-(void)reloadData;
- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier
                             cellForRow:(NSInteger)row
                                 inList:(NSInteger)listNum;
@end
