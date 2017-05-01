///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		OverScene.h
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "ui/CocosGUI.h"


class OverScene : public cocos2d::Scene
{
	int m_Cnt;
public:
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(OverScene);


	//* �^�b�`����̂��߂ɕK�v�Ȋ֐��̐錾
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// ������
	bool init();
	// �X�V
	void update(float delta) override;

	//* onButtonClick�̃C�x���g���X�i�[	
	bool OverScene::onButtonClick(Ref *ref);

	// �X�v���C�g�̍쐬
	cocos2d::Sprite* fly;
};

