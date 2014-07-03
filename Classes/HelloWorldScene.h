#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "ModelSprite.h"
class ModelSprite;

class HelloWorld : public cocos2d::Layer
{
public:
    HelloWorld();
    ~HelloWorld();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    
    //create Matrix
    void initMatrix();
    
    //
    void createAndDropModel(int row,int col);
    
    cocos2d::Point initPositionByItem(int row,int col);
    

    void update(float f);
    
    CREATE_FUNC(HelloWorld);
private:
    cocos2d::SpriteBatchNode *spriteSheet;
    ModelSprite **m_matrix;// 2D array which store (SushiSprite *).
    int m_width;
    int m_height;
    // for rapid count position
    float initX;
    float initY;
    bool isAction;
};

#endif // __HELLOWORLD_SCENE_H__
