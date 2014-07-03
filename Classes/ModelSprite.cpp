//
//  ModelSprite.cpp
//  clear_03
//
//  Created by 田浩 on 14-7-3.
//
//

#include "ModelSprite.h"
#define MODEL_TOTAL (6)
static const char *m_images[MODEL_TOTAL]={
    "111.jpg",
    "222.jpg",
    "333.jpg",
    "444.jpg",
    "555.jpg",
    "666.jpg"
};

ModelSprite *ModelSprite::create(int row,int col){
    ModelSprite *model = new ModelSprite();
    model -> m_row = row;
    model -> m_col = col;
    model -> m_imgIndex = arc4random() % MODEL_TOTAL;
    model -> initWithSpriteFrameName(m_images[model -> m_imgIndex]);
    model -> autorelease();
    return model;
};

float ModelSprite::getContentWidth(){
    static float item = 0;
    if (0 == item) {
        Sprite *sprite = createWithSpriteFrameName(m_images[0]);
        item = sprite -> getContentSize().height;
    };
    return item;
};