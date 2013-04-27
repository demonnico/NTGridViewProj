//
//  UIView+ResetCoord.m
//  NTGridViewProj
//
//  Created by demon on 4/27/13.
//  Copyright (c) 2013 demon. All rights reserved.
//

#import "UIView+ResetCoord.h"

@implementation UIView (ResetCoord)
-(void)resetWithX:(CGFloat)x
{
    self.frame =CGRectMake(x, self.frame.origin.y, self.frame.size.width, self.frame.size.height);
}
-(void)resetWithY:(CGFloat)y
{
    self.frame =CGRectMake(y, self.frame.origin.y, self.frame.size.width, self.frame.size.height);
}
@end
