//
//  NTGridView.m
//  NTGridViewProj
//
//  Created by demon on 4/23/13.
//  Copyright (c) 2013 demon. All rights reserved.
//

#import "NTGridView.h"

@implementation NTGridView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        // Initialization code
    }
    return self;
}

-(void)reloadData
{
/**
 *	@brief	计算出GridView中内容的大小
 */
-(void)caculateContentSize
{
    NSInteger listAmount =  [_dataSource gridViewAmountOfList:self];
    
    CGFloat sizeDynamicForHeight = 0;
    for (int listIndex=0; listIndex<listAmount; listIndex++)
    {
        //或者listIndex对应的子tableView行数/列数
        NSInteger rowAmount= [_dataSource gridView:self
                                numberOfRowsInList:listIndex];
        
        CGFloat size = 0;
        for (int rowIndex=0; rowIndex<rowAmount; rowIndex++)
        {
            CGFloat sizeForRowIndex = [_delegate gridView:self
                                               sizeForRow:rowIndex];
            size+=sizeForRowIndex;
        }
        //获得多列/多行中相对较长/宽的一个List尺寸
        if(sizeDynamicForHeight<size)
            sizeDynamicForHeight = size;
    }
    
    switch(_orientation)
    {
        case NTGridViewVertical:
            self.contentSize = CGSizeMake(self.frame.size.width,
                                          sizeDynamicForHeight);
            break;
        case NTGridViewHorizonal:
            self.contentSize = CGSizeMake(sizeDynamicForHeight,
                                          self.frame.size.height);
            break;
    }

}

- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier
                                 inList:(NSInteger)listNum
{
    return nil;
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
