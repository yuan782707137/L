#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    actionSp = Sprite::create("res/grass.png");
    actionSp->setPosition(Vec2(200,200));
    actionSp->setAnchorPoint(Vec2(0, 0));
    actionSp->setScale(.5);
    actionSp->setVisible(true);
    addChild(actionSp,2);
    
    auto sprite = Sprite::create("res/HelloWorld.png");
    sprite->setPosition(Vec2(480, 320));
    sprite->setAnchorPoint(Vec2::ONE);
    addChild(sprite);
    
    //进度条
//    auto gress = ProgressTimer::create(Sprite::create("res/grass.png"));
//    gress->setType(ProgressTimer::Type::BAR);
//    gress->setMidpoint(Vec2(0, 0.5));
//    gress->setBarChangeRate(Vec2(1,0));
//    gress->setPercentage(0);
//    gress->setPosition(240,160);
//    addChild(gress,1,1);
    
    auto menu = Menu::create();
    menu->setPosition(Vec2(50, 50));
    addChild(menu);
    
    auto item = MenuItemImage::create("CloseNormal.png", "CloseSelected.png");
    item->setCallback(CC_CALLBACK_1(HelloWorld::menuCloseCallback,this ));
    item->setPosition(Vec2(50,50));
    menu->addChild(item);
    
    
        return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("res/Zombie_default.plist","res/Zombie_default.png");
    
    Vector<AnimationFrame *>vec;
    for (int i = 1; i<30; i++) {
        std::string frameName = StringUtils::format("Zombie%d.png",i);
        auto frames = cache->getSpriteFrameByName(frameName);
        auto anFrame = AnimationFrame::create(frames, 0.5f, ValueMap());
        vec.pushBack(anFrame);
    }
    
    auto animation = Animation::create(vec,0.2f);
    auto animate = Animate::create(animation);
    actionSp->runAction(RepeatForever::create(animate));
    
    
        //auto show = Show::create();
    //actionSp->runAction(show);
    
    //auto mto = MoveTo::create(2.0f, Vec2(100, 100));
    //actionSp->runAction(mto);
    
    //层跟随
    //auto follow = Follow::create(actionSp);
    //this->runAction(follow);
    
    //actionSp->runAction(MoveBy::create(.3f, Vec2(30, 30)));

    //auto rt = RotateBy::create(2.0f, 960);
    //auto e3 = EaseElasticIn::create(mto, 1.0f);
    //auto delaytime = DelayTime::create(3);
    
    //auto seq = Sequence::create(mto,delaytime,rt, NULL);
    //actionSp->runAction(seq);
    
   // auto callf = CallFunc::create(CC_CALLBACK_0(HelloWorld::callfunc, this));
    //auto seq = Sequence::create(mto,rt,callf, NULL);
    //actionSp->runAction(seq);
    
    //进度条
//    auto gressrun = (ProgressTimer*)getChildByTag(1);
////    auto pt = ProgressTo::create(4.0f,100);
////    gressrun->runAction(pt);
//    auto run = ProgressFromTo::create(1.0f, 0, 100);
//    gressrun->runAction(run);
    
    //点击隐藏
    //auto hide = Hide::create();
//    auto toggle = ToggleVisibility::create();
//    actionSp->runAction(toggle);
    
}

void HelloWorld::callfunc()
{
    actionSp->setPosition(Vec2(240, 160));
}
