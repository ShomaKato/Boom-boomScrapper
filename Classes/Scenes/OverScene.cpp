///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/25
//*
//*	@���O		OverScene.cpp
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "Scenes\TitleScene.h"
#include "Scenes\OverScene.h"

// ���O���
USING_NS_CC;


bool OverScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �����_����
	srand(static_cast<unsigned int>(time(NULL)));

	//// �w�i�摜
	//Sprite* background = Sprite::create("back.png");
	//background->setPosition(480, 320);
	//this->addChild(background);

	// ���t���[���X�V��L����
	scheduleUpdate();

	//* �C�x���g���X�i�[���쐬����
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	//* �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(OverScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(OverScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(OverScene::onTouchCancelled, this);
	//* �C�x���g���X�i�[��o�^����
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//* �n�G�P�̕\��
	fly = Sprite::create("fly2.png");
	fly->setPosition(480, 320);

	this->addChild(fly);

	//* �Ƃ肠���������^��
	MoveBy* action1 = MoveBy::create(1.0f, Vec2(0.0f, 200.0f));
	MoveBy* action2 = MoveBy::create(1.0f, Vec2(0.0f, -200.0f));
	Sequence* turn = Sequence::create(action1, action2, nullptr);
	RepeatForever* turning = RepeatForever::create(turn);

	fly->runAction(turning);

	//* onButtonClick
	//* �{�^���̐ݒu
	ui::Button* button = ui::Button::create("Play-button.png");
	button->setPosition(Vec2(480.0f, 200.0f));
	this->addChild(button);
	button->addClickEventListener(CC_CALLBACK_1(OverScene::onButtonClick, this));


	// ������������ɏI��
	return true;
}

void OverScene::update(float delta)
{
}


bool OverScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	return false;
}

void OverScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}

void OverScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}


// �{�^���N���b�N���R�[���o�b�N
bool OverScene::onButtonClick(Ref * ref)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = TitleScene::create();
	//* [13.6]�P�E�V�[���g�����W�V����
	//nextScene = TransitionOriginal::create(1.5f, nextScene);	/* [13.7]�ɔ����ăR�����g�A�E�g */
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}