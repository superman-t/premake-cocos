#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "UICheckBox.h"
#include "UIRadioButton.h"
#include "UIPageView.h"
#include "CCLabel.h"
#include "UIEditBox/UIEditBox.h"
#include "UITextField.h"

class HelloWorld : public cocos2d::Scene
// , public cocos2d::ui::EditBoxDelegate
{
public:
    virtual bool init() override;

    static cocos2d::Scene* scene();

    // a selector callback
    void menuCloseCallback(Ref* sender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update( float dt );

	void selectedEvent( Ref* pSender, cocos2d::ui::CheckBox::EventType type );

	void onChangedRadioButtonSelect( cocos2d::ui::RadioButton* radioButton, cocos2d::ui::RadioButton::EventType type );
	void onChangedRadioButtonGroupSelect( cocos2d::ui::RadioButton* radioButton, int index, cocos2d::ui::RadioButtonGroup::EventType type );

	void pageViewEvent( Ref *pSender, cocos2d::ui::PageViewEventType type );

	void selectedItemEvent( Ref *pSender, cocos2d::ui::ListView::EventType type );

	void selectedItemEventScrollView( Ref* pSender, cocos2d::ui::ScrollView::EventType type );

	float getItemPositionYInView( cocos2d::ui::Widget* item ) const;
	void updateItem( int itemID, int templateID );

	void textFieldEvent( Ref *pSender, cocos2d::ui::TextField::EventType type );

 //
	// virtual void editBoxEditingDidBegin( cocos2d::ui::EditBox* editBox )override;
	// virtual void editBoxEditingDidEnd( cocos2d::ui::EditBox* editBox )override;
	// virtual void editBoxEditingDidEndWithAction( cocos2d::ui::EditBox* editBox, cocos2d::ui::EditBoxDelegate::EditBoxEndAction action )override;
	// virtual void editBoxTextChanged( cocos2d::ui::EditBox* editBox, const std::string& text )override;
	// virtual void editBoxReturn( cocos2d::ui::EditBox* editBox )override;

	float _time1;
	int _count;

	cocos2d::Label* _indexLabels[3];
	//how many items we actually spawn, these items will be reused.
	int _spawnCount;
	// how many items we need for the ListView. Usually this is a big number.
	int _totalCount;
	//when item is away from bufferSzone, we relocate it.
	float _bufferZone;
	float _itemTemplateHeight;
	float _updateInterval;
	float _updateTimer;
	float _lastContentPosY;
	float _reuseItemOffset;
	cocos2d::ui::ListView* _listView;
	cocos2d::ui::EditBox* _editEmail;
};

#endif // __HELLOWORLD_SCENE_H__
