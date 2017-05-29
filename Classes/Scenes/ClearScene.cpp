///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/25
//*
//*	@���O		ClearScene.cpp
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "Scenes\ClearScene.h"

// ���O���
USING_NS_CC;

//* create�֐�
ClearScene* ClearScene::create()
{
	//* �������̊m��
	ClearScene *pRet = new(std::nothrow) ClearScene();
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

bool ClearScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �Q�[���N���A���
	m_clear = Sprite::create("clear.png");
	m_clear->setPosition(490.0f, 320.0f);
	this->addChild(m_clear);

	//* onButtonClick
	//* �{�^���̐ݒu
	ui::Button* againButton = ui::Button::create("Again-button.png");
	againButton->setPosition(Vec2(300.0f, 150.0f));
	this->addChild(againButton);
	againButton->addClickEventListener(CC_CALLBACK_1(ClearScene::againButton, this));


	ui::Button* exitButton = ui::Button::create("Exit-button.png");
	exitButton->setPosition(Vec2(660.0f, 150.0f));
	this->addChild(exitButton);
	exitButton->addClickEventListener(CC_CALLBACK_1(ClearScene::exitButton, this));


	// ������������ɏI��
	return true;
}

void ClearScene::update(float delta)
{
}



// �{�^���N���b�N���R�[���o�b�N
bool ClearScene::againButton(Ref * ref)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}

bool ClearScene::exitButton(Ref * ref)
{
	// �{�^���������ꂽ��A�v�����I������
	Director::getInstance()->end();

	return true;
}