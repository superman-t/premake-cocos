#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "UIButton.h"
#include "UIScrollView.h"
#include "CreatorReader.h"
#include "UIScale9Sprite.h"
#include "CCFontAtlasCache.h"
#include "ui/UILoadingBar.h"
#include "ui/UIButton.h"
#include "ui/UIRichText.h"
#include "ui/UICheckBox.h"
#include "ui/UIRadioButton.h"
#include "ui/UIPageView.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "UITextField.h"

USING_NS_CC;
using namespace ui;

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

	scheduleUpdate();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto widgetSize = Director::getInstance()->getWinSize();


    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	 creator::CreatorReader* reader = creator::CreatorReader::createWithFilename( "creator/Scene/hello.ccreator" );
 
	 // will create the needed spritesheets + design resolution
	 reader->setup();
 
	 // get the scene graph
	 Scene* scene = reader->getSceneGraph();
 
	 // ...and use it
	 Director::getInstance()->replaceScene( scene );

	//  auto sprite = Sprite::create( "creator/Texture/HelloWorld.png" );
 //  //
	//  // auto actionBy = cocos2d::RotateBy::create( 2, 360 );
	//  // auto actionByBack = cocos2d::RepeatForever::create( actionBy );
	//  // sprite->runAction( actionByBack );
 //  //
 //  //    // // position the sprite on the center of the screen
 //  //    sprite->setPosition(Vec2(0, 0));
	//  // sprite->setScale( 1, 0.3 );
 //  //
	//  // auto listener = cocos2d::EventListenerTouchOneByOne::create();
	//  // listener->onTouchBegan = []( cocos2d::Touch* touch, cocos2d::Event* event )
	//  // {
	// 	//  auto location = touch->getLocation();
 //  //
	// 	//  CCLOG( "%f, %f, %d", location.x, location.y, event->getType() );
	// 	//  return false;
	//  // };
	//  // cocos2d::EventDispatcher* eventDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	//  // eventDispatcher->addEventListenerWithFixedPriority( listener, 1 );
 //  //
	//  // cocos2d::ui::Button* button = cocos2d::ui::Button::create( "creator/Texture/HelloWorld.png", "creator/Texture/HelloWorld.png"  );
	//  // button->setContentSize( Size(256, 128) );
	//  // button->setPosition( cocos2d::Vec2( 300, 200 ) );
	//  // button->setPressedActionEnabled( true );
 //  //
	//  // // this->addChild( button );
 //  //
	//  cocos2d::ui::ScrollView* scrollView = cocos2d::ui::ScrollView::create();
	//  scrollView->setBounceEnabled( true );
	//  scrollView->setContentSize( cocos2d::Size( 256, 256 ) );
	//  scrollView->setInnerContainerSize( cocos2d::Size( 256, 256 ) );
	//  scrollView->setPosition( cocos2d::Vec2( 256, 128 ) );
	//  scrollView->setScrollBarWidth( 4 );
	//  scrollView->setScrollBarEnabled( true );
	//  scrollView->setScrollBarPositionFromCorner( cocos2d::Vec2( 2, 2 ) );
	// scrollView->setScrollBarColor( cocos2d::Color3B::YELLOW );
	// scrollView->setGlobalZOrder( 200 );
 //  
	//   // //
	//   auto innerWidth = 256;
	//   // auto innerHeight = 512;
	//   // button->setPosition( cocos2d::Vec2( 0, 0) );
	//   scrollView->addChild( sprite );
 //  
	//  // CCLOG( "================%f", button->getContentSize().height );
 //
 //
	// auto sprite2 = Sprite::create( "creator/Texture/HelloWorld.png" );
	// // sprite2->setContentSize( Size( 256, 100 ) );
	// // sprite2->setColor( Color3B::BLUE );
	// // sprite2->setOpacity( 0.5 );
	// sprite2->setPosition( Vec2( 500, 500 ) );
	// this->addChild( sprite2 );
 //
 //     //
 //     // // add the sprite as a child to this layer
 //     // this->addChild(sprite);
	//  this->addChild( scrollView );
	// auto polygon = cocos2d::DrawNode::create();
	// cocos2d::Vec2 rect[4];
	// rect[0].set( 0, 0 );
	// rect[1].set( 0, 50 );
	// rect[3].set( 50, 0.0f);
	// rect[2].set( 50, 50);
 //
	// cocos2d::Color4F green( 0.0f, 1.0f, 0.0f, 1.0f );
	// polygon->drawPolygon( rect, 4, green, 0, green );
	// addChild( polygon );
 //
	// auto winSize = Director::getInstance()->getWinSize();
	// float x = winSize.width / 2;
	// float y = 0 + (winSize.height / 2 - 20);
 //
	// auto label = Label::createWithBMFont( "fonts/bitmapFontTest4.fnt", "Click Button to toggle rendering type");
	// label->setPosition( Vec2( winSize.width / 2, winSize.height - 60 ) );
	// label->setColor( Color3B::BLACK );
	// this->addChild( label );
	// _time1 = 0;
	// schedule( [=]( float dt )
	// {
	// 	_time1 += dt;
 //
	// 	char str[10] = { 0 };
	// 	sprintf( str, "%2.1f", _time1 );
	// 	label->setString( str );
	// }, "step_1" );
 //
	// auto blocks = ui::Scale9Sprite::create( "Images/blocks9.png" );
 //
	// blocks->setPosition( Vec2( x, y ) );
	// blocks->setPreferredSize( Size( 96 * 2, 96 ) );
	// this->addChild( blocks );
 //
	// auto addSliceSpriteButton = ui::Button::create( "cocosui/animationbuttonnormal.png", "cocosui/animationbuttonpressed.png" );
	// addSliceSpriteButton->setPosition( Vec2( winSize.width / 2, winSize.height - 100 ) );
	// addSliceSpriteButton->setTitleText( "Slice Rendering" );
	// addSliceSpriteButton->addClickEventListener( [=]( Ref* )
	// {
	// 	if( blocks->getRenderingType() == ui::Scale9Sprite::RenderingType::SLICE )
	// 	{
	// 		blocks->setRenderingType( ui::Scale9Sprite::RenderingType::SIMPLE );
	// 		addSliceSpriteButton->setTitleText( "Simple Rendering" );
	// 	}
	// 	else
	// 	{
	// 		blocks->setRenderingType( ui::Scale9Sprite::RenderingType::SLICE );
	// 		addSliceSpriteButton->setTitleText( "Slice Rendering" );
	// 		blocks->setCapInsets( Rect( 96 / 3, 96 / 3, 96 / 3, 96 / 3 ) );
	// 	}
	// } );
	// this->addChild( addSliceSpriteButton );
 // //
	// auto labelA = Label::createWithTTF( "create label with system fontfdsafds fdsafdsafdsafd fdsa fdsa fdsa fdsa fdsa fds fdsafds afdsafdsafdsafdsaf fds fdsa fdsa fdsa fda fdsa fdsa fdsa fdsa ", "fonts/arial.ttf", 24 );
	// auto size = labelA->getContentSize();
	// labelA->setDimensions( size.width, size.height );
	// labelA->setColor( Color3B::BLACK );
	// labelA->setPosition( 300,  50 );
	// addChild( labelA );

