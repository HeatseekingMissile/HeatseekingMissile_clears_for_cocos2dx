#include "HelloWorldScene.h"
#include "ModelSprite.h"
#define WIDTH (9)
#define HEIGHT (4)
#define SPLIT (20)
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ){
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //1 create back
    auto backSprite = cocos2d::Sprite::create("back_01.jpeg");
    backSprite -> setAnchorPoint(Point(0,1));
    backSprite -> setPosition(0,visibleSize.height);
    this -> addChild(backSprite);
    
    //2 batch
    SpriteFrameCache::getInstance() -> addSpriteFramesWithFile("meizhi.plist");
    auto spriteSheet = SpriteBatchNode::create("meizhi.pvr.ccz");
    this -> addChild(spriteSheet);
    
    //3. init
    int arraySize = sizeof(ModelSprite *) * WIDTH * HEIGHT;
    auto m_matrix = (ModelSprite **)malloc(arraySize);
    memset((void *)m_matrix,0,arraySize);
    
    //4.createValue
    initMatrix();
    return true;
}

void HelloWorld::initMatrix(){
    for (int row=0;row<WIDTH;row++) {
        for (int col=0;col<HEIGHT;col++) {
            createAndDropModel(row,col);
        }
    }
};

void HelloWorld::createAndDropModel(int row,int col){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    ModelSprite *model = ModelSprite::create(row,col);
    Point endPosition = initPositionByItem(row,col);
//    Point startPosition = Point(endPosition.x,endPosition.y+visibleSize.height*2);
     Point startPosition = Point(endPosition.x,endPosition.y+visibleSize.height/2);
    
    model -> setPosition(startPosition);
    
    float speed = endPosition.y/visibleSize.height*2;
    
    this -> addChild(model);
    
    model -> runAction(MoveTo::create(speed,endPosition));
};
Point HelloWorld::initPositionByItem(int row,int col){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //固定的初始值
    int initX = (visibleSize.width - WIDTH * ModelSprite::getContentWidth() - (WIDTH-1) * SPLIT)/2;
    int initY = (visibleSize.height - HEIGHT * ModelSprite::getContentWidth() - (HEIGHT-1)*SPLIT)/2;
    
    int x = initX + (ModelSprite::getContentWidth()+SPLIT) * row + ModelSprite::getContentWidth()/2;
    int y = initY + (ModelSprite::getContentWidth()+SPLIT) * col + ModelSprite::getContentWidth()/2;
    return Point(x,y);
};

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
