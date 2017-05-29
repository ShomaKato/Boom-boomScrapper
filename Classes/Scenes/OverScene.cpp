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
#include "Scenes\OverScene.h"

// ���O���
USING_NS_CC;

//* create�֐�
OverScene* OverScene::create()
{
	//* �������̊m��
	OverScene *pRet = new(std::nothrow) OverScene();
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

bool OverScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �C�x���g���X�i�[���쐬����
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// �C�x���g���X�i�[��o�^����
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �Q�[���I�[�o�[���
	m_over = Sprite::create("over.png");
	m_over->setPosition(490.0f, 320.0f);
	this->addChild(m_over);

	//* onButtonClick
	//* �{�^���̐ݒu
	ui::Button* againButton = ui::Button::create("Again-button.png");
	againButton->setPosition(Vec2(300.0f, 250.0f));
	this->addChild(againButton);
	againButton->addClickEventListener(CC_CALLBACK_1(OverScene::againButton, this));


	ui::Button* exitButton = ui::Button::create("Exit-button.png");
	exitButton->setPosition(Vec2(660.0f, 250.0f));
	this->addChild(exitButton);
	exitButton->addClickEventListener(CC_CALLBACK_1(OverScene::exitButton, this));


	// ������������ɏI��
	return true;
}

void OverScene::update(float delta)
{
}



// �{�^���N���b�N���R�[���o�b�N
bool OverScene::againButton(Ref * ref)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}

bool OverScene::exitButton(Ref * ref)
{
	// �{�^���������ꂽ��A�v�����I������
	Director::getInstance()->end();

	return true;
}