#define LongSentencesExample "acetian"


	// auto label = cocos2d::Label::createWithBMFont( "fonts/futura-48.fnt", "abcdefghijklmnopqrstuvwxyz" );
	// label->setPosition( cocos2d::Vec2( 300, 300 ) );
	// // label->setAlignment( cocos2d::TextHAlignment::CENTER );
	// // label->setDimensions( 300, 300 );
	// // label->setColor( cocos2d::Color3B::RED );
	// addChild( label );


	// auto labelFreeType = cocos2d::Label::createWithTTF( u8"中国", "fonts/DFYuanW7-GB2312.ttf", 32.0f );
	// labelFreeType->setColor( Color3B::RED );
	// labelFreeType->setPosition( 400, 400 );
	// labelFreeType->enableUnderline();
	// addChild( labelFreeType );
 //
	// TTFConfig ttfConfig( "fonts/HKYuanMini.ttf", 25, GlyphCollection::DYNAMIC );
	// auto label1 = Label::createWithTTF( ttfConfig,
	// 									"你好，Cocos2d-x v3的New Label.", TextHAlignment::LEFT, 200 * 0.75 );
	// if( label1 )
	// {
	// 	label1->setTextColor( Color4B( 128, 255, 255, 255 ) );
	// 	label1->setPosition( Vec2( 200, 200 ) );
	// 	label1->setAnchorPoint( Vec2( 0, 0.5 ) );
	// 	this->addChild( label1 );
	// 	// Demo for unloadFontAtlasTTF function, after it been called, all UI widget
	// 	//  use the special font must reset font, because the old one is invalid.
	// 	FontAtlasCache::unloadFontAtlasTTF( "fonts/HKYuanMini.ttf" );
	// 	label1->setTTFConfig( ttfConfig );
	// }

	// auto label = Label::createWithSystemFont( "你好", "Helvetica", 20.0 );
	// label->setPosition( 600, 600);
	// label->setAnchorPoint( Vec2::ZERO );
	// label->setTag( 123 );
	// this->addChild( label );

	// auto label2 = Label::createWithBMFont( "fonts/bitmapFontTest4.fnt", "Test" );
	// label2->setColor( Color3B::RED );
	// label2->setPosition( 200, 100 );
	// addChild( label2 );

	// auto batch = SpriteBatchNode::create( "creator/Texture/HelloWorld.png", 1 );
	// addChild( batch);
 //
	// auto sprite1 = Sprite::createWithTexture( batch->getTexture());
	// auto sprite2 = Sprite::createWithTexture( batch->getTexture());
 //
 //
	// auto s = Director::getInstance()->getWinSize();
	// sprite1->setPosition( Point( (s.width / 5) * 1, (s.height / 3) * 1 ) );
	// sprite2->setPosition( Point( (s.width / 5) * 2, (s.height / 3) * 1 ) );
 //
	// batch->addChild( sprite1);
	// batch->addChild( sprite2 );

	// auto blocks = ui::Scale9Sprite::createWithSpriteFrameName( "blocks9.png" );
	// blocks->setInsetLeft( 0 );
	// blocks->setInsetRight( 0 );
	// blocks->setInsetTop( 0 );
	// blocks->setInsetBottom( 0 );
	// blocks->setPreferredSize( Size( 400, 80 ) );
	// blocks->setPosition( 480, 320 );
 //
	// this->addChild( blocks );

	// SpriteFrameCache::getInstance()->addSpriteFramesWithFile( "Images/sprite_frames_test/test_RGBA8888.plist" );
	// cocos2d::SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName( "grossini.png" );
	// // cocos2d::Texture2D *texture = spriteFrame->getTexture();
	// auto sprite = cocos2d::Sprite::createWithSpriteFrame( spriteFrame );
	// sprite->setPosition( visibleSize.width / 2, visibleSize.height / 2 );
	// this->addChild( sprite );
 //



	// // Create the button
	// auto button = cocos2d::ui::Button::create( "cocosui/animationbuttonnormal.png",
	// 							  "cocosui/animationbuttonpressed.png" );
	// button->setTitleFontName( "fonts/arial.ttf" );
	// button->setPositionNormalized( Vec2( 0.3f, 0.5f ) );
	// button->setTitleText( "PLAY GAME" );
	// // button->setZoomScale( 0.3f );
	// button->setScale( 2.0f );
	// // button->setFlippedX( true );
	// button->setPressedActionEnabled( true );
 //
	// this->addChild( button );
	// auto sprite = Sprite::create( "Images/sprite_frames_test/test_RGBA8888.png" );
	// this->addChild( sprite );


	// // Create the loading bar
	// ui::LoadingBar* loadingBar = LoadingBar::create( "cocosui/sliderProgress.png" );
	// loadingBar->setTag( 0 );
	// loadingBar->setPosition( Vec2( widgetSize.width / 2.0f,
	// 						 widgetSize.height / 2.0f + loadingBar->getContentSize().height / 4.0f ) );
 //
	// auto loadingBarCopy = (LoadingBar*)loadingBar->clone();
	// loadingBarCopy->setTag( 1 );
	// loadingBarCopy->setPosition( loadingBar->getPosition()
	// 							 + Vec2( 0, -40 ) );
	// loadingBarCopy->setDirection( LoadingBar::Direction::RIGHT );
 //
	// Button* button = Button::create( "cocosui/animationbuttonnormal.png",
	// 								 "cocosui/animationbuttonpressed.png" );
	// button->setPosition( Vec2( widgetSize.width / 2.0f, widgetSize.height / 2.0f + 50 ) );
	// button->setTitleText( "Click to change direction!" );
 //
	// button->addTouchEventListener( [=]( Ref*, Widget::TouchEventType type )
	// {
	// 	if( type == Widget::TouchEventType::ENDED )
	// 	{
	// 		if( loadingBar->getDirection() == LoadingBar::Direction::LEFT )
	// 		{
	// 			loadingBar->setDirection( LoadingBar::Direction::RIGHT );
	// 			loadingBarCopy->setDirection( LoadingBar::Direction::LEFT );
	// 		}
	// 		else
	// 		{
	// 			loadingBar->setDirection( LoadingBar::Direction::LEFT );
	// 			loadingBarCopy->setDirection( LoadingBar::Direction::RIGHT );
	// 		}
	// 	}
	// } );
	// this->addChild( loadingBar, 1 );
	// this->addChild( loadingBarCopy, 2 );
	// this->addChild( button );
 //
	// auto _richText = RichText::createWithXML( "Default color.<font color='#ff0000'>red.<font color='#00ff00'>green</font>red again.</font>default again" );
	// _richText->ignoreContentAdaptWithSize( false );
	// _richText->setContentSize( Size( 200, 100 ) );
 //
	// _richText->setPosition( Vec2( widgetSize.width / 2 -200, widgetSize.height / 2 ) );
	// _richText->setLocalZOrder( 10 );
 //
 //
	// this->addChild( _richText );
 //
 //
	// // Create the checkbox
	// auto _checkBox = CheckBox::create( "cocosui/check_box_normal.png",
	// 							  "cocosui/check_box_normal_press.png",
	// 							  "cocosui/check_box_active.png",
	// 							  "cocosui/check_box_normal_disable.png",
	// 							  "cocosui/check_box_active_disable.png" );
	// _checkBox->setPosition( Vec2( widgetSize.width / 2.0f, widgetSize.height / 2.0f ) );
 //
	// _checkBox->addEventListener( CC_CALLBACK_2( HelloWorld::selectedEvent, this ) );
	// this->addChild( _checkBox );
 //
	// static const float BUTTON_WIDTH = 50;
	// static float startPosX = 0;
 //
	// auto _radioButtonGroup = RadioButtonGroup::create();
	// this->addChild( _radioButtonGroup );
	// _radioButtonGroup->addEventListener( CC_CALLBACK_3( HelloWorld::onChangedRadioButtonGroupSelect, this ) );
 //
	// // Create the radio buttons
	// static const int NUMBER_OF_BUTTONS = 2;
	// startPosX = widgetSize.width / 2.0f - ((NUMBER_OF_BUTTONS - 1) / 2.0f) * BUTTON_WIDTH;
	// for( int i = 0; i < NUMBER_OF_BUTTONS; ++i )
	// {
	// 	RadioButton* radioButton = RadioButton::create( "cocosui/radio_button_off.png", "cocosui/radio_button_on.png" );
	// 	float posX = startPosX + BUTTON_WIDTH * i;
	// 	radioButton->setPosition( Vec2( posX, 200 ) );
	// 	radioButton->setScale( 1.2f );
	// 	radioButton->addEventListener( CC_CALLBACK_2( HelloWorld::onChangedRadioButtonSelect, this ) );
	// 	_radioButtonGroup->addRadioButton( radioButton );
	// 	this->addChild( radioButton );
	// }
 //
	// // Create the page view
	// Size size( 240, 130 );
	// PageView* pageView = PageView::create();
	// pageView->setDirection( PageView::Direction::HORIZONTAL );
	// pageView->setContentSize( size );
 //
 //
	// pageView->setPosition( (widgetSize - pageView->getContentSize()) / 2.0f );
	// pageView->removeAllItems();
	// pageView->setBounceEnabled( true );
	// pageView->setIndicatorEnabled( true );
	// pageView->setGlobalZOrder( 200 );
 //
	// int pageCount = 4;
	// for( int i = 0; i < pageCount; ++i )
	// {
	// 	Layout* layout = Layout::create();
	// 	layout->setContentSize( size );
 //
	// 	auto imageView = Scale9Sprite::create( "cocosui/scrollviewbg.png" );
	// 	imageView->setScale9Enabled( true );
	// 	imageView->setContentSize( size );
	// 	imageView->setPosition( Vec2( layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f ) );
	// 	layout->addChild( imageView );
 //
	// 	auto label = Label::create( StringUtils::format( "page %d", (i + 1) ), "fonts/Marker Felt.ttf", 30 );
	// 	label->setColor( Color3B( 192, 192, 192 ) );
	// 	label->setPosition( Vec2( layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f ) );
	// 	layout->addChild( label );
 //
	// 	pageView->insertCustomItem( layout, i );
	// }
 //
	// // pageView->removeItem( 0 );
	// pageView->scrollToItem( pageCount - 2 );
	// //This method is deprecated, we used here only testing purpose
	// pageView->addEventListenerPageView( this, pagevieweventselector( HelloWorld::pageViewEvent ) );
 //
	// pageView->setIndicatorIndexNodesOpacity( 255 );
 //
	// this->addChild( pageView );
 //
 //
 //
	// // Create the layout
	// Layout* layout = Layout::create();
	// layout->setContentSize( Size( 280, 150 ) );
	// layout->setPosition( Vec2(100, 100) );
	// this->addChild( layout );
 //
	// Button* button2 = Button::create( "cocosui/animationbuttonnormal.png", "cocosui/animationbuttonpressed.png" );
	// button2->setPosition( Vec2( button2->getContentSize().width / 2.0f,
	// 					 layout->getContentSize().height - button2->getContentSize().height / 2.0f ) );
	// layout->addChild( button2 );
 //
	// Button* titleButton = Button::create( "cocosui/backtotopnormal.png", "cocosui/backtotoppressed.png" );
	// titleButton->setTitleText( "Title Button" );
	// titleButton->setPosition( Vec2( layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f ) );
	// layout->addChild( titleButton );
 //
	// Button* button_scale9 = Button::create( "cocosui/button.png", "cocosui/buttonHighlighted.png" );
	// button_scale9->setScale9Enabled( true );
	// button_scale9->setContentSize( Size( 100.0f, button_scale9->getVirtualRendererSize().height ) );
	// button_scale9->setPosition( Vec2( layout->getContentSize().width - button_scale9->getContentSize().width / 2.0f,
	// 							button_scale9->getContentSize().height / 2.0f ) );
 //
	// layout->addChild( button_scale9 );

