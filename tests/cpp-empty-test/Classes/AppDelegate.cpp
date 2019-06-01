#include "AppDelegate.h"

#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"

#include "platform/CCFileUtils.h"

#include "CreatorReader.h"


USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Cocos Creator Test");
        director->setOpenGLView(glview);
    }

    director->setOpenGLView(glview);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);

	Size frameSize = glview->getFrameSize();
    
    vector<string> searchPath;

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.

 //    // if the frame's height is larger than the height of medium resource size, select large resource.
	// if (frameSize.height > mediumResource.size.height)
	// {
 //        searchPath.push_back(largeResource.directory);
 //
 //        director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	// }
 //    // if the frame's height is larger than the height of small resource size, select medium resource.
 //    else if (frameSize.height > smallResource.size.height)
 //    {
 //        searchPath.push_back(mediumResource.directory);
 //        
 //        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
 //    }
 //    // if the frame's height is smaller than the height of medium resource size, select small resource.
	// else
 //    {
 //        searchPath.push_back(smallResource.directory);
 //
 //        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
 //    }

	searchPath.push_back( "Resources" );
    
    // set searching path
    FileUtils::getInstance()->setSearchPaths(searchPath);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
     director->setAnimationInterval(1.0f / 60);
  
	   creator::CreatorReader* reader = creator::CreatorReader::createWithFilename( "creator/Scene/hello.ccreator" );
  
	   // will create the needed spritesheets + design resolution
	   reader->setup();
  
	   // get the scene graph
	   Scene* scene = reader->getSceneGraph();
	   reader->retain();
  
	  // ...and use it
    //
	   // auto canvas = scene->getChildByName( "Canvas" );
    //
	   // cocos2d::ui::Button* button = (cocos2d::ui::Button*)canvas->getChildByName( "New Button" );
    //
	   // button->addClickEventListener( [=]( cocos2d::Ref* pSenders )
	   // {
		  //  cocos2d::Sprite* sprite = (cocos2d::Sprite*) canvas->getChildByName( "Sprite1" );
		  //  reader->getAnimationManager()->playAnimationClip( sprite, "anim" );
    //
	   // } );
	  Director::getInstance()->replaceScene( scene );

	  // // create a scene. it's an autorelease object
	  // auto scene = HelloWorld::scene();
	  //
	  // // run
	  // director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

}
