///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		PlayScene.h
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
#include "Player\Player.h"


class PlayScene : public cocos2d::Scene
{
private:
	// �v���C��
	Player* m_player;
	
public:
	// create�֐��̐錾�ƒ�`
	static PlayScene* create();

	////* �^�b�`����̂��߂ɕK�v�Ȋ֐��̐錾
	//bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// ������
	bool init();
	// �X�V
	void update(float delta) override;

};