/*
	_totalCount = 50;
	_spawnCount = 5;
	_bufferZone = 45;
	// Create the list view ex
	_listView = ListView::create();
	// set list view ex direction
	_listView->setDirection( ui::ScrollView::Direction::VERTICAL );
	_listView->setBounceEnabled( true );
	_listView->setBackGroundImage( "cocosui/green_edit.png" );
	_listView->setGlobalZOrder( 200 );
	_listView->setBackGroundImageScale9Enabled( true );
	_listView->setContentSize( Size( 200, 130 ) );
	_listView->setPosition( Vec2( (widgetSize - _listView->getContentSize()) / 2.0f ) );
	_listView->addEventListener( (ui::ListView::ccListViewCallback)CC_CALLBACK_2( HelloWorld::selectedItemEvent, this ) );
	_listView->addEventListener( (ui::ListView::ccScrollViewCallback)CC_CALLBACK_2( HelloWorld::selectedItemEventScrollView, this ) );
	_listView->setScrollBarPositionFromCorner( Vec2( 7, 7 ) );
	this->addChild( _listView );


	// create model
	Button* default_button = Button::create( "cocosui/backtotoppressed.png", "cocosui/backtotopnormal.png" );
	default_button->setName( "Title Button" );

	Layout* default_item = Layout::create();
	default_item->setTouchEnabled( true );
	default_item->setContentSize( default_button->getContentSize() );
	default_button->setPosition( Vec2( default_item->getContentSize() / 2.0f ) );
	default_item->addChild( default_button );

	// auto clippingNode = ClippingNode::create();
	// auto sprite = Sprite::create( "cocosui/clippingHead.jpg" );
	// clippingNode->addChild( sprite );
	// auto stencil = Sprite::create( "cocosui/clippingStencil.jpg" );
	// clippingNode->setStencil( stencil );
	// auto custom_item_contentSize = default_item->getContentSize();
	// clippingNode->setPosition( sprite->getContentSize().width / 2,
	// 						   custom_item_contentSize.height / 2 );
	// clippingNode->setScale( 0.5 );
	// default_item->addChild( clippingNode );

	
	// set model
	_listView->setItemModel( default_item );

	// set all items layout gravity
	_listView->setGravity( ListView::Gravity::CENTER_VERTICAL );

	//initial the data
	for( int i = 0; i < _totalCount; ++i )
	{
		if( i < _spawnCount )
		{
			Widget* item = default_item->clone();
			item->setTag( i );
			Button* btn = (Button*)item->getChildByName( "Title Button" );
			btn->setTitleText( StringUtils::format( "listview_item_%d", i ) );
			_listView->pushBackCustomItem( item );
		}
	}

	// set items margin
	float spacing = 4;
	_listView->setItemsMargin( spacing );
	_itemTemplateHeight = default_item->getContentSize().height;
	_reuseItemOffset = (_itemTemplateHeight + spacing) * _spawnCount;

	//update listview data
	this->scheduleUpdate();

	_listView->forceDoLayout();
	float totalHeight = _itemTemplateHeight * _totalCount + (_totalCount - 1) * spacing;
	_listView->setInnerContainerSize( Size( _listView->getInnerContainerSize().width, totalHeight ) );
	_listView->jumpToTop();


	// Show the indexes of items on each boundary.
	{
		float position = 75;
		// Labels
		_indexLabels[0] = Label::createWithTTF( " ", "fonts/Marker Felt.ttf", 12 );
		_indexLabels[0]->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
		_indexLabels[0]->setPosition( Size( 0, position ) );
		this->addChild( _indexLabels[0] );

		_indexLabels[1] = Label::createWithTTF( "  ", "fonts/Marker Felt.ttf", 12 );
		_indexLabels[1]->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
		_indexLabels[1]->setPosition( Size( 140, 0 ) );
		this->addChild( _indexLabels[1] );

		_indexLabels[2] = Label::createWithTTF( " ", "fonts/Marker Felt.ttf", 12 );
		_indexLabels[2]->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
		_indexLabels[2]->setPosition( Size( 0, -position ) );
		this->addChild( _indexLabels[2] );

		// Callback
		_listView->ScrollView::addEventListener( [this]( Ref* ref, ScrollView::EventType eventType )
		{
			ListView* listView = dynamic_cast<ListView*>(ref);
			if( listView == nullptr || eventType != ScrollView::EventType::CONTAINER_MOVED )
			{
				return;
			}
			auto bottom = listView->getBottommostItemInCurrentView();
			auto center = listView->getCenterItemInCurrentView();
			auto top = listView->getTopmostItemInCurrentView();

			// reused item index
			_indexLabels[0]->setString( StringUtils::format( "Top index=%zd", listView->getIndex( top ) ) );
			_indexLabels[1]->setString( StringUtils::format( "Center\nindex=%zd", listView->getIndex( center ) ) );
			_indexLabels[2]->setString( StringUtils::format( "Bottom index=%zd", listView->getIndex( bottom ) ) );
		} );
	}



	// Create the layout
	Layout* layout = Layout::create();
	layout->setLayoutType( Layout::Type::RELATIVE );
	layout->setContentSize( Size( 280, 150 ) );
	layout->setBackGroundColorType( Layout::BackGroundColorType::SOLID );
	layout->setBackGroundColor( Color3B::GREEN );
	Size backgroundSize = Size(300, 300);
	layout->setPosition( cocos2d::Vec2(100, 100));
	this->addChild( layout );

	// top left
	Button* button_TopLeft = Button::create( "cocosui/animationbuttonnormal.png",
											 "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_TopLeft );

	RelativeLayoutParameter* rp_TopLeft = RelativeLayoutParameter::create();
	rp_TopLeft->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT );
	button_TopLeft->setLayoutParameter( rp_TopLeft );


	// top center horizontal
	Button* button_TopCenter = Button::create( "cocosui/animationbuttonnormal.png",
											   "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_TopCenter );

	RelativeLayoutParameter* rp_TopCenter = RelativeLayoutParameter::create();
	rp_TopCenter->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_TOP_CENTER_HORIZONTAL );
	button_TopCenter->setLayoutParameter( rp_TopCenter );


	// top right
	Button* button_TopRight = Button::create( "cocosui/animationbuttonnormal.png",
											  "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_TopRight );

	RelativeLayoutParameter* rp_TopRight = RelativeLayoutParameter::create();
	rp_TopRight->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_TOP_RIGHT );
	button_TopRight->setLayoutParameter( rp_TopRight );


	// left center
	Button* button_LeftCenter = Button::create( "cocosui/animationbuttonnormal.png",
												"cocosui/animationbuttonpressed.png" );
	layout->addChild( button_LeftCenter );

	RelativeLayoutParameter* rp_LeftCenter = RelativeLayoutParameter::create();
	rp_LeftCenter->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL );
	button_LeftCenter->setLayoutParameter( rp_LeftCenter );


	// center
	Button* buttonCenter = Button::create( "cocosui/animationbuttonnormal.png",
										   "cocosui/animationbuttonpressed.png" );
	layout->addChild( buttonCenter );

	RelativeLayoutParameter* rpCenter = RelativeLayoutParameter::create();
	rpCenter->setAlign( RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT );
	buttonCenter->setLayoutParameter( rpCenter );


	// right center
	Button* button_RightCenter = Button::create( "cocosui/animationbuttonnormal.png",
												 "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_RightCenter );

	RelativeLayoutParameter* rp_RightCenter = RelativeLayoutParameter::create();
	rp_RightCenter->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL );
	button_RightCenter->setLayoutParameter( rp_RightCenter );


	// left bottom
	Button* button_LeftBottom = Button::create( "cocosui/animationbuttonnormal.png",
												"cocosui/animationbuttonpressed.png" );
	layout->addChild( button_LeftBottom );

	RelativeLayoutParameter* rp_LeftBottom = RelativeLayoutParameter::create();
	rp_LeftBottom->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_BOTTOM );
	button_LeftBottom->setLayoutParameter( rp_LeftBottom );


	// bottom center
	Button* button_BottomCenter = Button::create( "cocosui/animationbuttonnormal.png",
												  "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_BottomCenter );

	RelativeLayoutParameter* rp_BottomCenter = RelativeLayoutParameter::create();
	rp_BottomCenter->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_BOTTOM_CENTER_HORIZONTAL );
	button_BottomCenter->setLayoutParameter( rp_BottomCenter );


	// right bottom
	Button* button_RightBottom = Button::create( "cocosui/animationbuttonnormal.png",
												 "cocosui/animationbuttonpressed.png" );
	layout->addChild( button_RightBottom );

	RelativeLayoutParameter* rp_RightBottom = RelativeLayoutParameter::create();
	rp_RightBottom->setAlign( RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_BOTTOM );
	button_RightBottom->setLayoutParameter( rp_RightBottom );

	*/
	// auto layer1 = LayerGradient::create( Color4B( 255, 0, 0, 255 ), Color4B( 0, 255, 0, 255 ), Vec2( 0.9f, 0.9f ) );
	// addChild( layer1 );

 //
	// _editEmail = ui::EditBox::create( Size(300, 50), "Images/texture512x512.png" );
	// _editEmail->setPlaceHolder( "Email:" );
	// _editEmail->setInputMode( ui::EditBox::InputMode::EMAIL_ADDRESS );
	// _editEmail->setInputMode( ui::EditBox::InputMode::ANY );
	// _editEmail->setFontColor( Color3B::BLACK );
	// // _editEmail->setDelegate( this );
	// _editEmail->setVisible( true );
	// this->addChild( _editEmail );
	// //It is required to use setFontSize and setContentSize after adding it to the hierarchy, so that native EditBox get the right size
	// _editEmail->setFontSize( 30 );
	// _editEmail->setContentSize( Size( 300, 50 ) );
	// _editEmail->setPosition( Vec2( 480, 320 ) );


	// // Create the textfield
	// TextField* textField = TextField::create( );
	// textField->setContentSize( Size( 256, 32 ) );
	// textField->setPlaceHolder( "abc" );
	// textField->setFontName( "fonts/DFYuanW7-GB2312.ttf" );
	// textField->setFontSize( 32 );
	// // textField->setPlaceHolderColor( Color3B::BLUE );
	// textField->setCursorEnabled( true );
	// // textField->setTextColor( Color4B::BLACK );
	// textField->setPosition( Vec2( widgetSize.width / 2.0f, widgetSize.height / 2.0f ) );
	// textField->addEventListener( CC_CALLBACK_2( HelloWorld::textFieldEvent, this ) );
	// this->addChild( textField );

	// TextField* textField = TextField::create( "place holder", "fonts/DFYuanW7-GB2312.ttf", 20 );
	// textField->setPosition( cocos2d::Vec2( 200, 200 ) );
	// textField->setCursorEnabled( true );
	// textField->addEventListener( CC_CALLBACK_2( HelloWorld::textFieldEvent, this ) );
	// this->addChild( textField );

	/*auto sprite = cocos2d::Sprite::create( "Images/CyanSquare.png" );
	sprite->setColor( cocos2d::Color3B::GREEN );
	auto size = cocos2d::Director::getInstance()->getWinSize();
	sprite->setScale( size.width / sprite->getContentSize().width, size.height / sprite->getContentSize().height );
	sprite->setPosition( size.width / 2, size.height / 2 );

	this->addChild( sprite );

	auto sprite2 = cocos2d::Sprite::create( "Images/btn-about-normal.png" );

	sprite->addChild( sprite2);*/

    return true;
}

