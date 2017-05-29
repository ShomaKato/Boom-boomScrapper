///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		ClearScene.h
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Scenes\PlayScene.h"


class ClearScene : public cocos2d::Scene
{

public:
	// create�֐��̐錾�ƒ�`
	static ClearScene* create();



	// ������
	bool init();
	// �X�V
	void update(float delta) override;


	//* onButtonClick�̃C�x���g���X�i�[	
	// �^�C�g���{�^��
	bool ClearScene::againButton(Ref *ref);
	// �I���{�^��
	bool ClearScene::exitButton(Ref *ref);

	// �^�C�g�����
	cocos2d::Sprite* m_clear;
};

