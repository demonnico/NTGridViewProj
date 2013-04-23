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
