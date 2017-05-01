///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/3/15
//*
//*	@���O		TitleScene.cpp
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "Scenes\TitleScene.h"
#include "Scenes\PlayScene.h"
#include "Scenes\TransitionOriginal.h"

USING_NS_CC;

//* create�֐�
TitleScene* TitleScene::create()
{
	//* �������̊m��
	TitleScene *pRet = new(std::nothrow) TitleScene();
	//* ���������m�ۂł��A����ɏ������ł����Ȃ�
	if (pRet && pRet->init())
	{
		//* �����J���}�l�[�W���ɓo�^
		pRet->autorelease();
		//* �����������I�u�W�F�N�g��Ԃ�
		return pRet;
	}
	else
	{
		//* �������ŃG���[���N�����̂ŁA���������J�����Ĉُ�I��
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

// ������
bool TitleScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// ���t���[���X�V��L����
	scheduleUpdate();

	//* onButtonClick
	//* �{�^���̐ݒu
	ui::Button* button = ui::Button::create("Play-button.png");
	button->setPosition(Vec2(480.0f, 200.0f));
	this->addChild(button);
	button->addClickEventListener(CC_CALLBACK_1(TitleScene::onButtonClick, this));

	// ������������I��
	return true;
}

// ���t���[���X�V
void TitleScene::update(float delta)
{

}

// �^�b�`�J�n���R�[���o�b�N
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	//// ���̃V�[�����쐬����
	//Scene* nextScene = PlayScene::create();
	//// ���̃V�[���Ɉڍs
	//_director->replaceScene(nextScene);

	return true;
}

// �{�^���N���b�N���R�[���o�b�N
bool TitleScene::onButtonClick(Ref * ref)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}