void HelloWorld::textFieldEvent( Ref *pSender, TextField::EventType type )
{
	switch( type )
	{
		case TextField::EventType::ATTACH_WITH_IME:
		{
			// TextField* textField = dynamic_cast<TextField*>(pSender);
			// Size screenSize = Director::getInstance()->getWinSize();
			// textField->runAction( MoveTo::create( 0.225f,
			// 					  Vec2( screenSize.width / 2.0f, screenSize.height / 2.0f + textField->getContentSize().height / 2.0f ) ) );
		}
		break;

		case TextField::EventType::DETACH_WITH_IME:
		{
			// TextField* textField = dynamic_cast<TextField*>(pSender);
			// Size screenSize = Director::getInstance()->getWinSize();
			// textField->runAction( MoveTo::create( 0.175f, Vec2( screenSize.width / 2.0f, screenSize.height / 2.0f ) ) );

		}
		break;

		case TextField::EventType::INSERT_TEXT:
			// _displayValueLabel->setString( StringUtils::format( "insert words" ) );
			break;

		case TextField::EventType::DELETE_BACKWARD:
			// _displayValueLabel->setString( StringUtils::format( "delete word" ) );
			break;

		default:
			break;
	}
}


float HelloWorld::getItemPositionYInView( cocos2d::ui::Widget *item ) const
{
	auto worldPos = item->getParent()->convertToWorldSpaceAR( item->getPosition() );
	auto viewPos = this->_listView->convertToNodeSpaceAR( worldPos );
	return viewPos.y;
}

