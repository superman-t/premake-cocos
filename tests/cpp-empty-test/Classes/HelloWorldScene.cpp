#include "HelloWorldScene.h"
#include "AppMacros.h"
// #include "CreatorReader.h"


USING_NS_CC;


Scene* HelloWorld::scene()
{
     return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();


    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	// creator::CreatorReader* reader = creator::CreatorReader::createWithFilename( "creator/Scene/hello.ccreator" );
 //
	// // will create the needed spritesheets + design resolution
	// reader->setup();
 //
	// // get the scene graph
	// Scene* scene = reader->getSceneGraph();
 //
	// // ...and use it
	// Director::getInstance()->replaceScene( scene );

	 auto sprite = Sprite::create( "creator/Texture/HelloWorld.png" );
 
     // // position the sprite on the center of the screen
     sprite->setPosition(Vec2(visibleSize / 2) + origin);
     //
     // // add the sprite as a child to this layer
     this->addChild(sprite);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
