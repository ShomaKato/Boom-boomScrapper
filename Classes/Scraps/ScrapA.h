///-------------------------------------------------------------------
//*
//*	@���O		ScrapA.h
//*
//*	@�쐬��		2017/05/08
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------


// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


//////////////////////////////
///�@�v���C���N���X�̐錾�@///
//////////////////////////////
class ScrapA : public cocos2d::Layer
{
private:


public:
	// create�֐��̐錾�ƒ�`
	static ScrapA* create();

	// ������
	bool init();

	// �X�V
	void update(float delta);


	// �X�N���b�v�i�W�I�j
	cocos2d::Sprite* scrapA;
};

