//
//  ModelSprite.h
//  clear_03
//
//  Created by 田浩 on 14-7-3.
//
//

#ifndef __clear_03__ModelSprite__
#define __clear_03__ModelSprite__

#include <iostream>
#include "cocos2d.h"
#endif /* defined(__clear_03__ModelSprite__) */

class ModelSprite : public cocos2d::Sprite{
public:
    static ModelSprite *create(int row,int col);
    static float getContentWidth();
    
    CC_SYNTHESIZE(int,m_row,Row);
    CC_SYNTHESIZE(int,m_col,Col);
    CC_SYNTHESIZE(int,m_imgIndex,ImgIndex);
};