///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		TitleScene.h
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "ui/CocosGUI.h"


// �^�C�g���V�[��
class TitleScene : public cocos2d::Scene
{
private:
	int m_jumpCount;

public:
	//* create�֐��̐錾�ƒ�`
	//CREATE_FUNC(PlayScene);	/* ���܂Ŏg���Ă�create�֐� */
	static TitleScene* create();

	bool init();

	void update(float delta) override;
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

	//* onButtonClick�̃C�x���g���X�i�[	
	bool TitleScene::onButtonClick(Ref *ref);
};