void HelloWorld::updateItem( int itemID, int templateID )
{
	auto itemTemplate = _listView->getItems().at( templateID );
	Button* btn = (Button*)itemTemplate->getChildByName( "Title Button" );
	//If you have  the item ID and templateID, you could fill in the data here
	itemTemplate->setTag( itemID );
	btn->setTitleText( StringUtils::format( "listview_item_%d", itemID ) );
}

void HelloWorld::update( float dt)
{
	// _count++;
	// if( _count > 100 )
	// {
	// 	_count = 0;
	// }
	// LoadingBar* loadingBar = static_cast<LoadingBar*>(this->getChildByTag( 0 ));
	// LoadingBar* loadingBarCopy = static_cast<LoadingBar*>(this->getChildByTag( 1 ));
	// loadingBar->setPercent( _count );
	// loadingBarCopy->setPercent( _count );

	/*
	this->_updateTimer += dt;
	if( this->_updateTimer < this->_updateInterval )
	{
		return;
	}

	float totalHeight = _itemTemplateHeight * _totalCount + (_totalCount - 1) * 4;

	auto listViewHeight = _listView->getContentSize().height;

	this->_updateTimer = 0;
	auto isDown = this->_listView->getInnerContainerPosition().y < this->_lastContentPosY;
	auto items = _listView->getItems();

	for( int i = 0; i < _spawnCount && i < _totalCount; ++i )
	{
		auto item = items.at( i );
		auto itemPos = this->getItemPositionYInView( item );
		if( isDown )
		{
			if( itemPos < -_bufferZone && item->getPosition().y + _reuseItemOffset < totalHeight )
			{
				int itemID = item->getTag() - (int)items.size();
				item->setPositionY( item->getPositionY() + _reuseItemOffset );
				CCLOG( "itemPos = %f, itemID = %d, templateID = %d", itemPos, itemID, i );
				this->updateItem( itemID, i );
			}
		}
		else
		{
			if( itemPos > _bufferZone + listViewHeight &&
				item->getPosition().y - _reuseItemOffset >= 0 )
			{

				item->setPositionY( item->getPositionY() - _reuseItemOffset );
				int itemID = item->getTag() + (int)items.size();
				CCLOG( "itemPos = %f, itemID = %d, templateID = %d", itemPos, itemID, i );
				this->updateItem( itemID, i );
			}
		}
	}
	//update ListView Items
	this->_lastContentPosY = this->_listView->getInnerContainer()->getPosition().y;
	*/
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::selectedEvent( Ref* pSender, CheckBox::EventType type )
{
	switch( type )
	{
		case CheckBox::EventType::SELECTED:
			CCLOG( "Selected"  );
			break;

		case CheckBox::EventType::UNSELECTED:
			CCLOG( "Unselected"  );
			break;

		default:
			break;
	}

}

void HelloWorld::onChangedRadioButtonSelect( RadioButton* radioButton, RadioButton::EventType type )
{
	if( radioButton == nullptr )
	{
		return;
	}

	switch( type )
	{
		case RadioButton::EventType::SELECTED:
		{
			CCLOG( "---》%s", "Selected");
			break;
		}

		case RadioButton::EventType::UNSELECTED:
		{
			CCLOG("---》%s", "Unselected");
			break;
		}
		default:
			break;
	}
}

void HelloWorld::onChangedRadioButtonGroupSelect( RadioButton* radioButton, int index, RadioButtonGroup::EventType type )
{
	if( radioButton == nullptr )
	{
		return;
	}
	switch( type )
	{
		case RadioButtonGroup::EventType::SELECT_CHANGED:
		{
			CCLOG( "%s %d", "Selected", index );
			break;
		}
	}
}

void HelloWorld::pageViewEvent( Ref *pSender, PageViewEventType type )
{
	switch( type )
	{
		case PAGEVIEW_EVENT_TURNING:
		{
			PageView* pageView = dynamic_cast<PageView*>(pSender);

			CCLOG("page = %ld", static_cast<long>(pageView->getCurrentPageIndex() + 1)) ;
		}
		break;

		default:
			break;
	}
}


void HelloWorld::selectedItemEvent( Ref *pSender, ListView::EventType type )
{
	switch( type )
	{
		case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START:
		{
			ListView* listView = static_cast<ListView*>(pSender);
			auto item = listView->getItem( listView->getCurSelectedIndex() );
			log( "select child start index = %d", item->getTag() );
			break;
		}
		case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
		{
			ListView* listView = static_cast<ListView*>(pSender);
			auto item = listView->getItem( listView->getCurSelectedIndex() );
			log( "select child end index = %d", item->getTag() );
			break;
		}
		default:
			break;
	}
}

void HelloWorld::selectedItemEventScrollView( Ref* pSender, ui::ScrollView::EventType type )
{
	switch( type )
	{
		case ui::ScrollView::EventType::SCROLL_TO_BOTTOM:
			CCLOG( "SCROLL_TO_BOTTOM" );
			break;
		case ui::ScrollView::EventType::SCROLL_TO_TOP:
			CCLOG( "SCROLL_TO_TOP" );
			break;
		default:
			break;
	}
}


// void HelloWorld::editBoxEditingDidBegin( cocos2d::ui::EditBox* editBox )
// {
// 	log( "editBox %p DidBegin !", editBox );
// }
//
// void HelloWorld::editBoxEditingDidEnd( cocos2d::ui::EditBox* editBox )
// {
// 	log( "editBox %p DidEnd !", editBox );
// }
//
// void HelloWorld::editBoxEditingDidEndWithAction( cocos2d::ui::EditBox* editBox, cocos2d::ui::EditBoxDelegate::EditBoxEndAction action )
// {
// 	log( "editBox %p DidEnd with action %d!", editBox, action );
// }
//
// void HelloWorld::editBoxTextChanged( cocos2d::ui::EditBox* editBox, const std::string& text )
// {
// 	log( "editBox %p TextChanged, text: %s ", editBox, text.c_str() );
// 	editBox->setText( text.c_str() );
// }
//
// void HelloWorld::editBoxReturn( ui::EditBox* editBox )
// {
// 	log( "editBox %p was returned !", editBox );
//
// 	if( _editEmail == editBox )
// 	{
// 		log("%s", "Email EditBox return !" );
// 	}
// }