///-------------------------------------------------------------------
//*
//*	@���O		BaseScrap.h
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
class BaseScrap : public cocos2d::Layer
{
private:
	// �X�N���b�v���쎞�́A�㕔���̒�~�ꏊ
	float m_workSpotA = 340.0f;

	// �X�N���b�v���쎞�́A�������̒�~�ꏊ
	float m_workSpotB = 320.0f;

	// �����ʒu�֖߂鎞�́A�㕔���̒�~�ꏊ
	float m_initSpotA = 630.0f;;

	// �����ʒu�֖߂鎞�́A�������̒�~�ꏊ
	float m_initSpotB = 10.0f;;

	// �X�N���b�v���쎞�̑��x
	float m_workSpeed;

	// �����ʒu�֖߂鎞�̑��x
	float m_initSpeed;

	// �v���C���̌��݈ʒu
	cocos2d::Vec2 m_playerPos;

	// �A�N�V���������ۂ��i�A�N�V�������Ȃ�A�ǂꂭ�炢�����Ă��邩�̐��l������j
	int isActed;


public:
	// create�֐��̐錾�ƒ�`
	static BaseScrap* create();

	// ������
	bool init();

	// �X�V
	void update(float delta);

	//////////////////////////////
	/// �R�[���o�b�N�֐��̐錾 ///
	//////////////////////////////
	// �^�b�`�C�x���g���X�i�[
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);


	//////////////////////////////
	/// �X�v���C�g�E�m�[�h�o�^ ///
	//////////////////////////////
	// �v���C���i�㑤�j
	cocos2d::Sprite* scrapperA;
	// �v���C���i�����j
	cocos2d::Sprite* scrapperB;
	
	// �v���C���i�����m�[�h�j
	cocos2d::Node* scrappers;

};

